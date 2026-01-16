const int mod = 1e9+7;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        unordered_set <int> hGaps, vGaps;
        for(int i : hFences)
            for(int j : hFences)
                if(j != i)
                    hGaps.insert(abs(j - i));
        for(int i : vFences)
            for(int j : vFences)
                if(j != i)
                    vGaps.insert(abs(j - i));
        int maxSide = -1;
        for(int i : hGaps)
            if(vGaps.find(i) != vGaps.end())
                maxSide = max(maxSide, i);
        if(maxSide == -1) 
            return -1;
        return 1LL * maxSide * maxSide % mod;
    }
};