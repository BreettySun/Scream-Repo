/**太慢啦
 * 26. 删除排序数组中的重复项
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
  let len = nums.length
  for (let i = 0; i < len; i++) {
    if (nums[i] === nums[i + 1]) {
      nums.splice(i, 1)
      i--
      len--
    }
  }
  return nums.length
};

/**正解
 * 26. 删除排序数组中的重复项
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
  let i = 0
  for (let j = 1; j < nums.length; j++) {
    if (nums[i] !== nums[j]) {
      i++
      nums[i] = nums[j]
    }
  }
  return i + 1
};