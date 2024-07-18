#include<iostream>
using namespace std;

/*
  @breif: 문자열이 주어지면 중복되지 않는 가장 긴 부분 문자열의 길이를 반환한다.
  @input: string s
  @output: int

  @example:
  input: "abcabcbb"
  output: 3
  explanation: "abc"가 가장 긴 부분 문자열이다.

  문자열의 길이를 저장할 변수 n을 선언한다.
  가장 긴 부분 문자열의 길이를 저장할 변수 ans를 선언한다.
  문자열의 인덱스를 저장할 배열 index를 선언한다.
  i는 부분 문자열의 시작 인덱스, j는 부분 문자열의 끝 인덱스로 초기화한다.
  i는 index[s[j]]와 i 중 큰 값을 저장한다.
  ans는 j-i+1과 ans 중 큰 값을 저장한다.
  index[s[j]]에 j+1을 저장한다.
  ans를 반환한다.

  시간 복잡도: O(n) 
  
*/
class Solution{
  public:
    int lengthOfLongestSubstring(string s){
        int n = s.size(); // 문자열의 길이
        int ans = 0; // 가장 긴 부분 문자열의 길이
        int index[128] = {0}; // 문자열의 인덱스를 저장할 배열
        for(int i=0, j=0; j<n; j++){ // i는 부분 문자열의 시작 인덱스, j는 부분 문자열의 끝 인덱스
            i = max(index[s[j]], i); // 중복된 문자가 나오면 부분 문자열의 시작 인덱스를 중복된 문자의 인덱스로 변경
            ans = max(ans, j-i+1); // 가장 긴 부분 문자열의 길이를 갱신
            index[s[j]] = j+1; // 문자열의 인덱스를 저장
        }
        return ans;
    }
};

int main() {
    Solution c;
    cout << c.lengthOfLongestSubstring("abcabcbb");
    return 0;
}

