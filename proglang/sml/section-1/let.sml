let val x = 1
in
  (let val x = 2 in x+1 end) + (let val y = x+2 in y+1 end)
end;

fun countup_from1_better (x : int) =
  let fun count(from:int) =
          if from=x
          then x::[]
          else from :: count(from + 1)
  in
    count 1
  end;

val countup = countup_from1_better(10);


fun better_max (xs : int list) =
  if null xs
  then NONE
  else
    let val tl_ans = better_max(tl xs)
    in if isSome tl_ans andalso valOf tl_ans > hd xs
       then tl_ans
       else SOME (hd xs)
    end;

fun better_max2 (xs : int list) =
  if null xs
  then NONE
  else let (* fine to assume argument nonempty because it is local *)
      fun max_nonempty (xs : int list) = 
        if null (tl xs) (* xs must not be [] *)
        then hd xs
        else let val tl_ans = max_nonempty(tl xs)
             in
               if hd xs > tl_ans
               then hd xs
               else tl_ans
             end
       in
         SOME (max_nonempty xs)
       end;

val num = [3, 6, 1, 6, 2, 6, 0, 9, 8];
