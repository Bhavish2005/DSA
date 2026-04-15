class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<char, set<int>> mp;
        for (int i = 0; i < 4; i++) {
            mp[s1[i]].insert(i);
        }
        for (int i = 0; i < 4; i++) {
            if (mp.find(s2[i]) == mp.end())
                return false;
            bool ok = false;
            for (auto idx : mp[s2[i]]) {
                if (idx % 2 == i % 2) { 
                    ok = true;
                    mp[s2[i]].erase(idx); 
                    break;
                }
            }
            if (!ok) return false;
        }
        return true;
    }
};
