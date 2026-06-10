import math
import heapq

class SolutionSparseTable:
    def maxTotalValue(self, nums: list[int], k: int) -> int:
        n = len(nums)
        log_n = math.floor(math.log2(n)) + 1
        
        # Build Sparse Table
        stMax = [[0] * log_n for _ in range(n)]
        stMin = [[0] * log_n for _ in range(n)]
        
        for i in range(n):
            stMax[i][0] = nums[i]
            stMin[i][0] = nums[i]
            
        for j in range(1, log_n):
            for i in range(n - (1 << j) + 1):
                stMax[i][j] = max(stMax[i][j-1], stMax[i + (1 << (j-1))][j-1])
                stMin[i][j] = min(stMin[i][j-1], stMin[i + (1 << (j-1))][j-1])
                
        # Fast Log2 Array for O(1) query lookups
        log2_arr = [0] * (n + 1)
        for i in range(2, n + 1):
            log2_arr[i] = log2_arr[i // 2] + 1
            
        def queryMax(L, R):
            j = log2_arr[R - L + 1]
            return max(stMax[L][j], stMax[R - (1 << j) + 1][j])
            
        def queryMin(L, R):
            j = log2_arr[R - L + 1]
            return min(stMin[L][j], stMin[R - (1 << j) + 1][j])
            
        # Max Heap storing (-score, L, R)
        pq = []
        for L in range(n):
            score = queryMax(L, n - 1) - queryMin(L, n - 1)
            heapq.heappush(pq, (-score, L, n - 1))
            
        totalSum = 0
        
        for _ in range(k):
            neg_score, L, R = heapq.heappop(pq)
            totalSum += -neg_score
            
            if R > L:
                newR = R - 1
                newScore = queryMax(L, newR) - queryMin(L, newR)
                heapq.heappush(pq, (-newScore, L, newR))
                
        return totalSum











from collections import deque

class Solution:
    def countSubarrays(self, nums: list[int], X: int) -> int:
        count = 0
        n = len(nums)
        maxDq = deque()
        minDq = deque()
        
        L = 0
        for R in range(n):
            while maxDq and nums[maxDq[-1]] <= nums[R]:
                maxDq.pop()
            maxDq.append(R)
            
            while minDq and nums[minDq[-1]] >= nums[R]:
                minDq.pop()
            minDq.append(R)
            
            while L <= R:
                if maxDq and maxDq[0] < L:
                    maxDq.popleft()
                if minDq and minDq[0] < L:
                    minDq.popleft()
                    
                if nums[maxDq[0]] - nums[minDq[0]] >= X:
                    count += (n - R)
                    L += 1
                else:
                    break
                    
        return count

    def maxTotalValue(self, nums: list[int], k: int) -> int:
        low = 0
        high = int(1e9)
        targetValue = 0
        
        # Binary search to find the exact K-th largest subarray threshold value
        while low <= high:
            mid = low + (high - low) // 2
            if self.countSubarrays(nums, mid) >= k:
                targetValue = mid
                low = mid + 1
            else:
                high = mid - 1
                
        totalSum = 0
        arraysTaken = 0
        n = len(nums)
        L = 0
        
        maxDq = deque()
        minDq = deque()

        # Final pass to calculate exact sum of all subarrays strictly > targetValue
        for R in range(n):
            while maxDq and nums[maxDq[-1]] <= nums[R]:
                maxDq.pop()
            maxDq.append(R)
            
            while minDq and nums[minDq[-1]] >= nums[R]:
                minDq.pop()
            minDq.append(R)
            
            while L <= R:
                if maxDq and maxDq[0] < L:
                    maxDq.popleft()
                if minDq and minDq[0] < L:
                    minDq.popleft()
                    
                if nums[maxDq[0]] - nums[minDq[0]] > targetValue:
                    tempMax = nums[maxDq[0]]
                    tempMin = nums[minDq[0]]
                    
                    # This inner loop runs strictly less than K times over the ENTIRE program
                    for r in range(R, n):
                        tempMax = max(tempMax, nums[r])
                        tempMin = min(tempMin, nums[r])
                        totalSum += (tempMax - tempMin)
                        arraysTaken += 1
                    L += 1
                else:
                    break
                    
        # Fill remaining quota with the exact targetValue
        remainingArrays = k - arraysTaken
        totalSum += (remainingArrays * targetValue)
        
        return totalSum