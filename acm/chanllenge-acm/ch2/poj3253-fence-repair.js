'use strict'
const L = [1, 2, 3, 4, 5]

function main() {
  function solve(L, ans) {
    if (L.length === 1) {
      return 0
    } else {
      L.sort()
      let tmp = L[0] + L[1]
      L.splice(0, 1)
      L[0] = tmp
      ans += tmp
      return tmp + solve(L, ans)
    }
  }

  console.log(solve(L, 0))
}

main()
