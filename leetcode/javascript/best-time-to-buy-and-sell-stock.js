/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  var length = prices.length;
  var i, min;
  var maxProfit = 0;

  for (i = 1, min = prices[0]; i < length; i++) {
    if (min > prices[i]) {
      min = prices[i];
    }
    if (maxProfit < prices[i] - min) {
      maxProfit = prices[i] - min;
    }
  }
  return maxProfit;
};
