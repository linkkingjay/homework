/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
  var i, sum, max, min, length, t;
  for (i = 0, max = min = 1, sum = nums[0], length = nums.length; i < length; i++) {
    max *= nums[i];
    min *= nums[i];

    if (max < min) {
      t = max;
      max = min;
      min = t;
    }

    sum = Math.max(sum, max, min);
    if (max <= 0) {
      max = 1;
    }
    if (min >= 0 ) {
      min = 1;
    }
  }
  return sum;
};
