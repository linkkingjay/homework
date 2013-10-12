##
# @file max-subarray.py
# @synopsis  使用分治策略求数组中的最大子数组
# @author linkkingjay
# @version 1.0
# @date 2013-10-12


from random import choice
def max_crossing_subarray(A):
    mid = len(A) / 2
    left_sum = -float('inf')
    right_sum = -float('inf')

    csum = 0
    for i in range(mid - 1, -1, -1):
        csum += A[i]
        if csum > left_sum:
            left_sum = csum

    csum = 0
    for i in range(mid, len(A)):
        csum += A[i]
        if csum > right_sum:
            right_sum = csum

    return left_sum + right_sum

def max_subarray(A):
    n = len(A)
    # only one element
    if n == 1:
        return A[0]

    mid = n / 2
    left = max_subarray(A[0:mid])
    right = max_subarray(A[mid:])
    center = max_crossing_subarray(A)
    return max([left, right, center])

def main():
    D = list()
    for i in range(20):
        D.append(choice(range(100)))
    print D

    A = [0]
    for i in range(19):
        A.append(D[i + 1] - D[i])
    print A

    print max_subarray(A)

if __name__ == "__main__":
    main()
