/*
 *Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 *The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 *You may assume that each input would have exactly one solution.
 *
 *Input: numbers={2, 7, 11, 15}, target=9
 *Output: index1=1, index2=2
 */

var twoSum = function (nums, target) {
  var i, j;
  var map = {};
  for (i = 0; i < nums.length; i++) {
    if (map[nums[i]]) {
      if (i < map[nums[i]].index) {
        return [i + 1, map[nums[i]].index + 1];
      } else {
        return [map[nums[i]].index + 1, i + 1];
      }
    } else {
      map[target - nums[i]] = {
        value: nums[i],
        index: i
      };
    }
  }
  return false;
};
