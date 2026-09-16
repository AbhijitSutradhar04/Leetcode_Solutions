class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int],
                           waterStartTime: List[int], waterDuration: List[int]) -> int:

        ans = float('inf')

        # Land first, then Water
        for i in range(len(landStartTime)):
            land_end = landStartTime[i] + landDuration[i]

            for j in range(len(waterStartTime)):
                start_water = max(land_end, waterStartTime[j])
                finish = start_water + waterDuration[j]
                ans = min(ans, finish)

        # Water first, then Land
        for i in range(len(waterStartTime)):
            water_end = waterStartTime[i] + waterDuration[i]

            for j in range(len(landStartTime)):
                start_land = max(water_end, landStartTime[j])
                finish = start_land + landDuration[j]
                ans = min(ans, finish)

        return ans