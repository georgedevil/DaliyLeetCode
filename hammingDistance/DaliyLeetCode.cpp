// DaliyLeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include<stdio.h>
#include<conio.h>
using namespace std;
int hammingDistance(int x, int y) {
	int m = x^y;
	int r = 0;
	while (m != 0)
	{
		//(m&1==1)
		r++;

		//  m = m>>1;
		m = m&(m - 1);
	}

	return r;
}
int main()
{
	int result = hammingDistance(1,4);
	cout << result << endl;
	system("PAUSE ");
    return 0;
}

