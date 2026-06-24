class Solution {
    // Fucntion to check if element is present in the array or not
    bool isPresent(vector<int> nums, int num){
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == num)
                return true;
        }
        return false;
    }
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        
        // Array that contain the result previously processed results
        vector<int> result = nums[0];
        // Array that will contain result of current iteration
        vector<int> temp;
        // Loop through the list of arrays
        for(int i = 1; i < nums.size() && !result.empty(); i++){
            temp.clear();
            // Find intersection of two arrays at a time i.e. result and current
            for(int j = 0; j < result.size(); j++){
                if(isPresent(nums[i], result[j]))
                    temp.push_back(result[j]);
            }
            // Update result
            result = temp;
        }
        // Sort the result
        sort(result.begin(), result.end());
        return result;
        
    }
};
