/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  var i, sum;
  for (i = 0, sum = 0; i < prices.length - 1; i++) {
    if (prices[i + 1] > prices[i]) {
      sum += prices[i + 1] - prices[i];
    }
  }
  return sum;
};
