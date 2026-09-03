class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        mn = min((x for x in nums1 if x % 2 == 1), default=None)

        if mn is None:
            return True

        for x in nums1:
            if x % 2 == 0 and x < mn:
                return False

        return True