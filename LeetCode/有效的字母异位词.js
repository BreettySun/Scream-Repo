/**
 * 有效的字母异位词
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  let letterS = new Array(26).fill(0)
  let letterT = new Array(26).fill(0)
  for (const c of s) {
    letterS[c.charCodeAt() - 'a'.charCodeAt()]++
  }
  for (const c of t) {
    letterT[c.charCodeAt() - 'a'.charCodeAt()]++
  }
  for (let i = 0; i < 26; i++) {
    // console.log(letterS[i], '--', letterT[i]);
    if (letterS[i] !== letterT[i]) {
      return false
    }
  }
  return true
};

console.log(isAnagram('anagram', 'nagaram'));
console.log(isAnagram('cat', 'rat'));