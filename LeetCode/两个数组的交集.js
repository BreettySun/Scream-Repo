/**
 * 两个数组的交集
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function (nums1, nums2) {
  let result = []
  let len1 = nums1.length
  let len2 = nums2.length
  for (let i = 0; i < len1; i++) {
    for (let j = 0; j < len2; j++) {
      if (nums1[i] === nums2[j]) {
        result.push(nums1[i])
        nums1.splice(i, 1)
        nums2.splice(j, 1)
        len1--
        len2--
        i--
        j--
      }
    }
  }
  return result
};

/**
 * 双指针解法
 */
let intersect = function (nums1, nums2) {
  nums1.sort((a, b) => a - b);
  nums2.sort((a, b) => a - b);
  let l = 0, r = 0, ans = [];
  while (l < nums1.length && r < nums2.length) {
    if (nums1[l] === nums2[r]) {
      ans.push(nums1[l]);
      l++;
      r++;
    } else nums1[l] < nums2[r] ? l++ : r++;
  }
  return ans;
};
console.log(intersect([1, 2, 2, 1], [2, 2]));
console.log(intersect([4, 9, 5], [9, 4, 9, 8, 4]));