class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
          int temp= grid.size();

        vector<vector<int>> dist(temp, vector<int>(temp, INT_MAX));
        queue<pair<int,int>> q;

        for(int i = 0; i < temp; i++) {
            for(int j = 0; j < temp; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 && nx < temp && ny < temp &&
                   dist[nx][ny] == INT_MAX) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        auto canReach = [&](int safe) {
            if(dist[0][0] < safe) return false;

            queue<pair<int,int>> q;
            vector<vector<int>> vis(temp, vector<int>(temp, 0));

            q.push({0,0});
            vis[0][0] = 1;

            while(!q.empty()) {
                auto [x,y] = q.front();
                q.pop();

                if(x == temp-1 && y == temp-1)
                    return true;

                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx >= 0 && ny >= 0 && nx < temp && ny < temp &&
                       !vis[nx][ny] &&
                       dist[nx][ny] >= safe) {

                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }

            return false;
        };

        int low= 0, high = 2 * temp;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canReach(mid))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
        
    }
};