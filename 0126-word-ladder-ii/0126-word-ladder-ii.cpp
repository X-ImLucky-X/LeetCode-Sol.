class Solution {
public:
    unordered_map<string, vector<string>> parent;
    unordered_map<string, int> level;
    vector<vector<string>> ans;

    void dfs(string word, string begin, vector<string>& path) {
        if (word == begin) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (string &p : parent[word]) {
            path.push_back(p);
            dfs(p, begin, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return {};

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            for (int i = 0; i < word.size(); i++) {
                string next = word;

                for (char c = 'a'; c <= 'z'; c++) {
                    next[i] = c;

                    if (!st.count(next)) continue;

                    if (!level.count(next)) {
                        level[next] = level[word] + 1;
                        parent[next].push_back(word);
                        q.push(next);
                    }
                    else if (level[next] == level[word] + 1) {
                        parent[next].push_back(word);
                    }
                }
            }
        }

        if (!level.count(endWord)) return {};

        vector<string> path = {endWord};
        dfs(endWord, beginWord, path);

        return ans;
    }
};