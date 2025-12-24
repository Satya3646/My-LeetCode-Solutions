class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int apples = accumulate(apple.begin(), apple.end(), 0);
        int boxes = 0;
        for(int i : capacity)
        {
            if(apples > 0)
            {
                boxes++;
                apples -= i;
            }
            else
                break;
        }
        return boxes;
    }
};