#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <windows.h>

// 路由表项结构体
struct RouteEntry {
    std::string destination;  // 目的地址
    std::string mask;         // 掩码
    std::string nextHop;      // 下一跳地址
};

// 处理命令行字符串,返回第一个单词
std::string getCommand(const std::string &commandLine) {
    size_t pos = commandLine.find(' ');
    if (pos == std::string::npos) {
        return commandLine;
    }
    return commandLine.substr(0, pos);
}

// 字符串分割函数
std::vector<std::string> split(const std::string &str, char delimiter) {
    std::vector<std::string> result;
    std::string::size_type start = 0;
    auto pos = str.find_first_of(delimiter, start);
    while (pos != std::string::npos) {
        if (pos != start) {
            result.emplace_back(str, start, pos - start);
        }
        start = pos + 1;
        pos = str.find_first_of(delimiter, start);
    }
    if (start < str.length()) {
        result.emplace_back(str, start, str.length() - start);
    }
    return result;
}

// 检测地址格式是否正确
bool checkAddress(const std::string &address) {
    // 计算"."的个数，如果不为3，则格式错误
    int dotCount = 0;
    for (const auto &c: address) {
        if (c == '.') {
            ++dotCount;
        }
    }
    if (dotCount != 3) {
        return false;
    }
    // 检测每个"."之间的数字是否合法
    std::vector<std::string> addressParts = split(address, '.');
    if (addressParts.size() != 4) {
        return false;
    }
    for (const auto &part: addressParts) {
        if (part.empty()) {
            return false;
        }
        for (const auto &c: part) {
            if (!isdigit(c)) {
                return false;
            }
        }
        int num = std::stoi(part);
        if (num < 0 || num > 255) {
            return false;
        }
    }
    return true;
}

// 路由表管理模块
class RoutingTableManager {
public:
    std::vector<RouteEntry> routingTable;  // 路由表

public:
    // 加载初始路由表
    void loadRoutingTable(const std::vector<RouteEntry> &initialRoutingTable) {
        routingTable = initialRoutingTable;
    }

    // 添加路由表项
    void addRouteEntry(const RouteEntry &routeEntry) {
        routingTable.push_back(routeEntry);
    }

    // 删除路由表项
    void deleteRouteEntry(const std::string &destination, const std::string &mask) {
        for (auto it = routingTable.begin(); it != routingTable.end(); ++it) {
            if (it->destination == destination && it->mask == mask) {
                routingTable.erase(it);
                break;
            }
        }
    }

    // 修改路由表项
    void modifyRouteEntry(const RouteEntry &routeEntry) {
        const std::string &destination = routeEntry.destination;
        const std::string &mask = routeEntry.mask;
        const std::string &nextHop = routeEntry.nextHop;
        for (auto &entry: routingTable) {
            if (entry.destination == destination && entry.mask == mask) {
                entry.nextHop = nextHop;
                break;
            }
        }
    }

    // 查找目的地址对应的下一跳地址
    std::string lookupNextHop(const std::string &destinationAddress) {
        for (const auto &entry: routingTable) {
            if (matchDestination(entry.destination, entry.mask, destinationAddress)) {
                return entry.nextHop;
            }
        }
        return "";  // 没有找到匹配的路由表项，返回空字符串
    }

private:
    static bool
    matchDestination(const std::string &entryDest, const std::string &entryMask, const std::string &destAddress) {
        // 将目的地址和路由表项的目的地址进行按位与操作，与路由表项的掩码进行按位与操作
        // 如果结果与路由表项的目的地址相等，则匹配成功
        for (size_t i = 0; i < entryDest.length(); ++i) {
            // 将字符转换为二进制数进行按位与操作
            std::bitset<8> entryDestBits(entryDest[i]);
            std::bitset<8> entryMaskBits(entryMask[i]);
            std::bitset<8> destAddressBits(destAddress[i]);

            // 按位与操作后进行比较
            std::bitset<8> result = entryDestBits & entryMaskBits;
            if (result != (destAddressBits & entryMaskBits)) {
                return false;
            }
        }
        return true;
    }
};

// 数据包转发模块
class PacketForwarder {
public:
    // 模拟数据包的转发过程
    static void
    forwardPacket(const std::string &sourceAddress, const std::string &destinationAddress, const std::string &nextHop) {
        if (!nextHop.empty()) {
            std::cout << "Forwarding packet from " << sourceAddress << " to " << destinationAddress
                      << " via next hop " << nextHop << std::endl;
        } else {
            std::cout << "No matching route found for destination " << destinationAddress << std::endl;
        }
    }
};

// 输出结果显示模块
class ResultDisplay {
public:
    // 显示路由表
    static void displayRoutingTable(const std::vector<RouteEntry> &routingTable) {
        std::cout << "Routing table:" << std::endl;
        std::cout << "Destination\tMask\t\tNext hop" << std::endl;
        for (const auto &entry: routingTable) {
            std::cout << entry.destination << "\t" << entry.mask << "\t" << entry.nextHop << std::endl;
        }
    }

    // 显示转发结果
    static void displayResult(const std::string &nextHop) {
        std::cout << "Next hop: " << nextHop << std::endl;
    }

    // 显示字符绘制"Router"
    static void displayRouter() {
        std::cout << "    ____                   __                 \n"
                     "   / __ \\  ____   __  __  / /_  ___    _____ \n"
                     "  / /_/ / / __ \\ / / / / / __/ / _ \\  / ___/\n"
                     " / _, _/ / /_/ // /_/ / / /_  /  __/ / /      \n"
                     "/_/ |_|  \\____/ \\__,_/  \\__/  \\___/ /_/   \n"
                     "                                              \n"
                     "Enter -help to view all commands              \n" << std::endl;
    }

    // 显示帮助信息
    static void displayHelp() {
        std::cout << " ============================================================================================"
                  << std::endl;
        std::cout << "| -add <destination> <mask> <next hop>       --- Add a route entry                           |"
                  << std::endl;
        std::cout << "| -delete <destination> <mask>               --- Delete a route entry                        |"
                  << std::endl;
        std::cout << "| -modify <destination> <mask> <next hop>    --- Modify a route entry                        |"
                  << std::endl;
        std::cout << "| -lookup <destination>                      --- Lookup the next hop of the destination      |"
                  << std::endl;
        std::cout << "| -forward <source> <destination>            --- Forward a packet from source to destination |"
                  << std::endl;
        std::cout << "| -show                                      --- Display the routing table                   |"
                  << std::endl;
        std::cout << "| -exit                                      --- Exit the program                            |"
                  << std::endl;
        std::cout << " ============================================================================================"
                  << std::endl;
    }
};

int main() {
    RoutingTableManager routingTableManager;

    // 加载初始路由表
    std::vector<RouteEntry> initialRoutingTable = {
            {"192.168.0.0", "255.255.0.0", "192.168.1.1"},
            {"10.0.0.0",    "255.0.0.0",   "10.0.0.1"},
            {"172.16.0.0",  "255.240.0.0", "172.16.1.1"}
    };
    routingTableManager.loadRoutingTable(initialRoutingTable);

    // 显示字符绘制"Router"
    ResultDisplay::displayRouter();

    // 命令行
    std::string commandLine;
    std::cout << ">-: ";
    std::getline(std::cin, commandLine);
    // 命令
    std::string command = getCommand(commandLine);

    while (command != "exit") {
        if (command == "help") {
            ResultDisplay::displayHelp();
        } else if (command == "add") {
            // 命令行以空格分割
            std::vector<std::string> paramAddress = split(commandLine, ' ');
            // 判断参数个数是否正确
            if (paramAddress.size() != 4) {
                std::cout << "Invalid command!" << std::endl;
            } else {
                std::string destination = paramAddress[1], mask = paramAddress[2], nextHop = paramAddress[3];
                // 检测参数格式是否正确
                if (!checkAddress(destination) || !checkAddress(mask) || !checkAddress(nextHop)) {
                    std::cout << "Invalid address!" << std::endl;
                } else {
                    RouteEntry routeEntry = {destination, mask, nextHop};
                    routingTableManager.addRouteEntry(routeEntry);
                }
            }
        } else if (command == "delete") {
            // 命令行以空格分割
            std::vector<std::string> paramAddress = split(commandLine, ' ');
            // 判断参数个数是否正确
            if (paramAddress.size() != 3) {
                std::cout << "Invalid command!" << std::endl;
            } else {
                std::string destination = paramAddress[1], mask = paramAddress[2];
                // 检测参数格式是否正确
                if (!checkAddress(destination) || !checkAddress(mask)) {
                    std::cout << "Invalid address!" << std::endl;
                } else {
                    routingTableManager.deleteRouteEntry(destination, mask);
                }
            }
        } else if (command == "modify") {
            // 命令行以空格分割
            std::vector<std::string> paramAddress = split(commandLine, ' ');
            // 判断参数个数是否正确
            if (paramAddress.size() != 4) {
                std::cout << "Invalid command!" << std::endl;
            } else {
                std::string destination = paramAddress[1], mask = paramAddress[2], nextHop = paramAddress[3];
                // 检测参数格式是否正确
                if (!checkAddress(destination) || !checkAddress(mask) || !checkAddress(nextHop)) {
                    std::cout << "Invalid address!" << std::endl;
                } else {
                    RouteEntry routeEntry = {destination, mask, nextHop};
                    routingTableManager.modifyRouteEntry(routeEntry);
                }
            }
        } else if (command == "lookup") {
            // 命令行以空格分割
            std::vector<std::string> paramAddress = split(commandLine, ' ');
            // 判断参数个数是否正确
            if (paramAddress.size() != 2) {
                std::cout << "Invalid command!" << std::endl;
            } else {
                // 查找下一跳地址
                std::string destinationAddress = paramAddress[1];
                // 检测参数格式是否正确
                if (!checkAddress(destinationAddress)) {
                    std::cout << "Invalid address!" << std::endl;
                } else {
                    std::string nextHop = routingTableManager.lookupNextHop(destinationAddress);
                    ResultDisplay::displayResult(nextHop);
                }
            }
        } else if (command == "forward") {
            // 命令行以空格分割
            std::vector<std::string> paramAddress = split(commandLine, ' ');
            // 判断参数个数是否正确
            if (paramAddress.size() != 3) {
                std::cout << "Invalid command!" << std::endl;
            } else {
                // 转发数据包
                std::string sourceAddress = paramAddress[1], destinationAddress = paramAddress[2];
                // 检测参数格式是否正确
                if (!checkAddress(sourceAddress) || !checkAddress(destinationAddress)) {
                    std::cout << "Invalid address!" << std::endl;
                } else {
                    std::string nextHop = routingTableManager.lookupNextHop(destinationAddress);
                    PacketForwarder::forwardPacket(sourceAddress, destinationAddress, nextHop);
                }
            }
        } else if (command == "show") {
            // 显示路由表
            ResultDisplay::displayRoutingTable(routingTableManager.routingTable);
        } else if (command == "cls") {
            // 清屏
            system("cls");
            ResultDisplay::displayRouter();
        } else {
            std::cout << "Invalid command!" << std::endl;
        }

        if (command != "cls") {
            std::cout << std::endl;
        }
        std::cout << ">-: ";
        std::getline(std::cin, commandLine);
        command = getCommand(commandLine);
    }
    return 0;
}
