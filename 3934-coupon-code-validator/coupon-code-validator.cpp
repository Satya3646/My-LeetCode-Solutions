class Solution {
public:
    bool validCode(string &code)
    {
        if(code.size() == 0)
            return false;
        for(char &c : code)
            if(!isalnum(c) && (c != '_'))
                return false;
        return true;
    }

    vector<string> validateCoupons(vector <string> &code, vector <string> &businessLine, vector <bool> &isActive)
    {
        int n = code.size();
        vector <string> bkt1, bkt2, bkt3, bkt4;
        for(int i = 0; i < n; i++)
        {
            string bl = businessLine[i];
            if(!validCode(code[i]))
                continue;
            if(isActive[i])
            {
                if(bl == "electronics")
                    bkt1.push_back(code[i]);
                else if(bl == "grocery")
                    bkt2.push_back(code[i]);
                else if(bl == "pharmacy")
                    bkt3.push_back(code[i]);
                else if(bl == "restaurant")
                    bkt4.push_back(code[i]);
            }
        }
        sort(bkt1.begin(), bkt1.end());
        sort(bkt2.begin(), bkt2.end());
        sort(bkt3.begin(), bkt3.end());
        sort(bkt4.begin(), bkt4.end());
        vector <string> validCoupons;
        validCoupons.insert(validCoupons.end(), bkt1.begin(), bkt1.end());
        validCoupons.insert(validCoupons.end(), bkt2.begin(), bkt2.end());
        validCoupons.insert(validCoupons.end(), bkt3.begin(), bkt3.end());
        validCoupons.insert(validCoupons.end(), bkt4.begin(), bkt4.end());
        return validCoupons;
    }
};