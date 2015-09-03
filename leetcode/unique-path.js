/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
  var map = [];
  var i, j;
  for (i = 0; i < m; i++) {
    map[i] = [];
    for (j = 0; j < n; j++) {
      if (i === 0 && j === 0) {
        map[i][j] = 1;
      } else {
        if (i === 0) {
          map[i][j] = map[i][j - 1];
        } else if (j === 0) {
          map[i][j] = map[i - 1][j];
        } else {
          map[i][j] = map[i - 1][j] + map[i][j - 1];
        }
      }
    }
  }
  return map[m - 1][n - 1];
};

