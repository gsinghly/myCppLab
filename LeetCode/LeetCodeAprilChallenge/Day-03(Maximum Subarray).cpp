// Time:  O(n)
// Space: O(1)
// Kadane algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msf = nums[0], meh = nums[0];
        for(int i = 1; i < nums.size(); i++){
            meh = max(meh+nums[i], nums[i]);
            msf = max(msf, meh);
        }
        return msf;
    }
};

