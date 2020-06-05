// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.cbegin(), nums.cend(), 0, std::bit_xor<int>()); //O(n) since accumulate internal, rep(i, n) ans ^= nums[i];
    }
};
