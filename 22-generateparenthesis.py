import random

class Solution:
    def generateParenthesis(self,n:int)-> list[str]:
        maxsize = 2**(2*n)
        res = []
        patterns = set()
        while len(patterns) < maxsize:
            p = []
            for i in range(2*n):
                p.append(random.choice(["(",")"]))
            s = "".join(p)
            if s not in patterns:
                patterns.add(s)
            stack = []
            isValid = True
            for val in s:
                if val == "(":
                    stack.append(val)
                    continue
                if not stack:
                    isValid = False
                    break
                stack.pop()
            if not stack and isValid and s not in res:
                res.append(s)
        return res


if __name__ == "__main__":
    solution = Solution()
    for parenthesis in solution.generateParenthesis(2):
        print(parenthesis,end=" ")
