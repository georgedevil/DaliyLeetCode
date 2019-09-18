#Two Sum
##问题
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a 
给你两个表示非负整数的非空链表。整个链表为各位反序的链表节点是一位数的整数数。
single digit. Add the two numbers and return it as a linked list.
相加两个链表， 以链表形式返回和。
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
除0外，输入数链表首部不为0.
##Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

#思路
用例 是链表转数字 数字转链表
从输入输出的结构看，该问题被引向10进制的加法器，反而没有其他什么发散。。。


#效果
Runtime: 20 ms, faster than 87.87% of C++ online submissions for Add Two Numbers.
Memory Usage: 9.8 MB, less than 98.86% of C++ online submissions for Add Two Numbers.