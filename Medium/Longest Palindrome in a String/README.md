<h2><a href="https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1?page=1&company=Visa&status=unsolved&sortBy=submissions">Longest Palindrome in a String</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a string S, find the longest palindromic substring in S.<strong> Substring of string S:</strong></span><span style="font-size: 18px;"> S[ i . . . . j ]&nbsp;where 0&nbsp;≤ i&nbsp;≤ j &lt; len(S)<strong>. Palindrome string:</strong></span><span style="font-size: 18px;"> A string that reads the same backward. More formally, S is a palindrome if reverse(S) = S.</span><span style="font-size: 18px;"><strong> In case of conflict</strong>, return the substring which occurs first ( with the least starting index).</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
S = "aaaabbaa"
<strong>Output:</strong> aabbaa
<strong>Explanation</strong>: The longest Palindromic
substring is "aabbaa".</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: 
S = "abc"
<strong>Output:</strong> a
<strong>Explanation</strong>: "a", "b" and "c" are the 
longest palindromes with same length.
The result is the one with the least
starting index.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>longestPalin()&nbsp;</strong>which takes the string S&nbsp;as input and returns the longest palindromic substring of S.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity: </strong>O(|S|<sup>2</sup>).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(1).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ |S| ≤ 10<sup>3</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Zoho</code>&nbsp;<code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Samsung</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Visa</code>&nbsp;<code>Walmart</code>&nbsp;<code>Google</code>&nbsp;<code>Qualcomm</code>&nbsp;<code>Groupon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>palindrome</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;