class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int a = 1; a <= n; a++)
        {
            for(int b = 1; b <= n; b++)
            {
                int c = ceil(sqrt(a*a + b*b));
                if(((a*a + b*b) == c*c) && (c <= n))
                {
                    cnt++;
                    // cout << a << ' ' << b << ' ' << c << endl;
                }
            }
        }
        return cnt;
    }
};