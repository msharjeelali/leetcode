class Solution {
    // Fucntion to check if element is present in the array or not
    bool binarySearch(vector<int> &nums, int start, int end, int num){
        if(start > end){
            return false;
        }
        int mid = (start + end) / 2;
        if(nums[mid] == num){
            return true;
        }
        else if(nums[mid] < num){
            return binarySearch(nums, mid + 1, end, num);
        }
        else {
            return binarySearch(nums, start, mid - 1, num);
        }
    }
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        
        // Sort the entire list of arrays
        for(auto &row:nums){
            sort(row.begin(), row.end());
        }

        // Array that contain the result previously processed results
        vector<int> result = nums[0];
        // Array that will contain result of current iteration
        vector<int> temp;
        // Loop through the list of arrays
        for(int i = 1; i < nums.size() && !result.empty(); i++){
            temp.clear();
            // Find intersection of two arrays at a time i.e. result and current
            for(int j = 0; j < result.size(); j++){
                if(binarySearch(nums[i], 0, nums[i].size() - 1, result[j]))
                    temp.push_back(result[j]);
            }
            // Update result
            result = temp;
        }
        return result;
    }
};
