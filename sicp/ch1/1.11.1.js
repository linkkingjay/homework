// 递归
var callCount = 0
function f (n) {
  callCount += 1
  if (n < 3) {
    return n
  } else {
    return (f(n - 1) + 2 * f(n - 2) + 3 * f(n - 3))
  }
}

for (var i = 0; i < 10; i++) {
  console.log(`i: ${i}, f(i): ${f(i)}`)
}
console.log(`call count: ${callCount}`)
