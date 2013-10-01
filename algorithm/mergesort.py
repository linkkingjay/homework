def merge(B, C, A):
    i = j = k = 0
    n = len(A)
    p = len(B)
    q = len(C)

    while i < p and j < q:
        if B[i] <= C[j]:
            A[k] = B[i]
            i += 1
        else:
            A[k] = C[j]
            j += 1
        k += 1
    
    if i == p:
        A[k : n] = C[j : q]
    else:
        A[k : n] = B[i : p]
        
def merge_sort(A):
    n = len(A)
    if n > 1:
        B = A[0 : n / 2]
        C = A[n / 2 : n]
        merge_sort(B)
        merge_sort(C)
        merge(B, C, A)

def main():
    A = [3, 6, 1, 6, 2, 6, 0, 9, 8]
    merge_sort(A)
    print A

if __name__ == '__main__':
    main()
