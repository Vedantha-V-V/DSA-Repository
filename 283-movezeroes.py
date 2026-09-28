class Solution:
    def moveZeroes(self,nums)->None:
        k = 0
        for i in range(len(nums)):
            if nums[i]!=0:
                nums[i],nums[k] = nums[k],nums[i]
                k+=1

if __name__ == "__main__":
    solution = Solution()
    nums = [1,3,0,12,0]
    solution.moveZeroes(nums)
    print(nums)