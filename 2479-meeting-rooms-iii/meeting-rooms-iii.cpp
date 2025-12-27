class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); // sort the meetings based on the start times.
        vector <int> used(n, 0);

        // priority_queue to keep the available rooms in order of their numbers (smallest first).
        priority_queue <int, vector <int>, greater <int>> rooms; 
        for(int i = 0; i < n; i++)
            rooms.push(i);
        
        // priority_queue to keep the ongoing meetings, those ending first will be at top.
        priority_queue <pair <long long, int>,
                        vector <pair <long long, int>>,
                        greater <pair <long long, int>>> ongoing;

        for(vector <int> &meeting : meetings)
        {
            int st = meeting[0];
            int en = meeting[1];

            // pop all the meetings that would have ended by the time its the start time of current meeting.
            while(!ongoing.empty() && ongoing.top().first <= st) 
            {
                rooms.push(ongoing.top().second); // push the room to free space since meeting ended.
                ongoing.pop();
            }

            if(!rooms.empty()) // rooms are available.
            {
                ongoing.push({en, rooms.top()}); // push current meeting with smallest free room.
                used[rooms.top()]++; // increment since the meeting has started in the room.
                rooms.pop();
            }
            else // if no rooms are available the take one out of ongoing meeting and skip to its end (waiting time).
            {
                /* the current meeting must be offset by the endtime of ongoing meeting(top) to 
                account for the waiting time, the current meeting will wait till the top meeting
                ends. */
                auto [endTime, room] = ongoing.top();
                ongoing.pop();
                ongoing.push({endTime + (en - st), room}); // the same room is used since its the only room that will become free by ending the top meeting.
                used[room]++;
            }
        }

        // return index of the most used room.
        return max_element(used.begin(), used.end()) - used.begin();
    }
};