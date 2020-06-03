// Time:  O(n+m)
// Space: O(c), c = 26
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int f[26] = {0};
        for(int i = 0 ; i < ransomNote.size(); i++){
            f[ransomNote[i] - 'a']++;
        }
        for(int i = 0 ; i < magazine.size(); i++){
            f[magazine[i] - 'a']--;
        }
        for(int i = 0 ; i < 26; i++){
            if(f[i] > 0){
                return false;
            }
        }
        return true;
    }
};
