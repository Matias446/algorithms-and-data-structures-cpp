#pragma once


using namespace std;

template <class T>
class HeapSort{
    public: 
    void heapify (int* arr, int n, int m){
        int masLargo = m;
        int left = 2 * m + 1;
        int right = 2 * m + 2;

        if(left < n && arr[left] > arr[masLargo]){
            masLargo = left;
        }

        if(right < n && arr[right] > arr[masLargo]){
            masLargo = right;
        }

        if(masLargo != m){
            std::swap(arr[m], arr[masLargo]);
            heapify(arr, n, masLargo);
        }
    }

    void sortH (int* arr, int n){      
        for(int i = n / 2 - 1; i >= 0; i--){ 
            heapify(arr, n, i);
        }
        for(int i = n - 1; i > 0; i--){
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};
