class Solution {
public:
    long long getDescentPeriods(vector <int> &prices)
    {
        int n = prices.size();
        long long ans = 0;
        int cnt = 0;
        int i = 0; 
        while(i < n)
        {
            int j = i+1;
            while(j < n && prices[j-1] - prices[j] == 1)
                j++;
            int len = j-i;
            i = j;
            ans += 1LL * len * (len+1) / 2;
        }
        return ans;
    }
};