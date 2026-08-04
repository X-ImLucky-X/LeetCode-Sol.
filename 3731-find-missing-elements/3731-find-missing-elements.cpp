class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start=nums.front();
        int end=nums.back();
        vector<int> res;
        unordered_set<int> temp(nums.begin(),nums.end());
        for(int i=start;i<=end;i++){
            if(temp.find(i)==temp.end()){
                res.push_back(i);
            }
        }
        return res;
    }
};