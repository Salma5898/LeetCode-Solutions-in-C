/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"

Output: "leotcede"

 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/
char* reverseVowels(char* s) 
{
    char vowels[300000]; int j=0;
    int L_slength = strlen(s);
    for (int i=0; i<L_slength; i++)
    {
        if (strchr("aeiouAEIOU", s[i]))
            vowels[j++]=s[i];
    }    
    vowels[j]='\0';
    j=strlen(vowels)-1;

    for (int i=0; i<L_slength; i++)
    {
        if (strchr("aeiouAEIOU", s[i]))
            s[i]=vowels[j--];
    }
        printf("%s", vowels);
        return s;
}
