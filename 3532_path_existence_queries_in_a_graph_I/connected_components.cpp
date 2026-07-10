class Solution { 
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        // 2D matrix that store graph information
        int flag = 1;
        vector<int> graph(n,0);
        graph[0] = flag;
        for(int i = 1; i < n; i++){
            if(abs(nums[i] - nums[i-1]) <= maxDiff){
                graph[i] = flag;
                graph[i-1] = flag;
            } else {
                flag++;
            }
            graph[i] = flag;
        }
        
        // For each query run a BFS and check if we can get from source to destination
        vector<bool> result;
        for(auto query: queries){
            result.push_back(graph[query[0]] == graph[query[1]] && graph[query[0]] != 0);
        }    
        
        return result;
    }
};
