/*
Given an integer array arr, 
return true if there are three consecutive odd numbers in the array.
Otherwise, return false.
 

Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.


Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
*/

/*
0   =   0   0   0   0
1   =   0   0   0   1
2   =   0   0   1   0
3   =   0   0   1   1
always the LSB in odd numbers is 1
we have to use logical AND
Example 1:
2   =   0   0   1   0
6   =   0   1   1   0
4   =   0   1   0   0
1   =   0   0   0   1
*/
bool threeConsecutiveOdds(int* arr, int arrSize) 
{
    if (arrSize < 3)
        return false;
    int consecOdds =0;
    for (int i=0; i<arrSize; i++)   
    {
        if (arr[i] & 1)
        {
            consecOdds++;
            if (consecOdds == 3)
                return true;
        }
        else
            consecOdds = 0;
    }
    return false;
}
