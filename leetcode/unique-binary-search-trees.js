/**
 * @param {number} n
 * @return {number}
 */
var numTrees = function(n) {
  var i, j, s;
  s = [1, 1];
  for (i = 2; i <= n; i++) {
    s[i] = 0;
    for (j = 1; j <= i; j++) {
      s[i] += s[j - 1] * s[i - j];
    }
  }
  console.log(s);
  return s[n];
};
