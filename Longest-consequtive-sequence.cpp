class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        sort(v.begin(),v.end());
        vector<int> consecutive;
        int count = 0;
        if(v.size() == 0 ){
            return 0;
        }
        if(v.size() == 1){
            return 1;
        }
        for(int i=0 ; i<v.size()-1 ; i++){
            if( v[i]-v[i+1] == (-1)){
                count++;
            }
            else if( v[i]-v[i+1] != 0 ){            // Dont increases if diff is zero
                consecutive.push_back(count);
                count = 0;
            }
        }
        consecutive.push_back(count);

        sort(consecutive.begin(),consecutive.end());  // sort consecutive array

        int max = consecutive[consecutive.size()-1];  // find max in consecutive 
        

        return max+1;
    }
};
