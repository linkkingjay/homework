/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
  var i, length, sum, max, pMax, temp;
  if (nums.length === 0) {
    return 0;
  }
  max = nums[0];
  pMax = 0;
  for (i = 1, sum = nums[0], length = nums.length; i < length; i++) {
    console.log(pMax, max);
    pMax += nums[i];
    sum = Math.max(max, pMax);
    pMax = max;
    max = sum;
  }
  return sum;
};
