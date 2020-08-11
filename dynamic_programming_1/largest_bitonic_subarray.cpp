/*
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic subsequence
Input Constraints:
1<= N <= 100000
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
Sample Input 3:
2
5 1
Sample Output 3:
2
*/

#include <bits/stdc++.h>
int longestBitonicSubarray(int *input, int n) {
		
	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
    int* output = new int[n];
	output[0] = 1;
	for(int i = 1; i < n; i++) {
		output[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (input[j] >= input[i]) {
				continue;
			}
			int possibleAns = output[j] + 1;
			if (possibleAns > output[i]) {
				output[i] = possibleAns;
			}
		}
	}
    
    int* out = new int[n];
    out[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--){
        out[i] = 1;
        for(int j = i + 1; j < n; j++){
            if(input[j] >= input[i]){
                continue;
            }
            int possibleAns = out[j] + 1;
			if (possibleAns > out[i]) {
				out[i] = possibleAns;
			} 
        }
    }
    
    for(int i = 0; i < n; i++){
        //std :: cout << output[i] << "    " << out[i] << endl;
        output[i] += (out[i] - 1);
    }
    return *max_element(output, output + n);
}

