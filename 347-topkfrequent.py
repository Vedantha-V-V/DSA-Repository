from collections import Counter

class Solution:
    def topKFrequent(self,nums:list,k:int) -> list:
        d = Counter(nums)
        arr = []
        for key,value in d.items():
            arr.append((key,value))
        arr.sort(key=lambda x:x[1],reverse=True)
        res = []
        for i in range(k):
            res.append(arr[i][0])
        return res

solution = Solution()
print(solution.topKFrequent([1,1,1,2,3],2))