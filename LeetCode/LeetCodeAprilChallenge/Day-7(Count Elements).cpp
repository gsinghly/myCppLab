// Time:  O(n)
// Space: O(n) for set or maybe ~O(nlogn) due to count ??
// Another approach - O(nlogn) time, O(1) space -- sorting and comapring prev with curr
class Solution {
public:
    int countElements(vector<int>& nums) {
		set < int > s;
        for(int i : nums){
			s.emplace(i);
		}
		int ans = 0;
		for(int i : nums){
			if(s.count(i+1) == 1){
				ans++;
			}
		}
		return ans;
    }
};
