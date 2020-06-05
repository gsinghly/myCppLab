// Time:  O(n)
// Space: O(1) -- using map O(n) space, unordered_map O(n) space & maybe using set O(n) space + O(nlogn) time
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                nums[j++] = nums[i];
            }
        }
        for(int i = j; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};
