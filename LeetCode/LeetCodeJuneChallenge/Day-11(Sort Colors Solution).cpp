// Time:  O(n) with only 1 trraversal
// 2 traversal approach - count 0, 1, 2 and fill array in the next traversal
// Space: O(1)

class Solution {
public:
    void sortColors(vector<int>& a) {
        int l = 0, mid = 0, r = a.size()-1;
        while(mid <= r){
            if(a[mid] == 0){
                swap(a[l++], a[mid++]);
            }
            else if(a[mid] == 1){
                mid++;
            }
            else{
                swap(a[mid], a[r--]);
            }
        }
    }
};
