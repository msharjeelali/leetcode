class Solution {
    bool isPresent(string find, string word){
        int wordIndex = 0;
        int findSize = find.size(), wordSize = word.size();
        while(wordIndex <= wordSize - findSize){
            int i = 0, j = wordIndex;
            bool isPresent = true;
            while(i < findSize && j < wordSize && isPresent){
                if(find[i] != word[j])
                    isPresent = false;
                i++, j++;
            }
            if(isPresent)
                return true;
            wordIndex++;
        }
        return false;
    }
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int count = 0;
        for(int i = 0; i < patterns.size(); i++){
            if(isPresent(patterns[i], word)){
                count++;
            }
        }
        return count;
        
    }
};
