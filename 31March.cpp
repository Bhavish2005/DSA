class Solution {
public:
    string generateString(string str1, string str2) {
        int length = str1.size() + str2.size() - 1;
        int n = str1.size();
        int m = str2.size();
        string word(length, '?');
        vector<bool> fixed(length, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != '?' && word[i + j] != str2[j])
                        return "";

                    word[i + j] = str2[j];
                    fixed[i + j] = true;
                }
            }
        }

        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '?')
                word[i] = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    bool broken = false;
                    for (int j = m - 1; j >= 0; j--) {
                        if (!fixed[i + j]) {
                            word[i + j] = 'b';
                            broken = true;
                            break;
                        }
                    }
                    if (!broken)
                        return "";
                }
            }
        }
        return word;
    }
};
