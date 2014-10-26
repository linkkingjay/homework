val cbs : (int -> unit) list ref = ref []
fun onKeyEvent f = cbs := f::(!cbs) (* The only "public" binding *)
fun onEvent i = 
  let fun loop fs =
        case fs of
          [] => ()
        | f::fs' => (f i; loop fs')
  in loop (!cbs)
  end

val timesPressed = ref 0
val _ = onKeyEvent (fn _ => timesPressed := (!timesPressed) + 1)

fun printIfPressed i = 
  onKeyEvent (fn j => if i = j
                      then print ("you pressed " ^ Int.toString i ^ "\n")
                      else ())

val _ = printIfPressed 4
val _ = printIfPressed 11
val _ = printIfPressed 23
