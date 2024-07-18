#include<iostream>
#include<vector> // Include the vector header
#include<algorithm> // to using merge
using namespace std;

class Solution
{
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int totalLength = nums1.size() + nums2.size();
      vector<int> totalVector;
      totalVector.resize(totalLength);
      std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), totalVector.begin());
      
      //두개의 벡터를 합쳐 중간 값을 알아내야함
      if(totalLength % 2){ //두 벡터 합친 크기가 홀수인 경우
        return totalVector[totalLength/2];
      }
      int med1 = totalVector[totalLength/2-1];
      int med2 = totalVector[totalLength/2];
      
      return (med1 + med2) / 2.0;
    }
};

int main(){
  Solution sol;
  vector<int> a = {1,2};
  vector<int> b = {3,4};

  cout << sol.findMedianSortedArrays(a,b);

  return 0;
}