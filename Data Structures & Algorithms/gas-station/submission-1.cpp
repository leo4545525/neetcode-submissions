class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin() , gas.end() , 0) < accumulate(cost.begin() , cost.end() , 0))
            return -1;
        
        int remain = 0, res = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            remain += (gas[i] - cost[i]);
            if(remain < 0)
            {
                remain = 0;
                res = i + 1;
            }
        }
        return res;
    }
};
