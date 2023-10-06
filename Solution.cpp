#include<iostream>
#include<limits.h>
using namespace std;

bool isPossible(int arr[], int N , int k, int mid) {

  int cowCount = 1;
  int lastPos = arr[0];

  for(int i=0 ; i<N ; i++) {
    if(arr[i] - lastPos >= mid) {
      cowCount++;
      if(cowCount == k) {
        return true;
      }
      lastPos = arr[i];
    }
  }
  return false;
}

int AggresiveCow(int arr[], int N, int k) {
  int start = 0;

  int maxi = -1;
  for(int i= 0; i<N; i++) {
    maxi = max(maxi, arr[i]);
  }
  int end = maxi;

    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end) {

      if(isPossible(arr, N ,k,  mid)) {
        ans = mid;
        start = mid+1;
      } else {
        end = mid-1;
      }
      mid = start + (end - start)/2;
    }
    return ans;
}

int main() {
    int n; 
    cout<<"How many stalls you want : ";
    cin>>n;

      int arr[n];
    cout<<"Enter the elements : ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int k;
  cout<<"Enter no. of cows: ";
  cin>>k;

  cout<<"Largest minimum distance among cows : "<<AggresiveCow(arr, 5, k);
  return 0;
}