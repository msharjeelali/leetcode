class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> charFreq;
        int totalCount = 0;
        int size = s.size();

        charFreq['a'] = 0;
        charFreq['b'] = 0;
        charFreq['c'] = 0;
        
        int left = 0, right = 0;

        while(right < size){
            charFreq[s[right]]++;
            while(charFreq['a'] > 0 && charFreq['b'] > 0 && charFreq['c'] > 0){
                totalCount += size - right;
                charFreq[s[left]]--;
                left++;
            }
            right++;
        }

        return totalCount;
    }
};
