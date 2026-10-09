class Solution:
    def minimumInsertions(self,s:str) -> int:
        n = len(s)
        stack = []
        res = 0
        i = 0
        while i < n:
            if s[i] == "(":
                stack.append(s[i])
            elif i == n-1:
                if stack:
                    stack.pop()
                    res+=1
                else:
                    res+=2
            else:
                if s[i+1] == ")":
                    if stack:
                        stack.pop()
                    else:
                        res += 1
                    i+=1
                else:
                    if stack:
                        stack.pop()
                        res += 1
                    else:
                        res += 2
            i += 1
        res += (2*len(stack))
        return res

if __name__ == "__main__":
    solution = Solution()
    print(solution.minimumInsertions("))())("))
