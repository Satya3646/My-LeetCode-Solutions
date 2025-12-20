const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    void solve(vector <vector <char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        queue <pair <int, int>> q;

        /*
        1) Put all the zeros on the boundary into the queue while marking them as visited.
        2) Since the board is a character board we can just use a sentinel character (#) to mark visited without needing an explicit visited array.
        3) Now we can do BFS traversal from these boundary zeros marking all their adjacent zeors as '#'.
        4) At the end the remaining zeros are the surrounded zeros which we will mark as 'X' and all the '#' are zeros, restore the board by changing '#' to 'O'.
        */

        // Put all the zeros on left and right boundary into queue and mark them as visited using a different character (#).
        for(int i = 0; i < m; i++) 
        {
            if(board[i][0] == 'O')
                board[i][0] = '#',
                q.push({i, 0});
            if(board[i][n-1] == 'O')
                board[i][n-1] = '#', 
                q.push({i, n-1});
        }

        // Put all the zeros on top and bottom boundary into queue and mark them as visited using a different character (#).
        for(int i = 0; i < n; i++)
        {
            if(board[0][i] == 'O')  
                board[0][i] = '#', 
                q.push({0, i});
            if(board[m-1][i] == 'O')
                board[m-1][i] = '#', 
                q.push({m-1, i});
        }

        while(!q.empty())
        {
            int qs = q.size();
            for(int i = 0; i < qs; i++)
            {
                auto [x, y] = q.front(); // Unpack the coordinates.
                q.pop();
                for(int j = 0; j < 4; j++) // Iterate the adjacents.
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(0 <= nx && nx < m && 0 <= ny && ny < n && board[nx][ny] == 'O') // if this is zero that is adjacent to a boundary zero the marks this a visited using '#'.
                        board[nx][ny] = '#', 
                        q.push({nx, ny});
                }
            }
        }

        // After the traversal completed all the zeros left are the surrounded zeros (not connected to any boundary), so we can marks the as 'X', at the same time we can restore the boundary connected zeros we marked earlier.
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};