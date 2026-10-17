from typing import List

class Solution:
    def minSwaps(self, nums:List[int]) -> int:
        def digiSum(num:int)->int:
            res = 0
            while num > 0:
                rem = num%10
                res += rem
                num = num//10
            return res
        swaps = len(nums)
        visited = [False for _ in range(len(nums))]
        digiSort = sorted((digiSum(num),num) for num in nums)
        d = {}
        for i,pair in enumerate(digiSort):
            d[pair[1]] = i
        for i,num in enumerate(nums):
            if not visited[i]:
                swaps -= 1
                pos = i
                while not visited[pos]:
                    visited[pos] = True
                    pos = d[nums[pos]]
        return swaps

if __name__ == "__main__":
    solution = Solution()
    print(solution.minSwaps([18,43,34,16]))
