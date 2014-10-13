fun sum_list (xs : int list) =
  if null xs
  then 0
  else hd(xs) + sum_list(tl xs);

fun countdown (x : int) =
  if x=0
  then []
  else x :: countdown(x - 1);

fun append (xs : int list, ys : int list) =
  if null xs
  then ys
  else hd xs :: append(tl xs, ys);

val num_list = [1, 2, 3, 4, 5];
val sum = sum_list(num_list);

val countdown_list = countdown(10);

val list_x = [1, 2, 3];
val list_y = [4, 5, 6];
val lixt_x_y = append(list_x, list_y);
