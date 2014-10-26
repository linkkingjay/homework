fun sorted3 x y z = z >= y andalso y >= x

fun fold f acc xs =
  case xs of
    []     => acc
  | x::xs' => fold f (f(acc, x)) xs

val is_nonnegative = (sorted3 0) 0

val sum = fold (fn (x, y) => x + y) 0
