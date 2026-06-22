class Solution {
public:
    vector<int> arr;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        res(0,c,target);

        return ans;
    }
    void res(int i,vector<int>& c, int t){
        if(i == c.size() || t < 0){
            return;
        }
        if(t == 0) {
            ans.push_back(arr);
            return;
        }

        //pick i
        arr.push_back(c[i]);
        res(i, c, t-c[i]);

        //not choose i
        arr.pop_back();
        res(i+1,c,t);
    }
};

