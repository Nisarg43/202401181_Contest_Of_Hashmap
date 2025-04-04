class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        vector<int> ans;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]++;
        }
        int s = m.size();
        //let store values of map to vector
        vector<pair<int,int>>v;
        for(auto it = m.begin() ; it != m.end() ; ++it){
            v.push_back({it->second,it->first});
        }
        sort(v.begin(),v.end());                // sort vector

        int start = max(0, (int)v.size() - k);  // Ensure we don't go below 0

        for(int i=v.size()-1 ;  i>=start ; i-- ){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
