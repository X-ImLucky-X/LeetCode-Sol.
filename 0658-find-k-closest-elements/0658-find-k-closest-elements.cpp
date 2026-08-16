class Solution {
private:
    int findi(vector<int>& arr,int k){
        int l=0;
        int r=arr.size()-1;
        int best=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]<=k){
                best=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        if(best==-1) return 0;
        return best;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int mid = findi(arr, x);
        int right = mid + 1;
        int left = mid;

        int n = arr.size();
        // collect k elements (use k as remaining count)
        while ((int)res.size() < k && (left >= 0 || right < n)) {
            if (left < 0) {                 // only right available
                res.push_back(arr[right++]);
            } else if (right >= n) {        // only left available
                res.push_back(arr[left--]);
            } else {
                int dl = abs(arr[left] - x);
                int dr = abs(arr[right] - x);
                if (dl <= dr) {            // tie -> pick left (smaller)
                    res.push_back(arr[left--]);
                } else {
                    res.push_back(arr[right++]);
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};