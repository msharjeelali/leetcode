class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        // Array to have frequency of each element
        vector<int> frequency(1000);
        // Iterate over the list of arrays and track frequency
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                frequency[nums[i][j] - 1]++;
            }
        }

        vector<int> result;
        for(int i = 0; i < frequency.size(); i++){
            // If frequency equals count of arrays that means it is present in all
            if(frequency[i] == nums.size()){
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
