class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> m;
        for(int i = 0 ; i<s.length() ; i++){
            m[s[i]]++;
        }

        for(int i = 0 ; i<s.length() ; i++){
            if(m[s[i]] < 2){
                return i;
            }
        }
        return -1;
    }
};
