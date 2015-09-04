/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
  var i, a, b, t;

  if (n === 0) {
    return 0;
  }
  if (n === 1) {
    return 1;
  }
  a = 1, b = 1;
  for (i = 2; i <= n; i++) {
    t = a + b;
    a = b;
    b = t;
  }
  return b;
};
