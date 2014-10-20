datatype exp = Constant of int
             | Negate of exp
             | Add of exp * exp
             | Multiply of exp * exp

fun number_of_adds e =
  case e of
    Constant i       => 0
  | Negate e2        => number_of_adds e2
  | Add(e1, e2)      => 1 + number_of_adds e1 + number_of_adds e2
  | Multiply(e1, e2) => number_of_adds e1 + number_of_adds e2
val test_number_of_adds =
  number_of_adds(Add(Constant 1, Add(Constant 2, Constant 3))) = 2

fun largest_constant e =
  case e of
    Constant i => i
  | Negate e2 => largest_constant e2
  | Add(e1, e2) => if largest_constant e1 > largest_constant e2
                   then largest_constant e1
                   else largest_constant e2
  | Multiply(e1, e2) => if largest_constant e1 > largest_constant e2
                        then largest_constant e1
                        else largest_constant e2
val test_largest_constant = 
  largest_constant(Add(Constant 1, Add(Constant 2, Constant 3))) = 3

