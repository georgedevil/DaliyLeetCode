# Longest Substring Without Repeating Characters
***
## 问题
Given a string, find the length of the longest substring without repeating characters.
给定字符串，找出最长的无重复字符的子串。
## Example:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
## 思路
遍历。。
然后节约遍历。。
当发现重复的时候新子串头部从重复节点后一个开始，子串尾部增一

## 效果
Runtime: 4 ms, faster than 99.37% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 9.2 MB, less than 91.54% of C++ online submissions for Longest Substring Without Repeating Characters.
比较字符是否一致时用*iter直接比较 ：节约了memory 增加了runtime....虽然逻辑相同
Runtime: 8 ms, faster than 94.38% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 9.1 MB, less than 97.01% of C++ online submissions for Longest Substring Without Repeating Characters.