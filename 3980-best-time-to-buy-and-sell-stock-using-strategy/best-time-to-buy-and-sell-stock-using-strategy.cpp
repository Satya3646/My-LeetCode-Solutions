class Solution {
public:
    long long maxProfit(vector <int> &prices, vector<int> &strategy, int k) {
        int n = prices.size();
        // prefix of new profit till day.
        vector <long long> prefix(n);
        // prefix of prices till day.
        vector <long long> prefixPrices(n);
        prefix[0] = prices[0] * strategy[0];
        prefixPrices[0] = prices[0];
        for(int i = 1; i < n; i++) // generate the prefix values.
        {
            prefix[i] = prices[i] * strategy[i] + prefix[i-1];
            prefixPrices[i] = prefixPrices[i-1] + prices[i];
        }
        long long baseProfit = prefix[n-1];
        long long maxVal = baseProfit;
        int i = 0, j = k-1; // place the initial window.
        while(j < n)
        {
            maxVal = max(maxVal, baseProfit
                                 - (prefix[j] - (i == 0? 0: prefix[i-1])) // subtract the current window from base profit.
                                 + (prefixPrices[j] - prefixPrices[j - k/2])); // add the new window profit to base profit.
            i++; 
            j++;
        }
        return maxVal;
    }
};