# coding: utf-8
# Python实现选择排序
def selection_sort(s):
    i = 0
    n = len(s)

    while i < n - 1:
        m = i
        j = i + 1
        while j < n:
            if s[m] > s[j]: 
                m = j
            j += 1
        t = s[i]
        s[i] = s[m]
        s[m] = t
        i += 1

def main():
    s = [3, 6, 1, 6, 2, 6, 0, 9, 8]
    selection_sort(s)
    print s

if __name__ == '__main__':
    main()
