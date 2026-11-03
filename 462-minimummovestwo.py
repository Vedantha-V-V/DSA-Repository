class Solution:
    def minMoves2(self,nums:list)->int:
        nums.sort()
        median = nums[len(nums)>>1]
        return sum(abs(num-median) for num in nums)

if __name__ == "__main__":
    solution = Solution()
    print(solution.minMoves2([1,10,2,9]))