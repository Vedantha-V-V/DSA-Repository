class Solution:
    def minSumSquareDiff(self,nums1:list,nums2:list,k1:int,k2:int)->int:
        difference = [abs(a-b) for a,b in zip(nums1,nums2)]
        k = k1 + k2
        maxdiff = max(difference)
        def feasible(target):
            ops = sum(max(0,diff-target) for diff in difference)
            return ops <= k

        left,right = 0,maxdiff-1
        optimal = maxdiff
        while left <= right:
            mid = (left+right)//2
            if feasible(mid):
                optimal = mid
                right = mid - 1
            else:
                left = mid + 1

        for i,diff in enumerate(difference):
            ops = max(0,diff-optimal)
            difference[i] = min(optimal,diff)
            k -= ops

        for i,diff in enumerate(difference):
            if k == 0:
                break
            if diff == optimal:
                difference[i] -= 1
                k -= 1

        return sum(diff*diff for diff in difference)

if __name__ == "__main__":
    solution = Solution()
    print(solution.minSumSquareDiff([1,4,10,12],[5,8,6,9],1,1))
