
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ans = INT_MAX;

        // Land ride first, then water ride
        int earliestLandFinish = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            earliestLandFinish = min(
                earliestLandFinish,
                landStartTime[i] + landDuration[i]
            );
        }

        for (int j = 0; j < waterStartTime.size(); j++) {
            int start = max(earliestLandFinish, waterStartTime[j]);
            ans = min(ans, start + waterDuration[j]);
        }

        // Water ride first, then land ride
        int earliestWaterFinish = INT_MAX;
        for (int j = 0; j < waterStartTime.size(); j++) {
            earliestWaterFinish = min(
                earliestWaterFinish,
                waterStartTime[j] + waterDuration[j]
            );
        }

        for (int i = 0; i < landStartTime.size(); i++) {
            int start = max(earliestWaterFinish, landStartTime[i]);
            ans = min(ans, start + landDuration[i]);
        }

        return ans;
    }
};
