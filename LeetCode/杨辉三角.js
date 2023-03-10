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


/**
 * 官方解法
 */
var generate = function (numRows) {
  const ret = [];
  for (let i = 0; i < numRows; i++) {
    const row = new Array(i + 1).fill(1);
    for (let j = 1; j < row.length - 1; j++) {
      row[j] = ret[i - 1][j - 1] + ret[i - 1][j];
    }
    ret.push(row);
  }
  return ret;
};

console.log(generate(4));