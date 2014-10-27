(* Coursera Programming Languages, Homework 3, Provided Code *)

exception NoAnswer

datatype pattern = Wildcard
		 | Variable of string
		 | UnitP
		 | ConstP of int
		 | TupleP of pattern list
		 | ConstructorP of string * pattern

datatype valu = Const of int
	      | Unit
	      | Tuple of valu list
	      | Constructor of string * valu

fun g f1 f2 p =
    let 
	val r = g f1 f2 
    in
	case p of
	    Wildcard          => f1 ()
	  | Variable x        => f2 x
	  | TupleP ps         => List.foldl (fn (p,i) => (r p) + i) 0 ps
	  | ConstructorP(_,p) => r p
	  | _                 => 0
    end

(**** for the challenge problem only ****)

datatype typ = Anything
	     | UnitT
	     | IntT
	     | TupleT of typ list
	     | Datatype of string

(**** you can put all your code here ****)
fun only_capitals xs =
  List.filter (fn x => Char.isUpper(String.sub(x, 0))) xs
val test1 = only_capitals ["A","B","C"] = ["A","B","C"]

fun longest_string1 xs = 
  case xs of
    [] => ""
  | x::xs' => List.foldl (fn (a, b) => if String.size a > String.size b
                                       then a
                                       else b) x xs
val test2 = longest_string1 ["A","bc", "cd", "C"] = "bc"

fun longest_string2 xs =
  case xs of
    [] => ""
  | x::xs' => List.foldl (fn (a, b) => if String.size a >= String.size b
                                    then a
                                    else b) x xs
val test3 = longest_string2 ["A","bc", "cd", "C"] = "cd"

fun longest_string_helper f =
  fn xs =>
    case xs of
      [] => ""
    | x::xs => List.foldl (fn (a, b) => if f ((String.size a), (String.size b))
                                        then a
                                        else b) x xs

val longest_string3 = longest_string_helper (fn (x, y) => x > y)

val longest_string4 = longest_string_helper (fn (x, y) => x >= y)

val test4a= longest_string3 ["A","bc","C"] = "bc"

val test4b= longest_string4 ["A","B","C"] = "C"
