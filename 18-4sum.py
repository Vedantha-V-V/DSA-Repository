class Solution:
    def fourSum(self,nums:list,target:int)->list[list[int]]:
        res = []
        n = len(nums)
        nums.sort()
        for i in range(n-3):
            if i>0 and nums[i]==nums[i-1]:
                continue
            for j in range(i+1,n-2):
                if j>i+1 and nums[j]==nums[j-1]:
                    continue
                k = j+1
                l = n-1
                while(k<l):
                    x = nums[i] + nums[j] + nums[k] + nums[l]
                    if x == target:
                        res.append([nums[i],nums[j],nums[k],nums[l]])
                        k,l=k+1,l-1
                        while k<l and nums[k]==nums[k-1]:
                            k+=1
                        while k<l and nums[l]==nums[l+1]:
                            l-=1
                    elif x > target:
                        l-=1
                    else:
                        k+=1
        return res


if __name__ == "__main__":
    solution = Solution()
    print(solution.fourSum([1,0,-1,0,-2,2],0))