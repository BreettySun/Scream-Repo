/**
 * 矩阵置零
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function (matrix) {
  let line = matrix.length;
  let row = matrix[0].length;
  let lineArr = [];
  let rowArr = [];
  for (let i = 0; i < line; i++) {
    for (let j = 0; j < row; j++) {
      if (matrix[i][j] === 0) {
        lineArr.push(i);
        rowArr.push(j);
      }
    }
  }
  for (let i = 0; i < line; i++) {
    for (let j = 0; j < row; j++) {
      if (lineArr.includes(i) || rowArr.includes(j)) {
        matrix[i][j] = 0;
      }
    }
  }
};