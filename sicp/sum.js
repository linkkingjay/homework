function sum(term, a, next, b) {
  for (var i = a, sum = 0; i <= b; i = next(i)) {
    sum += term(i);
  }
  return sum;
}

function sum_cubes(a, b) {
  return sum(function (x) {
    return x * x * x;
  }, a, function (x) {
    return x + 1;
  }, b);
}
