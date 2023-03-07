/**
 * 最大子数组和
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
  let max = nums[0];
  let sum = 0;
  for (let i = 0; i < nums.length; i++) {
    if (sum > 0) {
      sum += nums[i];
    } else {
      sum = nums[i];
    }
    max = Math.max(max, sum);
  }
  return max;
};

console.log(maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]));