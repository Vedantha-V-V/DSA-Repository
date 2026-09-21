from typing import List

class Solution:
    def largestOverlap(self, img1:List[list[int]],img2:List[list[int]]) -> int:
        n1 = len(img1)
        n2 = len(img2)

        d = dict()

        for i in range(n1):
            for j in range(n1):
                if img1[i][j] == 1:
                    for h in range(n2):
                        for k in range(n2):
                            if img2[h][k] == 1:
                                offset = (i-h,j-k)
                                if offset in d:
                                    d[offset] += 1
                                else:
                                    d[offset] = 1
                
        return max(d.values()) if d else 0


solution = Solution()
print(solution.largestOverlap([[1]],[[1]]))