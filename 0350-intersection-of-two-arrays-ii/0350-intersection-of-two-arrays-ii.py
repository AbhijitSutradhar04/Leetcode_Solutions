class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        freq = {}
        ans = []

        for x in nums1:
            freq[x] = freq.get(x, 0) + 1

        for x in nums2:
            if freq.get(x, 0) > 0:
                ans.append(x)
                freq[x] -= 1

        return ans