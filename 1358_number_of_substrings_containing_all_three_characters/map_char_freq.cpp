class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> charFreq;
        int totalCount = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            charFreq['a'] = 0;
            charFreq['b'] = 0;
            charFreq['c'] = 0;

            charFreq[s[i]]++;
            for(int j = i + 1; j < s.size(); j++){
                charFreq[s[j]]++;
                if(charFreq['a'] > 0  && charFreq['b'] > 0 && charFreq['c'] > 0){
                    totalCount++;
                }
            }
        }

        return totalCount;
    }
};
