/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.


Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
  int mSize = nums1Size + nums2Size;
  int merge[mSize];
  int i,j=0,m=0;
  double x=0.0;
  for(i=0,j=0;(i<nums1Size && j<nums2Size);m++)
  {
      // 1 2 3 nums1
      // 2 6
      if (nums1[i]<=nums2[j])
      {
          printf("[%d](%d)hi:%d ",m, i,nums1[i]);
           merge[m]=nums1[i];
           i++;
      } 
      else
      {
          printf("[%d](%d)bye:%d",m, j,nums2[j]);
          merge[m]=nums2[j];
          j++;
      }
  }
  printf("\ni=%d j=%d m=%d\nnum1Size=%d num2Size=%d\n",i,j,m,nums1Size,nums2Size);
  if (nums1Size > nums2Size)
  {
      for (int k=i; k<nums1Size; k++)
      {
          printf("[%d]hi:%d ",k,nums1[k]);
          merge[m]=nums1[k];
          m++;
      }
  }
  else if (nums2Size==nums1Size)
  {
      int k, lim;
      if(i<=j)
      {
          k=i;
          lim=nums1Size;
          for (k;k<lim;k++)
          {
              merge[m]=nums1[k];
              m++;
          }
      }
      else 
      {
          k=j;
          lim=nums2Size;
          for (k;k<lim;k++)
          {
              merge[m]=nums2[k];
              m++;
          }
      }
  }
  else
  {
      for (int k=j;k<nums2Size;k++)
      {
          printf("[%d]bye:%d ",k,nums2[k]);
          merge[m]=nums2[k];
          m++;
      }
  }
  printf("\n");
  for (i=0;i<mSize;i++)
    printf(" %d",merge[i]);
  int  med=0;
  med=mSize/2;
  printf("\nmed=%d",med);
  if (mSize%2==0)
    return (merge[med]+merge[med-1])/2.0;
  else
    return 1.0*merge[med];
  }
