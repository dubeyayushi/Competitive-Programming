#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {
  if (size == 0) {
    return 0;
  }

  int smallOutput = allIndexes(input, size - 1, x, output);
  if (input[size] == x) {
    output[smallOutput] = size;
    return smallOutput+1;
  }
  return smallOutput;

  if (input[size - 1] == x) {
    output[smallOutput] = size - 1;
    return smallOutput+1;
  } 
  else {
    return smallOutput;
  }
}

int main(){
    int input[] = {1,2,3,4,4,5,6,4,5,7};
    int output[100];
    cout << allIndexes(input, 10, 4, output);
}
