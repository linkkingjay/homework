/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
  var i, sum, s, length;
  for (i = 0, s = 0, sum = nums[0], length = nums.length; i < length; i++) {
    s += nums[i];
    sum = Math.max(sum, s);
    if (s < 0) {
      s = 0
    }
  }
  return sum;
};
