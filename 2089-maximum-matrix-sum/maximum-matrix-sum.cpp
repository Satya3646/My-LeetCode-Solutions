class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int cntNeg = 0;
        int minVal = INT_MAX;
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] < 0)
                    cntNeg++;
                sum += abs(matrix[i][j]);
                minVal = min(minVal, abs(matrix[i][j]));
            }
        }
        if(cntNeg & 1)
            return sum - 2*minVal;
        return sum;
    }
};