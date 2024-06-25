//2. add tow numbers leet code

#include <iostream>

using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
@breif
  두개의 링크드 리스트를 받아 더한 값을 반환한다.
@param
  ListNode *l1 : 첫번째 링크드 리스트
  ListNode *l2 : 두번째 링크드 리스트
@return
  ListNode* : 두 링크드 리스트를 더한 값
결과 값 리스트를 생성한다.
헤드 포인터를 저장한다.
carry 변수를 0으로 초기화한다.
l1, l2가 nullptr이 아닐때까지 반복한다.
  sum 변수를 0으로 초기화한다.
  l1이 nullptr이 아닐때 sum에 l1의 값을 더하고 l1을 다음 노드로 이동한다.
  l2가 nullptr이 아닐때 sum에 l2의 값을 더하고 l2를 다음 노드로 이동한다.
  sum에 carry를 더한다.
  carry에 sum을 10으로 나눈 값을 저장한다.
  result의 다음 노드에 sum을 10으로 나눈 나머지 값을 저장한다.
  result를 다음 노드로 이동한다.
*/

class Solution{
  public:
  ListNode* addTwoNumbers(ListNode *l1, ListNode* l2){
    ListNode *result = new ListNode();
    ListNode *head = result;
    int carry = 0;

    while(l1 != nullptr || l2 != nullptr){
      int sum = 0;
      if(l1 != nullptr){
        sum += l1->val;
        l1 = l1->next;
      }
      if(l2 != nullptr){
        sum += l2->val;
        l2 = l2->next;
      }
      sum += carry;
      carry = sum / 10;
      result->next = new ListNode(sum % 10); // 나머지 값 저장
      result = result->next;
    }
    if(carry > 0){
      result->next = new ListNode(carry); // carry가 남아있을 경우 저장
    }
    return head->next;
  }
};

int main(){
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  Solution s;
  ListNode *result = s.addTwoNumbers(l1, l2);

  while(result != nullptr){
    cout << result->val << " ";
    result = result->next;
  }
  cout << endl;
  return 0;
}