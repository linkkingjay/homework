function compare (x, y) {
  if (x > y) {
    return 'GT';
  } else if (x === y) {
    return 'EQ';
  } else if (x < y) {
    return 'LT';
  } else {
    return 'ERROR';
  }
}
function compareWithHundred(x) {
  return compare(x, 100);
}

console.log(compareWithHundred(99));
console.log(compareWithHundred(100));
console.log(compareWithHundred(101));
