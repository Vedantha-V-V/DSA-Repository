class Solution:
    def reverseParentheses(self,s:str)->str:
        n = len(s)
        stack = []
        queue = []
        for i in range(n):
            if s[i] != ")":
                stack.append(s[i])
            else:
                val = stack.pop()
                while len(stack) > 0 and val != "(":
                    queue.append(val)
                    val = stack.pop()
                if len(stack) == 0 and i == n-1:
                    return "".join(queue)
                while len(queue) > 0:
                    stack.append(queue.pop(0))
        return "".join(stack)

if __name__ == "__main__":
    solution = Solution()
    print(solution.reverseParentheses("(u(love)i)"))