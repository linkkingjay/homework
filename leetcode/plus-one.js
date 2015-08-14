// Given a non-negative number represented as an array of digits, plus one to the number.
// The digits are stored such that the most significant digit is at the head of the list.

/**
* @synopsis  
*
* @param {number[]} digits
*
* @returns {number[]}
*/
var plusOne = function(digits) {
  var l = digits.length;
  var i = l - 1;
  for (; i >= 0; i--) {
    digits[i]++;
    if (digits[i] == 10) {
      digits[i] = 0;
    } else {
      break;
    }
  }
  if (digits[0] == 0) {
    digits.unshift(1);
  }
  return digits;
};
