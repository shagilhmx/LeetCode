<h2>Chef recently read about the mex function and came up with a function similar to that. For a (possibly empty) sequence of positive integers S, Chef defines f(S) as the smallest positive integer that does not appear in S. For example, f([])=1, f([3,4,3,5])=1, f([2,5,1,1,2,3])=4.</h2>

<h2>Chef's friend heard about Chef's idea and found it really cool. Therefore, he sent a sequence a1,a2,…,aN to Chef and asked him to find the sum of f(S) over all 2N possible subsequences S of this sequence. Since Chef is busy, he entrusted you with solving the problem.</h2>

<g2>Since the resulting sum can be very big, compute it modulo 998,244,353.</h2>

<strong>Input</strong>
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers a1,a2,…,aN.
<strong>Output</strong>
For each test case, print a single line containing one integer ― the sum of f(S) over all subsequences modulo 998,244,353.

<strong>Constraints</strong>
1≤T≤50
1≤N≤105
1≤ai≤109 for each valid i
the sum of N over all test cases does not exceed 5⋅105
Subtasks
Subtask #1 (50 points): the sum of N over all test cases does not exceed 1,000
Subtask #2 (50 points): original constraints

<strong>Sample Input 1 </strong>
2
2
1 1
3
1 2 1
<strong>Sample Output 1 </strong>
7
17
<strong>Explanation</strong>
Example case 1: The values for all possible subsequences are f([])=1, f([1])=2, f([1])=2, f([1,1])=2.

Example case 2: The values for all possible subsequences are f([])=1, f([1])=2, f([2])=1, f([1])=2, f([1,2])=3, f([2,1])=3, f([1,1])=2, f([1,2,1])=3.

