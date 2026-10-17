class KthLargest {
public:
    //Heap 裡永遠只留最大的 K 個，所以 Min Heap 的 top() 就是第 K 大。
    priority_queue<int, vector<int>, greater<int>> pq; //min_heap
    int k;

    KthLargest(int k, vector<int>& nums) {  
        this -> k = k;
        for(int num: nums)
        {
            pq.push(num);
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k)
        {
            pq.pop();
        }
        return pq.top();
    }
};
