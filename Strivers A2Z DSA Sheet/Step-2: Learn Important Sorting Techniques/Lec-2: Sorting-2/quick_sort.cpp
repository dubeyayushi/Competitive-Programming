//https://www.naukri.com/code360/problems/quick-sort_5844?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

/*
    time complexity: 
        1. best case - O(nlogn)
        2. average case - O(nlogn)
        3. worst case - O(n*n)
*/

/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/

int partitionArray(int input[], int start, int end) {
	// Write your code here
	int pivot = input[start];
	int i = start;
	int j = end;

	while(i<j){
		while(input[i]<=pivot && i<end){
			i++;
		}
		while(input[j]>pivot && j>start){
			j--;
		}
		if (i<j){
			int temp = input[i];
			input[i] = input[j];
			input[j] = temp;
		}
	}
	int temp = input[start];
	input[start] = input[j];
	input[j] = temp;
	return j;
}

void quickSort(int input[], int start, int end) {
	/*
		Don't write main().
		Don't read input, it is passed as function argument.
		Change in the given array itself.
		Taking input and printing output is handled automatically.
	*/
	if (start<end){
		int p_index = partitionArray(input, start, end);
		quickSort(input, start, p_index-1);
		quickSort(input, p_index+1, end);
	}
}