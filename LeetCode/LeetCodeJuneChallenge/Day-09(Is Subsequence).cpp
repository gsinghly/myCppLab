// Time:  O(n)
// Space: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        if(s.size() > t.size() || (s.size() == t.size() && s != t)){
            return false;
        }
        for(int i = 0; i < t.size() && j < s.size(); i++){
            if(s[j] == t[i]){
                j++;
            }
        }
        return (j == s.size());
    }
};
