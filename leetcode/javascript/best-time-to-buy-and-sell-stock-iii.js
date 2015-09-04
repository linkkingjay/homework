/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  var i, length;
  var min, max, profits, sum = 0;
  profits = [];
  for (i = 0, min = prices[0], length = prices.length; i < length; i++) {
    min = Math.min(min, prices[i]);
    profits[i] = Math.max(sum, prices[i] - min);
    sum = profits[i];
  }

  sum = 0;
  for (i = length - 1, max = prices[length - 1]; i > 0; i--) {
    max = Math.max(max, prices[i]);
    profits[i] += max - prices[i];
    sum = Math.max(sum, profits[i]);
  }
  return sum;
};
