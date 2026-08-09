class Solution:
    def maxProfit(self, nums: List[int]) -> int:
      n=len(nums)
      profit=0
      buy=0
      maxi=0
      mini=nums[0]
      for i in range(0,n):
        mini=min(mini,nums[i])
        profit=nums[i]-mini
        maxi=max(maxi,profit)
      return maxi


        