f1 := 1
f2 := 1
t := 0
for(i, 3, 20, 
    f1 println
    t = f2
    f2 = f1 + f2
    f1 = t
)
