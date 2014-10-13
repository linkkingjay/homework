(*function 1*)
fun is_older (x : int*int*int, y : int*int*int) = 
  if (#1 x) < (#1 y)
  then true
  else if (#1 x) = (#1 y) andalso (#2 x) < (#2 y)
       then true
       else if (#1 x) = (#1 y) andalso (#2 x) = (#2 y) andalso (#3 x) < (#3 y)
            then true
            else false

(*function 2*)
fun number_in_month (dates : (int*int*int) list, month : int) = 
  if null dates
  then 0
  else if (#2 (hd dates)) = month
       then 1 + number_in_month(tl dates, month)
       else number_in_month(tl dates, month)

(*function 3*)
fun number_in_months (dates : (int*int*int) list, months : int list) =
  if null dates
  then 0
  else if null months
       then 0
       else number_in_month(dates, hd months) + number_in_months(dates, tl months)

(*function 4*)
fun dates_in_month (dates : (int*int*int) list, month : int) =
  if null dates
  then []
  else if (#2 (hd dates)) = month
       then (hd dates) :: dates_in_month((tl dates), month)
       else dates_in_month((tl dates), month)

(*function 5*)
fun dates_in_months (dates : (int*int*int) list, months : int list) =
  if null dates
  then []
  else if null months
       then []
       else dates_in_month(dates, hd months) @ dates_in_months(dates, tl months)

(*function 6*)
fun get_nth (strings : string list, n : int) = 
  if n=1
  then hd strings
  else get_nth(tl strings, n-1)

(*function 7*)
fun date_to_string (date : int*int*int) = 
  let
    val month_strings = ["January", "February", "March", "April", "May", "June",
                         "July", "August", "September", "October", "November",
                         "December"]
  in
    get_nth(month_strings, #2 date) ^ " " ^ Int.toString(#3 date) ^ ", " ^
            Int.toString(#1 date)
  end

(*function 8*)
fun number_before_reaching_sum (sum : int, numbers : int list) =
  if sum > 0
  then 1 + number_before_reaching_sum(sum - hd numbers, tl numbers)
  else ~1


(*function 9*)
fun what_month (day : int) =
  let
    val month_days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
  in
    number_before_reaching_sum(day, month_days) + 1
  end

(*function 10*)
fun month_range(day1 : int, day2 : int) =
  if day1 > day2
  then []
  else what_month(day1) :: month_range(day1 + 1, day2)

(*function 11*)
fun oldest(dates : (int*int*int) list) =
  if null dates
  then NONE
  else
    let val tl_oldest = oldest(tl dates)
    in if isSome tl_oldest andalso is_older(valOf tl_oldest, hd dates)
       then tl_oldest
       else SOME (hd dates)
    end
