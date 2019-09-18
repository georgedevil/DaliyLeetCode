#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

class Solution
{
  public:
  struct ListNode
  {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

  template <int sz>
  ListNode *createNodeList(int (&arrays)[sz])
  {
    if (sz == 0)
      return nullptr;
    ListNode *result = new Solution::ListNode(arrays[0]);
    ListNode *last = result;
    for (int i = 1; i < sz; i++)
    {
      ListNode *temp = new Solution::ListNode(arrays[i]);
      last->next = temp;
      last = temp;
    }
    return result;
  }
};

int main()
{
  cout << "2_AddTwoNumbers" << endl;
  Solution *test = new Solution();
  int array1[] = {1, 3, 5};
  int array2[] = {2, 4, 6, 8};

  Solution::ListNode *l1 = test->createNodeList(array1);
  Solution::ListNode *l2 = test->createNodeList(array2);
  Solution::ListNode *result = test->addTwoNumbers(l1, l2);

  while (result != nullptr)
  {
    cout << result->val;
    result = result->next;
  }

  system("pause");
}

Solution::ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2)
{
  int carry = 0;
   ListNode *temp = nullptr;
  ListNode *result = l1;
  while (l1 != nullptr || l2 != nullptr)
  {
    int n2 = 0;
    if (l2 != nullptr)
    {
      n2 = l2->val;
      l2 = l2->next;
    }

   

    temp = l1;
    if (l1->next == nullptr&&l2!=nullptr)
    {
      l1->next = new ListNode(0);
    }
    l1 = l1->next;
    temp->val += n2 + carry;
    carry = 0;
    if (temp->val > 9)
    {
      carry = 1;
      temp->val -= 10;
    }
  }
  if(carry>0){
      temp->next = new ListNode(1);
  }
  return result;
}
