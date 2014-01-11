oriDiv := Number getSlot("/")
Number / := method(i,
    if (i == 0, 0, self oriDiv(i))
)
(2 / 0) println
(8 / 4) println
(9 / 2) println
