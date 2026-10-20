class Solution:
    def sortableIntegers(self,nums:list)->int:
        n = len(nums)
        prefixCount = [0]*n
        nextDescent = [n]*n
        res = 0
        for i in range(n-1):
            prefixCount[i+1] = prefixCount[i] + (nums[i] > nums[i+1])
        for i in range(n-2,-1,-1):
            nextDescent[i] = i if nums[i] > nums[i+1] else nextDescent[i+1]
        for k in range(1,n+1):
            if n%k:
                continue
            prev_max = float("-inf")
            sortable = True
            for i in range(0,n,k):
                j = i+k-1
                c = prefixCount[j] - prefixCount[i]
                if c == 0:
                    min,max = nums[i], nums[j]
                elif c == 1:
                    if nums[j] > nums[i]:
                        sortable = False
                        break
                    p = nextDescent[i]
                    min,max = nums[p+1],nums[p]
                else:
                    sortable = False
                    break
                if min < prev_max:
                    sortable = False
                    break
                prev_max = max
            if sortable:
                res += k
        return res


if __name__ == "__main__":
    solution = Solution()
    print(solution.sortableIntegers([3,1,2]))