class Solution:
    def minimumOperations(self,s:str)->int:
        n = len(s)
        sorteds = "".join(sorted(s))
        if s == sorteds:
            return 0
        if n == 2:
            return -1
        minc, maxc = 0,0
        for i,char in enumerate(s):
            if char < s[minc]:
                minc = i
            if char >= s[maxc]:
                maxc = i
        if minc == 0 or maxc == n-1:
            return 1
        if minc == n-1 and maxc == 0:
            return 3
        return 2

if __name__ == "__main__":
    solution = Solution()
    print(solution.minimumOperations("card"))