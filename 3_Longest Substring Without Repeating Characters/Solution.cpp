#include <iostream>
// #include <vector>
// #include <algorithm>
#include <string.h>
using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    if (s.size() < 1)
    {
      return 0;
    }
    string::iterator testingHeader = s.begin();
    if (testingHeader == s.end())
    {
      return 1;
    }
    string::iterator longestHeader = s.begin();
    size_t longestSize = 1;
    string::iterator testingTail = testingHeader + 1;
    string::iterator checkIter = testingHeader;

    size_t testingstrSize = 1;
    while (testingTail != s.end())
    {
      while (checkIter != testingTail)
      {
        char c=*checkIter;
        char t =*testingTail;
        if (c == t)
        { //cover
          break;
        }     
        checkIter++;
      }
      if (checkIter != testingTail)
      { //cover
        testingHeader = checkIter + 1;
        testingstrSize = testingTail - testingHeader+1;   
      }
      else
      { //safe
        testingstrSize++;
        if (testingstrSize > longestSize)
        {
          longestSize = testingstrSize;
          longestHeader = testingHeader;
        }
      }
      testingTail++;
      checkIter = testingHeader;
    }
    return longestSize;
  }
};

int main()
{
  cout << "3_LongestSubstring" << endl;
  Solution *test = new Solution();
  string str="bbbbbabcabcbb";
  int result=test->lengthOfLongestSubstring(str);
  cout<<result;
  system("pause");
}