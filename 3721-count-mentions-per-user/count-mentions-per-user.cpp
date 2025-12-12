class Solution {
public:
    vector <int> countMentions(int n, vector <vector <string>> &events)
    {
        vector <int> mentions(n);
        vector <int> status(n); // Shows if the user is online(-1) or offline.
        // Sort the events based on timestamps, if same timestamps the offline events come first.
        sort(events.begin(), events.end(), [](vector <string> &a, vector <string> &b)
        {
            int ta = stoi(a[1]), tb = stoi(b[1]);
            if(ta == tb) // if 'O' > 'M' returns true.
                return a[0][0] > b[0][0];
            return ta < tb; // if a comes before b return true.
        });
        for(vector <string> &event : events) // Simulate the events.
        {
            int time = stoi(event[1]); // Current time.
            if(event[0][0] == 'M') // MESSAGE event
            {
                if(event[2][0] == 'A') // All are mentioned.
                {
                    for(int &i : mentions)
                        i++;
                }
                else if(event[2][0] == 'H') // Online users are mentioned.
                {
                    for(int i = 0; i < n; i++)
                    {
                        if(time >= status[i]) // if current time >= status[i] the the user will come online for this event henve set his status to onlie and mention him.
                        {
                            // status[i] = -1 case is automatically handled, -1 is the sentinel value we used to have this possible.
                            status[i] = -1;
                            mentions[i]++;
                        }
                    }
                }
                else // User id's are mentioned.
                {
                    stringstream users(event[2]); // Get the id's as string stream.
                    string user;
                    while(users >> user) // Extract each user id one by one.
                        mentions[stoi(user.substr(2))]++;
                }
            }
            else // OFFLINE event
                status[stoi(event[2])] = time + 60; // Set his status to current time + 60.
        }
        return mentions;
    }
};