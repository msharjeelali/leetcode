class Solution {
    bool hasAllThree(string s, int i, int j){
        bool isA = false;
        bool isB = false;
        bool isC = false;

        for(int k = i; k <= j; k++){
            if(s[k] == 'a'){
                isA = true;
            } else if (s[k] == 'b'){
                isB = true;
            } else if(s[k] == 'c'){
                isC = true;
            }
        }

        return isA && isB && isC;
    }
public:
    int numberOfSubstrings(string s) {

        int totalCount = 0;
        
        for(int i = 0; i < s.size(); i++){
            for(int j = i + 1; j < s.size(); j++){
                if(hasAllThree(s, i , j)){
                    totalCount++;
                }
            }
        }

        return totalCount;
    }
};
