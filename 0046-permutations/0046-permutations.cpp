class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        dfs(nums, cur);
        return res;
    }

private:
    void dfs(vector<int>& nums, vector<int>& cur) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(cur.begin(), cur.end(), nums[i]) != cur.end())
                continue;

            cur.push_back(nums[i]);
            dfs(nums, cur);
            cur.pop_back();
        }
    }
};