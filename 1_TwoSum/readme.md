#Two Sum
##问题
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
给定一个整型数组，返回 两个数组成员的下标 要求两数组成员相加等于指定值

You may assume that each input would have exactly one solution, and you may not use the same element twice.
你可以假定每个指定值只有一个解，同时你也不该把同一个元素用两次
##Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].


#思路
##基础二重遍历
流程图
```flow
st=>start: index1=0
op2init=>operation: index2=0
condIndexsame=>condition: index1==index2
op2add=>operation: index2++
end=>end: 输出 index1,index2
condCheckTarget=>condition: [index1]+[index2]==target
condCheckindex2=>condition: index2>Max
op1add=>operation: index1++

st->op2init->condIndexsame
condIndexsame(yes)->op2add
condIndexsame(no)->condCheckTarget
op2add->condCheckindex2
condCheckindex2(yes)->op1add
condCheckindex2(no)->condIndexsame
op1add->op2init
condCheckTarget(yes)->end
condCheckTarget(no)->op2add
```

##遍历前裁剪
* ~~数组去除 直接大于target的元素。~~ 
* 数组预排序 通过判断大于结束遍历。
* 依据 加法交换性 可将index1设为两者中小数，~~index2的遍历起点设在index1后。~~因a < b < c 且 a+b=c 得 a < c/2 < b 由此缩小index1 index2 的范围。 将原数组分为两段
* ~~依据 奇偶性 将 两段数组再拆分 分为四数组，根据target奇偶 遍历两组 四中二。~~

##合并二重遍历
因为 index1 index2在有序不同组中，可以尝试合并二重遍历为 一重双步。
例如:
abcdefg  hijklmn
起始双标在 g、h上 分别向两边步进


#效果
Runtime: 8 ms, faster than 92.50% of C++ online submissions for Two Sum.
Memory Usage: 9.7 MB, less than 58.31% of C++ online submissions for Two Sum.
