class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int pop_count = nums.size() - k;
        for(int num: nums)
        {
            pq.push(num);
        }
        while(pop_count--)
        {
            pq.pop();
        }
        return pq.top();
    }
};
