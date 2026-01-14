#include <iostream>
using namespace std;

int partition(int arr[], int start, int end){
  int pos = start;

  for(int i = start; i < end; i++){
    if(arr[i] <= arr[end]){
      swap(arr[i], arr[pos]);
      pos++;
    }
  }

  swap(arr[pos], arr[end]);
  return pos;
}

void quicksort(int arr[], int start, int end){
  if (start >= end)
  return;

  int pivot = partition(arr,start,end);

  quicksort(arr,start,pivot-1);
  quicksort(arr,pivot+1,end);

}

int main(){
  int arr[5] = {1,6,3,5,2};
  quicksort(arr,0,4);

  for(int i = 0; i < 5; i++){
    cout << arr[i] << " ";
  }

  cout << endl;
  return 0;
}