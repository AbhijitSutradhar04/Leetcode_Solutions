class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        ans = []

        for hour in range(12):
            for minute in range(60):
                if (hour.bit_count() + minute.bit_count()) == turnedOn:
                    ans.append(f"{hour}:{minute:02d}")

        return ans