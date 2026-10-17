class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair<int, vector<int>>> pq;
        for(vector<int> p :points)
        {
            int x = p[0];
            int y = p[1];
            int dis = x * x + y * y;
            pq.push({dis, p});

            if(pq.size() > k)
            {
                pq.pop();
            }
            
        }
        vector<vector<int>> res;
        while(pq.size())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
