var assert = require('assert');
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
  if (nums.length === 1) {
    return nums[0];
  }
  return Math.max(
    house_robber(nums.slice(0, nums.length - 1)),
    house_robber(nums.slice(1, nums.length))
  );

  function house_robber(nums) {
    var i, length, sum, max, pMax;
    if (nums.length === 0) {
      return 0;
    }
    max = nums[0];
    pMax = 0;
    for (i = 1, sum = nums[0], length = nums.length; i < length; i++) {
      pMax += nums[i];
      sum = Math.max(max, pMax);
      pMax = max;
      max = sum;
    }
    return sum;
  }
};

