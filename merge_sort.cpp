#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end){
  int temp[100];
  int index = 0;
  int left = start;
  int right = mid+1;

  while(left <= mid && right <= end){

    if(arr[left] <= arr[right]){
      temp[index] = arr[left];
      left++;
      index++;
    }

    else{
      temp[index] = arr[right];
      right++;
      index++;
    }
  }

  while(left <= mid){
    temp[index] = arr[left];
    left++;
    index++;
  }

  while(right <= end){
    temp[index] = arr[right];
    right++;
    index++;
  }

  index = 0;

  for(int i = start; i <= end; i++){
    arr[i] = temp[index];
    index++;
  }
}

void mergesort(int arr[], int start, int end){
  
  if(start >= end){
    return;
  }

  int mid = start + (end - start) / 2;

  mergesort(arr,start,mid);
  mergesort(arr,mid+1,end);

  merge(arr,start,mid,end);
}

int main(){
  int arr[5] = {4,6,3,2,1};

  for (int i = 0; i < 5; i++){
    cout << arr[i] << " ";
  }
  cout << endl;

  mergesort(arr,0,4);

  for (int i = 0; i < 5; i++){
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}