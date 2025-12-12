class Solution {
public:
    vector <int> countMentions(int n, vector <vector <string>> &events)
    {
        vector <int> mentions(n);
        unordered_map <int, int> offlineUsers;
        offlineUsers.reserve(n);
        sort(events.begin(), events.end(), [](vector <string> &a, vector <string> &b)
        {
            int ta = stoi(a[1]), tb = stoi(b[1]);
            if(ta == tb)
                return a[0][0] > b[0][0];
            return ta < tb;
        });
        for(vector <string> &event : events)
        {
            int time = stoi(event[1]);
            if(event[0][0] == 'M')
            {
                if(event[2][0] == 'A')
                {
                    for(int &i : mentions)
                        i++;
                }
                else if(event[2][0] == 'H')
                {
                    for(int i = 0; i < n; i++)
                    {
                        bool online = true;
                        auto it = offlineUsers.find(i);
                        if(it != offlineUsers.end())
                        {
                            if(time >= it->second)
                                offlineUsers.erase(it);
                            else
                                online = false;
                        }
                        if(online)
                            mentions[i]++;
                    }
                }
                else
                {
                    stringstream users(event[2]);
                    string user;
                    while(users >> user)
                        mentions[stoi(user.substr(2))]++;
                }
            }
            else
            {
                offlineUsers[stoi(event[2])] = time + 60;
            }
        }
        return mentions;
    }
};