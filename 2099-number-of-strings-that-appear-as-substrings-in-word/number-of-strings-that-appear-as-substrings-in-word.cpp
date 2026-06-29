class Solution {
    bool KMP(const string& pattern, const string& word) {
        int m = pattern.size();
        int n = word.size();

        vector<int> pi(m);

        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && pattern[i] != pattern[j])
                j = pi[j - 1];

            if (pattern[i] == pattern[j])
                j++;

            pi[i] = j;
        }

        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && word[i] != pattern[j])
                j = pi[j - 1];

            if (word[i] == pattern[j])
                j++;

            if (j == m)
                return true;
        }

        return false;
    }

public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (const string& pattern : patterns)
            count += KMP(pattern, word);

        return count;
    }
};