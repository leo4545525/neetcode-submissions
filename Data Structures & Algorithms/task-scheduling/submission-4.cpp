// Max Heap 選目前剩最多次的 task；
// Cooldown Queue 保存暫時不能執行的 task。
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        // 1. 統計每種 task 出現次數
        unordered_map<char, int> tmp;
        for (auto task : tasks)
        {
            tmp[task]++;
        }

        // 2. Max Heap：存目前可以執行的 task 剩餘次數
        //    每次優先執行剩餘次數最多的 task
        priority_queue<int> pq;
        for (auto t : tmp)
        {
            pq.push(t.second);
        }

        // 3. Cooldown Queue：
        //    {剩餘次數, 可以重新執行的時間}
        queue<pair<int, int>> cooldown;

        int time = 0;

        // Heap 和 cooldown 都空才代表所有 task 都完成
        while (!pq.empty() || !cooldown.empty())
        {
            // 4. 先把 cooldown 已結束的 task 放回 Heap
            //    ready time <= 現在時間，代表這一秒已經可以執行
            if (!cooldown.empty() &&
                cooldown.front().second <= time)
            {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }

            // 5. Heap 有 task，就執行目前剩餘次數最多的
            if (!pq.empty())
            {
                int cnt = pq.top();
                pq.pop();

                cnt--;  // 執行一次

                // 如果還沒做完，進入 cooldown
                // time + n + 1 = 下一次最早可執行時間
                if (cnt > 0)
                {
                    cooldown.push({cnt, time + n + 1});
                }
            }

            // Heap 為空時，這一秒自然就是 idle
            time++;
        }

        return time;
    }
};
