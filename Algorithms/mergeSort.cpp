#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& arr, int left, int mid, int right){
    /*left is the starting index of the array to be sorted 
      right is the ending index of the array to be sorted
    */
    int n1 = mid - left + 1 ;//size of left array, we add one since we start count from zero
    int n2 = right - mid;//size of right array

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    //copy over the main array to the subarrays
    for (int i = 0; i < n1; ++i){
        leftArr[i] = arr[left + i];
    }
    for (int j= 0; j < n2; ++j){
        rightArr[j] = arr[mid + 1 + j];
    }
    //sorting loop 
    int i = 0, j =0, k = left;
    while (i < n1 && j < n2){
        if (leftArr[i] <= rightArr[j]){
            arr[k] =leftArr[i];
            ++i;
        } else{
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }
    //sort remaining elements
    while (i < n1){
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }
    while (j < n2){
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>&arr, int left, int right){
    //base case
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; ++i)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, arr_size - 1);

    cout << "Sorted array is \n";
    for (int i = 0; i < arr_size; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}









