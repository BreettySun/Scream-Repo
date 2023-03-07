/**
 * 20. 有效的括号
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  const stack = []
  const map = {
    '(': ')',
    '{': '}',
    '[': ']'
  }
  for (let i = 0; i < s.length; i++) {
    if (map[s[i]]) {
      stack.push(s[i])
    } else {
      if (map[stack.pop()] !== s[i]) return false
    }
  }
  return stack.length === 0
}