/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
  var i, length, sum, pSum, temp, num, pNum, cur;
  length = s.length;
  if (length === 0 || s[0] == '0') {
    return 0;
  }

  cur = sum = pSum = 1;
  for (i = 1; i < length; i++) {
    num = s[i];
    pNum = s.substr(i - 1, 2);
    if (is_valid(num) && is_valid(pNum)) {
      cur = sum + pSum;
    } else if (is_valid(num) && !is_valid(pNum)) {
      cur = sum;
    } else if (!is_valid(num) && is_valid(pNum)) {
      cur = pSum;
    } else if (!is_valid(num) && !is_valid(pNum)) {
      return 0;
    }
    pSum = sum;
    sum = cur;
  }

  return cur;
  function is_valid(str) {
    if (str.length === 2 && str[0] === '0') {
      return false;
    }
    var number = parseInt(str);
    return number >= 1 && number <= 26;
  }
};
