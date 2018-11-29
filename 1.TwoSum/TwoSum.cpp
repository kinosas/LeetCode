class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int i=0, j=nums.size()-1;
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
                    
        while(i < j){
            if(tmp[i]+tmp[j] < target){
                i++;
            }
            else if(tmp[i]+tmp[j] == target){
                int x=0;
                int p,q;
                while(x < nums.size())
                    if(nums[x] == tmp[i]){
                        p = x;
                        break;
                    }
                    else{
                        x++;
                    }
                x = nums.size()-1;
                while(x >= 0)
                    if(nums[x] == tmp[j]){
                        q = x;
                        break;
                    }
                    else{
                        x--;
                    }
                ret.push_back(p<q?p:q);
                ret.push_back(p>q?p:q);
                return ret;
            }
            else{
                j--;
            }
        }
    }
};