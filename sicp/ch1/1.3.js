function sumOfMaxTwo (a, b, c) {
  if (a >= c && b >= c) {
    return a + b
  } else if (a >= b && c >= b) {
    return a + c
  } else if (b >= a && c >= a) {
    return b + c
  }
}
