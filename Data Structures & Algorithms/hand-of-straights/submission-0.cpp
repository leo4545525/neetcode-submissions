class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
            return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> cnt;
        for(auto val : hand)
        {
            cnt[val]++;
        }
        for(auto val : hand)
        {
            if(cnt[val])
            {
                for(auto i = val; i < val + groupSize; i++)
                {
                    if(!cnt[i]) return false;
                    cnt[i]--;
                }
            }
        }
        return true;
    }
};
