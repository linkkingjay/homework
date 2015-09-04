class Solution:
    def singleNumber(self, A):
        ret = 0
        for num in A:
            ret = num ^ ret
        return ret
