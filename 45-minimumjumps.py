class Solution:
    def minimumJumps(self,arr:list) -> int:
        n = len(arr)
        if arr[0] == 0:
            return -1
        maxReach = 0
        currReach = 0
        jump = 0
        for i in range(n):
            maxReach = max(maxReach,i+arr[i])
            if maxReach >= n-1:
                return jump+1
            if i == currReach:
                if i == maxReach:
                    return -1
                else:
                    jump+=1
                    currReach = maxReach
        return -1

if __name__ == "__main__":
    solution = Solution()
    arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
    print(solution.minimumJumps(arr))