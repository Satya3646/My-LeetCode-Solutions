class Solution {
public:
    int sumDivisors(int n)
    {
        int cnt = 0;
        int sum = 0;
        int sqrtN = (int)sqrt(n); 
        for(int i = 1; i <= sqrtN; i++)
        {
            if(n % i == 0)
            {
                sum += i;
                cnt++;
                if(n/i != i)
                {
                    sum += n/i;
                    cnt++;
                }
            }
        }
        if(cnt == 4)
            return sum;
        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int &i : nums)
            ans += sumDivisors(i);
        return ans;
    }
};