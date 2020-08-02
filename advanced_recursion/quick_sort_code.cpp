/*
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int a[], int low, int high)
{
    int pivot, index, i;
    index = low;
    pivot = high;

    for(i = low; i < high; i++) {
        if(a[i] < a[pivot]) {
            swap(&a[i], &a[index]);
            index++;
        }
    }

    swap(&a[pivot], &a[index]);

    return index;
}
int QuickSort(int a[], int low, int high)
{
    int pindex = high;
    if(low < high) {
        int pindex = Partition(a, low, high);
        
        QuickSort(a, low, pindex - 1);
        QuickSort(a, pindex + 1, high);
    }
    return 0;
}
void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    QuickSort(input, 0, size - 1);
}
