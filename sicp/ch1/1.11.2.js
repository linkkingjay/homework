var callCount = 0
function f (n) {
  callCount += 1
  if (n < 3) {
    return n
  } else {
    return fIter(2, 1, 0, n)
  }
}

function fIter(a, b, c, count) {
  callCount += 1
  if (count < 3) {
    return a
  } else {
    return fIter((a + 2 * b + 3 * c), a, b, count - 1)
  }
}

for (var i = 0; i < 10; i++) {
  console.log(`i: ${i}, f(i): ${f(i)}`)
}
console.log(`call count: ${callCount}`)
