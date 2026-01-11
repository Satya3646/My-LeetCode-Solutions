class Solution {
public:
    void NSE(vector <int> &arr, vector <int> &nse)
    {
        stack <int> stk;
        int n = arr.size();

        for(int i = n-1; i >= 0; i--)
        {
            // pop as long as the top is not less that current
            while(!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();
            if(!stk.empty())
                nse[i] = stk.top();
            stk.push(i);
        }
    }

    void PSE(vector <int> &arr, vector <int> &pse)
    {
        stack <int> stk;
        int n = arr.size();

        for(int i = 0; i < n; i++)
        {
            // pop as long as the top is not less that current
            while(!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();
            if(!stk.empty())
                pse[i] = stk.top();
            stk.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        vector <int> nse(n, n);
        vector <int> pse(n, -1);
        NSE(heights, nse);
        PSE(heights, pse);

        int maxRect = 0;
        for(int i = 0; i < n; i++) // current height can be in the range between PSE and NSE.
            maxRect = max(maxRect, (nse[i] - pse[i] - 1) * heights[i]);
        return maxRect;
    }

    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        // prefix vector by adding elements row by row.
        vector <vector <int>> prefix(n, vector <int> (m, 0));

        for(int i = 0; i < m; i++)
            prefix[0][i] = matrix[0][i] - '0';

        for(int i = 1; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] == '1')
                    prefix[i][j] = prefix[i-1][j] + 1;
        
        /* Now each row is like a histogram in which we can find the largest recatangle in the 
        by making a call of largest histogram on each of the row prefix. */
        int maxRect = 0;
        for(int i = 0; i < n; i++)
            maxRect = max(maxRect, largestRectangleArea(prefix[i]));
        return maxRect;
    }
};