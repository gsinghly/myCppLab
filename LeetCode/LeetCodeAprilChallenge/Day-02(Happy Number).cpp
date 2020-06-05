// Time:  O(m) 
// Space: O(m), m = No. of steps required for n to be a happy number

class Solution {
public:
    bool isHappy(int n) {
        unordered_map < int, int > mpp;
        while(1){
            string s = to_string(n);
            if(mpp[n] == 1){
                return false;
            }
            mpp[n] = 1;
            int c = 0;
            for(int i = 0 ; i < s.size(); i++){
                c += ((s[i] - '0')*(s[i]- '0'));
            }
            if(c == 1){
                return true;
            }
            n = c;
        }
    }
};
