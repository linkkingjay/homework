function cc(amount, coin_values) {
  if (amount === 0) {
    return 1;
  } else if (amount < 0 || no_more(coin_values)) {
    return 0;
  } else {
    var left_amount = amount - first_denomination(coin_values);
    return cc(amount, except_first_denomination(coin_values)) +
      cc(left_amount, coin_values);
  }
}

function first_denomination(coin_values) {
  return coin_values[0];
}

function except_first_denomination(coin_values) {
  return coin_values.slice(1);
}

function no_more(coin_values) {
  return coin_values.length === 0;
}

console.log(cc(100, [50, 25, 10, 5, 1]));
