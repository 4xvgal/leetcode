#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<vector<int>> answer;
    vector<int> ans;
    vector<bool> isVisited;
    void solve(vector<int>& nums, int& n){
        if(ans.size()==n){
            answer.push_back(ans); //작은 벡터를 큰 벡터에 삽입한다.
            return;
        }
        for(int i=0; i<n; i++){ // 반복문을 돌며 백트래킹을 수행한다.
            if(isVisited[i]) // 이미 방문한 문자면 넘어간다.
                continue;
            ans.push_back(nums[i]); // 방문하지 않은 문자를 방문한 것으로 표시하고 ans에 추가한다.
            isVisited[i]=true; // 방문하지 않은 문자를 방문한 것으로 표시한다.
            solve(nums, n); // 재귀적으로 다음 문자를 찾는다.
            ans.pop_back(); // 다음 문자를 찾은 후에는 ans에서 제거한다.
            isVisited[i]=false; // 방문하지 않은 문자를 방문하지 않은 것으로 표시한다.
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        answer = {};
        ans={};
        int n=nums.size();
        isVisited=vector<bool>(n, false);
        solve(nums, n);
        return answer;        
    }
};