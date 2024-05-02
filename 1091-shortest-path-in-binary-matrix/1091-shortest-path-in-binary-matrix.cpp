class Solution {
public:
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
        return -1;
    }
    if(n-1 == 0){
        return 1;
    }
    
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    
    queue<pair<pair<int, int>, int>> q; // (coordinates, distance)
    q.push({{0, 0}, 1}); // Starting node (row, column), distance from source
    grid[0][0] = 1; // Mark as visited
    
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int distance = q.front().second;
        q.pop();
        
        if (row == n - 1 && col == n - 1) {
            return distance;
        }
        
        for (const auto& dir : directions) {
            int new_row = row + dir.first;
            int new_col = col + dir.second;
            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < n && grid[new_row][new_col] == 0) {
                grid[new_row][new_col] = 1;
                q.push({{new_row, new_col}, distance + 1});
            }
        }
    }
    
    return -1;
}
};
