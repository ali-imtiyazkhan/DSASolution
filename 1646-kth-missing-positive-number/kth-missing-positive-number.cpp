class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int curr = 1;
        int i = 0;
        
        while(k > 0) {
            if(i < arr.size() && arr[i] == curr) {
                i++; 
            } else {
                k--;
                if(k == 0) return curr;
            }
            curr++;
        }
        
        return curr;
    }
};