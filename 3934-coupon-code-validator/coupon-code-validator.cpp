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

    bool validBusinessLine(string &businessLine)
    {
        if(businessLine != "electronics" &&
           businessLine != "grocery" &&
           businessLine != "pharmacy" &&
           businessLine != "restaurant")
            return false;
        return true;
    }

    vector<string> validateCoupons(vector <string> &code, vector <string> &businessLine, vector <bool> &isActive)
    {
        int n = code.size();
        vector <pair <string, string>> validCoupons;
        for(int i = 0; i < n; i++)
        {
            string bl = businessLine[i];
            if(!validCode(code[i]))
                continue;
            if(!validBusinessLine(bl))
                continue;
            if(isActive[i])
                validCoupons.push_back({bl, code[i]});
        }
        sort(validCoupons.begin(), validCoupons.end());
        vector <string> f;
        for(pair <string, string> &p : validCoupons)
            f.push_back(p.second);
        return f;
    }
};