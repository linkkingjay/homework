class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        l = 0
        r = len(num) - 1
        while l < r:
            if l == r - 1:
                if num[l] < num[r]:
                    return l
                else:
                    return r
            if l == r:
                return l
            mid = (l + r) / 2
            print l, mid, r
            if num[mid] > num[l]:
                if num[l] < num[r]: # 0 1 2
                    r = mid - 1
                else: # 1 2 0
                    l = mid + 1
            elif num[mid] < num[l]:
                if num[l] < num[r]: # 2 0 1
                    r = mid - 1
                else: # 2 1 0
                    l = mid + 1
        return l


if __name__ == "__main__":
    sol = Solution()
    num = [4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 3]
    num = [8, 9, 10, 0, 1, 2, 3]
    print sol.findMin(num)
