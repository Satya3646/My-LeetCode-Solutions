const int mod = 1e9+7;

class Solution {
public:
    int numberOfWays(string &corridor)
    {
        int n = corridor.size();
        int cntSeats = 0;
        long long cnt = 0,
                  ans = 1;
        char c = 'S'; // Character indicator.
        int i = 0, j = n-1; // Window pointers.
        while(i < j && corridor[i] != 'S') // Point to the first seat available.
            i++;
        while(j > i && corridor[j] != 'S') // Point to the last seat available.
            j--;
        while(i <= j) // Iterate the window.
        {
            if(corridor[i] == 'S') // Update count of seats.
                cntSeats++;
            if(c == corridor[i]) // if current item is equal to c(indicator) increment count.
                cnt++;
            if(c == 'S' && cnt == 2) // If two seats are captured then a room can be formed with surrounding plants.
            {
                c = 'P'; // Flip the indicator to count the plants now.
                cnt = 0;
            }
            else if(c == 'P' && corridor[i] == 'S') // If plants have ended between previous set of two seats and a new seat is encountered(new room).
            {
                c = 'S'; // Flip the indicator to count seats now.
                ans = (ans % mod * (cnt+1) % mod) % mod;
                cnt = 1; // Update count to 1 since we are already pointing to a seat.
            }
            i++;
        }
        // If seats = 0 or odd number of seats no combination is possible.
        return (cntSeats == 0 || cntSeats & 1)? 0: ans;
    }
};