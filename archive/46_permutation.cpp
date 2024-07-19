#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    void permutation(vector<int>& nums,vector<vector<int>> &ans,int ind){
        // base case
        if(ind == nums.size()){
            ans.push_back(nums); //push the current permutation
            return; // return to the previous call
        }

        // function work
        for(int i = ind; i<nums.size();i++){ // for each element in the array
            swap(nums[ind],nums[i]); // swap the current element with the first element
            permutation(nums,ans,ind+1); // call the function recursively for the next element
            swap(nums[ind],nums[i]); // backtrack to the previous state
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; // store the answer
        permutation(nums,ans,0); // call the recursive function
        return ans; //return the answer 
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int>> answer = s.permute(nums);
    for(auto& a: answer){
        for(auto& b: a){
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}