class Solution {
public:
    bool solve(int ind, int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited, int n, int m, const string& word) {
        // Base case 1: If we have matched all characters in the word
        if (ind == word.length()) {
            return true;
        }
        
        // Base case 2: Check for out of bounds, already visited cells, or character mismatch
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || board[i][j] != word[ind]) {
            return false;
        }
        
        // Mark the current cell as visited
        visited[i][j] = true;
        
        // Explore all 4 neighboring directions (Down, Up, Right, Left)
        bool found = solve(ind + 1, i + 1, j, board, visited, n, m, word) ||
                     solve(ind + 1, i - 1, j, board, visited, n, m, word) ||
                     solve(ind + 1, i, j + 1, board, visited, n, m, word) ||
                     solve(ind + 1, i, j - 1, board, visited, n, m, word);
                     
        // Backtrack: Unmark the current cell so it can be used in other potential paths
        visited[i][j] = false;
        
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        // Fixed the visited array declaration
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the first character matches, start the DFS
                if (board[i][j] == word[0]) {
                    if (solve(0, i, j, board, visited, n, m, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};