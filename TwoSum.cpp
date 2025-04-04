class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int>M;
        // for(int i=0 ; i<nums.size() ; i++){
        //     M[nums[i]] = i;
        // }
        vector<int> ans;

        for(int i = 0; i<nums.size() ; i++){
            int n1  = nums[i];
            int n2  = target-n1;

            if(M.find(n2) != M.end()){
                ans.push_back(i);
                ans.push_back(M[n2]);
                return ans;
            }
            M[n1] = i;
            
        }
        return ans;    
    }
};