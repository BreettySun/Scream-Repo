#include<bits/stdc++.h>
#define MAXLEN 255
using namespace std;

// 字符串暴力匹配
int Index(string s, string t) {
	unsigned i = 0, j = 0;
	while (i < s.length() && j < t.length()) {
		if (s[i] == t[j]) {
			i++;
			j++;
		} else {
			i = i - j + 2;
			j = 0;
		}
	}
	if (j >= t.length()) {
		return i - t.length();
	} else {
		return -1;
	}
}

int main() {
	string s;
	string t;
	cin >> s;
	cin >> t;
	cout << Index(s, t) << endl;
	return 0;
}
