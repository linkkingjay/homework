List myAverage := method(
    avg := 0
    self foreach(v, avg = avg + v)
    avg = avg / (self size)
    return avg
)

sum := 0
a := list(list(1,2,3), list(4,5,6), list(7,8,9))

a foreach(l, 
    l foreach(v, sum = sum + v)
    l myAverage println
)
sum println

