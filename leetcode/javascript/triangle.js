/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
  var map = [];
  var i, j;
  map[0] = [triangle[0][0]];
  for (i = 1; i < triangle.length; i++) {
    map[i] = [];
    for (j = 0; j < i + 1; j++) {
      if (j === 0) {
        map[i][j] = map[i - 1][0] + triangle[i][j];
      } else if (j === i) {
        map[i][j] = map[i - 1][i - 1] + triangle[i][j];
      } else {
        map[i][j] = Math.min(map[i - 1][j - 1] + triangle[i][j],
                             map[i - 1][j] + triangle[i][j]);
      }
    }
  }
  console.log(map);
  return Math.min.apply(null, map[i - 1]);
};
