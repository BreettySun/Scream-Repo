/**
 * 重塑矩阵
 * @param {number[][]} mat
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function (mat, r, c) {
  let line = mat.length
  let column = mat[0].length
  if (line * column !== r * c) {
    return mat
  } else {
    let result = []
    let m = 0, n = 0
    for (let i = 0; i < r; i++) {
      let temp = []
      for (let j = 0; j < c; j++) {
        temp.push(mat[m][n++])
        if (n === column) {
          m++
          n = 0
        }
      }
      result.push(temp)
    }
    return result
  }
};

console.log(matrixReshape([[1, 2], [3, 4]], 1, 4));