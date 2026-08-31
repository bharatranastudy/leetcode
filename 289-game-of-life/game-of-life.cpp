class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int live = 0;

                // Check all 8 neighbors
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {

                        if (di == 0 && dj == 0)
                            continue;

                        int ni = i + di;
                        int nj = j + dj;

                        if (ni >= 0 && ni < m &&
                            nj >= 0 && nj < n &&
                            abs(board[ni][nj]) == 1) {
                            live++;
                        }
                    }
                }

                // Live cell
                if (board[i][j] == 1) {

                    if (live < 2 || live > 3) {
                        board[i][j] = -1;
                    }
                }

                // Dead cell
                else if (board[i][j] == 0) {

                    if (live == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }

        // Convert temporary states to final states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == -1)
                    board[i][j] = 0;

                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};