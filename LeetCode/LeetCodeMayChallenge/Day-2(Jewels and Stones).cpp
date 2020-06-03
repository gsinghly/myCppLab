// Time:  O(n*m) - find is almost linear in implementation i guess. 
// Space: O(1)  - KMP can be used to make time O(n+m) but space O(n) due to lps vector.
// Approach1
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int c = 0;
        for(int i = 0 ; i < S.size(); i++){
            if(J.find(S[i]) != string:: npos){
                c++;
            }
        }
        return c;
    }
};


// Time:  O(m + n)
// Space: O(n) - Space time complexity trade off from above approach
// Approach2
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> us;
        for (const auto& j : J) {
            us.emplace(j);
        }
        int result = 0;
        for (const auto& s : S) {
            result += us.count(s);
        }
        return result;
    }
};

