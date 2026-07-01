class Solution {
    bool doesPathExists(vector<vector<int>> &dist, vector<vector<bool>> &visited, int i, int j, int threshold){
        if(i < 0 || j < 0 || i >= dist.size() || j >= dist.size()){
            return false;
        }

        if(dist[i][j] < threshold || visited[i][j]){
            return false;
        }

        if(i == dist.size() - 1 && j == dist.size() - 1){
            return true;
        }

        visited[i][j] = true;

        return doesPathExists(dist, visited, i - 1, j, threshold)
            || doesPathExists(dist, visited, i + 1, j, threshold)
            || doesPathExists(dist, visited, i, j - 1, threshold)
            || doesPathExists(dist, visited, i, j + 1, threshold);
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int size = grid.size();

        vector<vector<int>> dist(size, vector<int>(size, INT_MAX));

        queue<pair<int,int>> q;

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int directions[4][2] = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(auto &dir : directions){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx >= 0 && ny >= 0 && nx < size && ny < size
                   && dist[nx][ny] == INT_MAX){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        vector<int> distValues;

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                distValues.push_back(dist[i][j]);
            }
        }

        sort(distValues.begin(), distValues.end());
        distValues.erase(unique(distValues.begin(), distValues.end()), distValues.end());

        int low = 0;
        int high = distValues.size() - 1;
        int maxSafeness = 0;

        while(low <= high){
            int mid = (low + high) / 2;

            vector<vector<bool>> visited(size, vector<bool>(size, false));

            if(doesPathExists(dist, visited, 0, 0, distValues[mid])){
                maxSafeness = distValues[mid];
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return maxSafeness;
    }
};
