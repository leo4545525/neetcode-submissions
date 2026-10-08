#define a_z 26
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> bundle;
        
        for(auto s:strs)
        {
            string key = "";
            vector<int> cnt(a_z);
            for(char c:s)
            {
                cnt[c - 'a']++;
            }

            for(int i = 0; i < a_z; i++)
            {
                if(i==0) key += to_string(cnt[i]);
                else     key += ',' + to_string(cnt[i]);
            }
            bundle[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto pair:bundle)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};
