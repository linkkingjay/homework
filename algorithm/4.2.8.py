# P103   Problem 4.2.8
# 设计一个算法对n个实数组成的数组进行重新排列，使得其中所有的负元素都位于正元素
# 之前。这个算法需要兼顾空间效率和时间效率。

def func(num):
    n = len(num)
    i = 0
    j = n - 1
    while i != j:
        if num[i] < 0:
            num[i], num[j] = num[j], num[i]
            j -= 1
        i += 1

def main():
    a = range(-10, 11)
    print a
    func(a)
    print a

main()

