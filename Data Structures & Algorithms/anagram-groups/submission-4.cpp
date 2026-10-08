class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(auto str:strs)
        {
            string s = str;
            sort(s.begin(), s.end());
            groups[s].push_back(str);
        }
        vector<vector<string>> res;
        for(auto group:groups)
        {
            res.push_back(group.second);
        }
        return res;
    }
};
