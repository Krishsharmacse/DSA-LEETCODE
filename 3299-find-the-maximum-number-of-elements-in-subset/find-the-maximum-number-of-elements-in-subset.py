class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        count = {}

        for num in nums:
            count[num] = count.get(num, 0) + 1

        ans = 1

        if 1 in count:
            ones = count[1]
            if ones % 2 == 0:
                ones -= 1
            ans = max(ans, ones)

        LIMIT = 10**15

        for x in count:
            if x == 1:
                continue

            curr_len = 0
            curr = x

            while curr <= LIMIT and count.get(curr, 0) >= 2:
                curr_len += 2
                curr *= curr

            if curr <= LIMIT and count.get(curr, 0) > 0:
                curr_len += 1
            else:
                curr_len -= 1

            ans = max(ans, curr_len)

        return ans