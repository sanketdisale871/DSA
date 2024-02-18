class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        vector<int> ans(n, 0);
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        
        // Initialize available rooms
        for (int i = 0; i < n; i++)
        {
            available.push(i);
        }
        
        // Sort meetings based on start time
        sort(meetings.begin(), meetings.end());

        // Iterate through meetings
        for (auto &&meeting : meetings)
        {
            int start = meeting[0], end = meeting[1];

            // Update room availability based on current meeting start time
            while (busy.size() > 0 && busy.top().first <= start)
            {
                available.push(busy.top().second);
                busy.pop();
            }

            // Assign meeting to available room or update busy room
            if (available.size() > 0)
            {
                int top = available.top();
                ans[top]++;
                available.pop(); 
                busy.push({end, top});
            }
            else
            {
                auto top = busy.top();
                int end1 = top.first, index = top.second;

                ans[index]++;
                busy.pop();
                busy.push({top.first + end - start, index});
            }
        }

        // Find the index of the room with the maximum number of meetings
        return max_element(ans.begin(), ans.end()) - ans.begin();
    }
};