/*
Given a random integer array and a number x. Find and print the triplets of elements in the array which sum to x.
While printing a triplet, print the smallest element first.
That is, if a valid triplet is (6, 5, 10) print "5 6 10". There is no constraint that out of 5 triplets which have to be printed on 1st line. You can print triplets in any order, just be careful about the order of elements in a triplet.
Input format :
Line 1 : Integer N (Array Size)
Line 2 : Array elements (separated by space)
Line 3 : Integer x
Output format :
Line 1 : Triplet 1 elements (separated by space)
Line 2 : Triplet 3 elements (separated by space)
Line 3 : and so on
Constraints :
1 <= N <= 1000
1 <= x <= 100
Sample Input:
7
1 2 3 4 5 6 7 
12
Sample Output ;
1 4 7
1 5 6
2 3 7
2 4 6
3 4 5
*/
// arr - input array
// size - size of array
// x - sum of triplets

void FindTriplet(int arr[], int size, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
for(int i=0;i<size;i++)
{
  for(int j=i+1;j<size;j++)
  {
    
    {
      for(int k=j+1;k<size;k++)
      {
        if(arr[i]+arr[j]+arr[k]==x)
      {
        if(arr[i]>=arr[j] && arr[i]>=arr[k])
        {
          if(arr[j]>=arr[k])
          {
            cout << arr[k] << " " << arr[j] << " " << arr[i] << endl;
          }
          else
          {
            cout << arr[j] << " " << arr[k] << " " << arr[i] << endl;
          }
        }
          else if(arr[j]>=arr[i] && arr[j]>=arr[k])
          {
            if(arr[i]>=arr[k])
            {
              cout << arr[k] << " " << arr[i] << " " << arr[j] << endl;
            }
            else
            {
              cout << arr[i] << " " << arr[k] << " " << arr[j] << endl;
            }
          }
          else if(arr[k]>=arr[i] && arr[k]>=arr[j])
          {
            if(arr[i]>=arr[j])
            {
              cout << arr[j] << " " << arr[i] << " " << arr[k] << endl;
            }
            else
            {
              cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
            }
          }
      }
      }
    }
  }
}
}

