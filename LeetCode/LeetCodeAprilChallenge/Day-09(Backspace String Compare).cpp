// Time - O(n)
// Spcae - O(n)
// Approach 2 - Space O(1) ??
class Solution {
public:
    string backspace(string s){
        string t;
        for(char c : s){
            if(c == '#'){
                if(!t.empty()){
                    t.pop_back();
                }
            }
            else{
                t += c;
            }
        }
        return t;
    }
    bool backspaceCompare(string S, string T) {
        return backspace(S) == backspace(T);   
    }
};
