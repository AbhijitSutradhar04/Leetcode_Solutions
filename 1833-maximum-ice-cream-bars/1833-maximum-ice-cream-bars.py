class Solution:
    def maxIceCream(self, costs: list[int], coins: int) -> int:
        costs.sort()

        count = 0

        for price in costs:
            if coins >= price:
                coins -= price
                count += 1
            else:
                break

        return count