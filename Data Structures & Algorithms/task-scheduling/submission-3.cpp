class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> tmp;
        priority_queue<int> pq;
        for(auto task:tasks)
        {
            tmp[task]++;
        }
        for(auto t:tmp)
        {
            pq.push(t.second);
        }
        queue<pair<int, int>> cooldown;  // {剩餘次數, 可以重新執行的時間}
        int time = 0;
        while(!pq.empty() || !cooldown.empty())
        {
            if(!cooldown.empty() && cooldown.front().second <= time)
            {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
            if(!pq.empty())
            {
                int cnt = pq.top();
                pq.pop();
                if(--cnt)
                {
                    cooldown.push({cnt, time + n + 1});
                }
            }
            time++;
        }
        return time;
    }
};
