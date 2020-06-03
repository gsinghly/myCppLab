// Time:  O(logn)
// Space: O(1)

// Forward declaration of isBadVersion API.
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, ans;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(isBadVersion(mid)){
                ans = mid;    //Timus ~ infinite loop problem using (l+r)>>1 ~ Abrupt, prefer storing in ans, or (l < r) with extra added case - BS in a grid - D question solved by bittudalal;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
