class Solution:
    def knightProbability(self,n:int,k:int,row:int,column:int) -> float:
        dp = [[[0.0]*n for _ in range(n)] for _ in range(k+1)]

        for r in range(n):
            for c in range(n):
                dp[0][r][c] = 1.0

            knight_moves = [(-2,-1),(2,1),(2,-1),(-2,1),(-1,-2),(1,2),(-1,2),(1,-2)]

            for moves in range(1,k+1):
                for r in range(n):
                    for c in range(n):
                        for dx,dy in knight_moves:
                            prev_row = r + dx
                            prev_col = r + dy
                            if 0 <= prev_row < n and 0 <= prev_col < n:
                                dp[moves][r][c] += dp[moves-1][prev_row][prev_col]/8.0

        return dp[k][row][column]

solution = Solution()
print(solution.knightProbability(3,2,0,0))