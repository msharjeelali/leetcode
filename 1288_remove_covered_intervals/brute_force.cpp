class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
       vector<vector<int>> result;

       for(int i = 0; i < intervals.size(); i++){
        bool isCovered = false;
        for(int j = 0; j < intervals.size() && !isCovered; j++){
            if(i == j){
                continue;
            }
            if(intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]){
                isCovered = true;
            }
        }
        if(!isCovered){
            result.push_back(intervals[i]);
        }
       }
       return result.size();
    }
};
