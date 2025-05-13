/*
You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:

If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: s = "abcyy", t = 2

Output: 7

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'b' becomes 'c'
'c' becomes 'd'
'y' becomes 'z'
'y' becomes 'z'
String after the first transformation: "bcdzz"
Second Transformation (t = 2):
'b' becomes 'c'
'c' becomes 'd'
'd' becomes 'e'
'z' becomes "ab"
'z' becomes "ab"
String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.
Example 2:

Input: s = "azbk", t = 1

Output: 5

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'z' becomes "ab"
'b' becomes 'c'
'k' becomes 'l'
String after the first transformation: "babcl"
Final Length of the string: The string is "babcl", which has 5 characters.
 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
1 <= t <= 105
*/

#define MOD 1000000007

int lengthAfterTransformations(char* s, int t) 
{
    long long dp[26] = {0};
    for (int i=0; i<strlen(s); i++)
        dp[s[i]-'a']++;

    for (int i=0; i<t; i++) 
    {
        long long newDP[26] = {0};
        for (int i = 0; i < 26; i++) 
        {
            if (i == 25) 
            {  // 'z'
                newDP[0] = (newDP[0] + dp[i]) % MOD; // 'a'
                newDP[1] = (newDP[1] + dp[i]) % MOD; // 'b'
            } 
            else
                newDP[i+1] = (newDP[i+1]+dp[i]) % MOD;
            //dp[i]=newDP[i];
        }
        for (int i = 0; i < 26; i++) 
            dp[i] = newDP[i];        
    }

    long long result = 0;
    for (int i = 0; i < 26; i++)
        result = (result + dp[i]) % MOD;

    return (int)result;
}
