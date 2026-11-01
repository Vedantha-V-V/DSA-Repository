class Solution:
    def minMoves(self,nums:list)->int:
        minval = min(nums)
        total = sum(nums)
        return total - minval*len(nums)

if __name__ == "__main__":
    solution = Solution()
    print(solution.minMoves([1,2,3]))