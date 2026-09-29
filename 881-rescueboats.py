class Solution:
    def numRescueBoats(self,people:list,limit:int)->int:
        n = len(people)
        left,right = 0,n-1
        boats = 0
        while left <= right:
            if people[left] + people[right] <= limit:
                left += 1
            right -= 1
            boats += 1
        return boats

if __name__ == "__main__":
    solution = Solution()
    print(solution.numRescueBoats([1,2],3))