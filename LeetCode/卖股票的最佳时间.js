/**
 * 卖股票的最佳时机
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let len = prices.length
  let minPrice = 999999
  let maxRevenue = 0
  for (let i = 0; i < len; i++) {
    if (minPrice > prices[i]) {
      minPrice = prices[i]
    } else {
      maxRevenue = Math.max(maxRevenue, prices[i] - minPrice)
    }
  }
  return maxRevenue
};

console.log(maxProfit([7, 1, 5, 3, 6, 4]));
console.log(maxProfit([7, 6, 4, 3, 1]));