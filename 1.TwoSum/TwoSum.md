Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].


其实吧，这道题很简单啦，但是是第一道题，主要是熟悉一下LeetCode的模式啦，只要在代码框架中填充自己算法代码，返回就好了。


如果是从小到大有序排列的列表其实这样写就好了

    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> ret;
            int i=0, j=nums.size()-1;
            while(i < j){
                if(nums[i]+nums[j] < target){
                    i++;
                }
                else if(nums[i]+nums[j] == target){
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
                else{
                    j--;
                }
            }
        }
    };

假如使用递归，这样会超时

    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> ret;
            int i=0, j=nums.size()-1;
            func(nums,ret,i,j,target);
            return ret;
        }
        void func(vector<int>& nums, vector<int> &ret, int i, int j, int target){
            if(i < j){
                if(nums[i]+nums[j] == target){
                    if(ret.size()==0){
                        ret.push_back(i);
                        ret.push_back(j);
                    }
                    return;
                }
                func(nums,ret,i+1,j,target);
                func(nums,ret,i,j-1,target);
            }
        }
    };

假如使用两重循环，复杂度是平方级别:

    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> ret;
            int len=nums.size();
            int i,j;
            for(i=0;i<len-1;i++){
                for(j=i+1;j<len;j++){
                    if(nums[i]+nums[j]==target){
                        ret.push_back(i);
                        ret.push_back(j);
                        return ret;
                    }
                }
            }
        }
    };

结果是

    Runtime: 76 ms, faster than 39.33% of C++ online submissions for Two Sum.

最后采用了排序和第一种方案结合，因为vector的排序本身被优化过，加上两次查找都是 O(nlog2n+n+n+n) = O(nlog2n)，代码如下：

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

最后最好的结果是：

    Runtime: 8 ms, faster than 69.26% of C++ online submissions for Two Sum.

还有哈希表的做法，下次补充