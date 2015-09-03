/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
  var i, j, m, n, map;
  m = obstacleGrid.length;
  n = obstacleGrid[0].length;
  map = [];
  for (i = 0; i < m; i++) {
    map[i] = [];
    for (j = 0; j < n; j++) {
      if (obstacleGrid[i][j] === 1) {
        map[i][j] = 0;
        continue;
      }
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
