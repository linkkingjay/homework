val x = ref 0
val x2 = x
val x3 = ref 0
(* val y = x + 1 *) (* wrong: x is not an int *)
val y = (!x) + 1 (* y is 1 *)
val _ = x := (!x) + 7 (* the contents of the reference x refers to is now 7 *)
val z1 = !x (* z1 is 7 *)
val z2 = !x2 (* z2 is also 7 -- with mutation, aliasing matters *)
val z3 = !x3 (* z3 is 0 *)
