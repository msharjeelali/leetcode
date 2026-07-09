class Solution {
    bool runBfs(vector<vector<int>>& graph, int source, int destination){
        vector<int> queue;
        set<int> visited;
        
        queue.push_back(source);
        visited.insert(source);

        while(!queue.empty()){
            int current = queue.front();
            queue.erase(queue.begin());

            if(current == destination){
                return true;
            }

            for(int i = 0; i < graph.size(); i++){
                bool doesPathExist = graph[current][i] == true;
                bool isVisited = visited.find(i) != visited.end();
                if(doesPathExist && !isVisited){
                    queue.push_back(i);
                    visited.insert(current);
                }
            }
        }
        return false;
    } 
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        // 2D matrix that store graph information
        vector<vector<int>> graph(n, vector<int> (n, false));
        graph[0][0] = true;
        for(int i = 1; i < n; i++){
            graph[i][i] = true;
            if(abs(nums[i] - nums[i-1]) <= maxDiff){
                graph[i][i-1] = true;
                graph[i-1][i] = true;
            }
        }
        
        // For each query run a BFS and check if we can get from source to destination
        vector<bool> result;
        for(auto query: queries){
            bool bfsResult = runBfs(graph, query[0], query[1]);
            result.push_back(bfsResult);
        }    
        
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << graph[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return result;
    }
};
