fun pow (x:int, y:int) = (* correct only for y >= 0 *)
  if y=0
  then 1
  else x * pow(x, y-1)
