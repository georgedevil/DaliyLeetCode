#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target);
};

int main()
{
  cout << "main()" << endl;
  cout << "1_Two Sum" << endl;
  vector<int> nums = {230, 863, 916, 585, 981, 404, 316, 785, 88, 12, 70, 435, 384, 778, 887, 755, 740, 337, 86, 92, 325, 422, 815, 650, 920, 125, 277, 336, 221, 847, 168, 23, 677, 61, 400, 136, 874, 363, 394, 199, 863, 997, 794, 587, 124, 321, 212, 957, 764, 173, 314, 422, 927, 783, 930, 282, 306, 506, 44, 926, 691, 568, 68, 730, 933, 737, 531, 180, 414, 751, 28, 546, 60, 371, 493, 370, 527, 387, 43, 541, 13, 457, 328, 227, 652, 365, 430, 803, 59, 858, 538, 427, 583, 368, 375, 173, 809, 896, 370, 789};
  int target = 542;
  Solution *test = new Solution();
  vector<int> result = test->twoSum(nums, target);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result.at(i) << endl;
  }
  system("pause");
}

vector<int> Solution::twoSum(vector<int> &nums, int target)
{
  float midelT = target / 2.0;
  int maxnums = nums.size();
  int *lessvec = new int[maxnums]();
  int *morevec = new int[maxnums]();
  int lessveccount = 0;
  int moreveccount = 0;
  vector<int> midelTindexs = {};
  for (int i = 0; i < nums.size(); i++)
  {
    int num = nums.at(i);
    if (num == midelT)
    {
      midelTindexs.push_back(i);
      continue;
    }
    if (num > midelT)
    {
      morevec[moreveccount] = num;
      moreveccount++;
    }
    else
    {
      lessvec[lessveccount] = num;
      lessveccount++;
    }
  }
  if (midelTindexs.size() >= 2)
  {
    if (midelTindexs.size() > 2)
    {
      midelTindexs.erase(midelTindexs.begin() + 2, midelTindexs.end());
    }
    return midelTindexs;
  }

  int *lessArr = new int[lessveccount]();
  memcpy(lessArr, lessvec, lessveccount * sizeof(int));
  delete[] lessvec;

  int *morArr = new int[moreveccount]();
  memcpy(morArr, morevec, moreveccount * sizeof(int));
  delete[] morevec;

  sort(morArr, morArr + moreveccount, [](int &p1, int &p2) {
    return p1 < p2; //升序排列
  });
  sort(lessArr, lessArr + lessveccount, [](int &p1, int &p2) {
    return p1 > p2; //降序排列
  });

  int indexmore = 0;
  int indexless = 0;
  bool Anchorless = true;
  bool lastbigger = true;
  vector<int> indexs = {};
  do
  {
    int value = lessArr[indexless] + morArr[indexmore];
    if (value == target)
    {
      int index0 = -1;
      int index1 = -1;
      for (int i = 0; i < nums.size(); i++)
      {
        int temp = nums.at(i);
        if (temp == lessArr[indexless])
        {
          index0 = i;
          if (index1 != -1)
            break;
        }
        else if (temp == morArr[indexmore])
        {
          index1 = i;
          if (index0 != -1)
            break;
        }
      }
      index0 < index1 ? indexs = {index0, index1} : indexs = {index1, index0};
      break;
    }

    if (value > target)
    {
      if (!lastbigger)
      {
        Anchorless = !Anchorless;
      }
      lastbigger = true;
      if (Anchorless)
      {
        indexmore--;
        if (indexmore < 0)
        {
          Anchorless = !Anchorless;
          indexmore = 0;
          indexless++;
        }
      }
      else
      {
        indexless++;
      }
    }
    else
    {
      if (lastbigger)
      {
        Anchorless = !Anchorless;
      }
      lastbigger = false;

      if (Anchorless)
      {
        indexmore++;
      }
      else
      {
        indexless--;
        if (indexless < 0)
        {
          Anchorless = !Anchorless;
          indexless = 0;
          indexmore++;
        }
      }
    }

    if (indexless >= lessveccount || indexmore >= moreveccount)
    {
      break;
    }

  } while (true);
  delete[] lessArr;
  delete[] morArr;
  return indexs;
}