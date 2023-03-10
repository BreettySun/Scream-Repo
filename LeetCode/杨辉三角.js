/**
 * 杨辉三角
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function (numRows) {
  if (numRows === 1) {
    return [[1]]
  } else if (numRows === 2) {
    return [[1], [1, 1]]
  } else {
    let numNow = numRows - 2
    let result = [[1], [1, 1]]
    let temp = [1]
    for (let i = 0; i < numNow; i++) {
      for (let j = 0; j < i + 3 - 1; ++j) {
        if (j === i + 1) {
          temp.push(1)
          break
        }
        let a = result[i + 1][j] + result[i + 1][j + 1]
        temp.push(a)
      }
      result.push(temp)
      temp = [1]
    }
    return result
  }
};

console.log(generate(4));