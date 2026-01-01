class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1; // we start by adding 1.
        int i = digits.size()-1;

        while(i >= 0 && carry) // till digits didnt end and carry is still propagating.
        {
            digits[i]++; // +1
            carry = digits[i] / 10; // get carry.
            digits[i] %= 10; // digits must hold only the ones place digit.
            i--;
        }

        vector <int> ans; 
        // if carry is there the add 1 to the start of ans.
        if(carry) 
            ans.push_back(1);
        // insert the digits at the end of answer.
        ans.insert(ans.end(), digits.begin(), digits.end()); 

        return ans;
    }
};