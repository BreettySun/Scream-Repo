/**
 * 字符串中的第一个唯一字符
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function (s) {
  for (let i = 0; i < s.length; i++) {
    let flag = true
    for (let j = 0; j < s.length; j++) {
      if (s[i] === s[j] && i !== j) {
        flag = false
        break
      }
    }
    if (flag) {
      return i
    }
  }
  return -1
};

console.log(firstUniqChar('leetcode'));
console.log(firstUniqChar('loveleetcode'));
console.log(firstUniqChar('aabb'));