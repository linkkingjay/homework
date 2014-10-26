var sorted3 = function (x) {
  return function (y) {
    return function (z) {
      if (z >= y && y >= x) {
        return true;
      } else {
        return false;
      }
    }
  }
};

console.log(sorted3(7)(9)(11)); // true
console.log(sorted3(12)(8)(11)); // false
