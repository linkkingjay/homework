(* Dan Grossman, Coursera PL, HW2 Provided Code *)

(* if you use this function to compare two strings (returns true if the same
   string), then you avoid several of the functions in problem 1 having
   polymorphic types that may be confusing *)
fun same_string(s1 : string, s2 : string) =
    s1 = s2

(* function 1(a) *)
fun all_except_option(x, ys) =
  case ys of
    []     => NONE
  | y::ys' => if same_string(x, y)
              then SOME(ys')
              else if isSome(all_except_option(x, ys'))
                   then SOME(y::valOf(all_except_option(x, ys')))
                   else NONE

(* function 1(b) *)
fun get_substitutions1(xss, s) =
  case xss of
    [] => []
  | xs::xss' => if isSome(all_except_option(s, xs))
                then valOf(all_except_option(s, xs)) @ get_substitutions1(xss', s)
                else get_substitutions1(xss', s)


val test1 = all_except_option("string", ["string"]) = SOME []

val test2 = get_substitutions1([["foo"],["there"]], "foo") = []

(* you may assume that Num is always used with values 2, 3, ..., 10
   though it will not really come up *)
datatype suit = Clubs | Diamonds | Hearts | Spades
datatype rank = Jack | Queen | King | Ace | Num of int 
type card = suit * rank

datatype color = Red | Black
datatype move = Discard of card | Draw 

exception IllegalMove

(* put your solutions for problem 2 here *)
