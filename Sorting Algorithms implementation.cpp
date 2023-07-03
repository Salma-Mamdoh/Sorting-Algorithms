#include<bits/stdc++.h>
using namespace std;
namespace sortlib {
    // insertion sort 
	template<typename T>
    void insertion_sort(T arr[], int n) {
        T key;
        int j;
        for (int i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && key < arr[j]) {
                // shift elements
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    // selection sort 
    template<typename T>
    void selection_sort(T arr[], int n) {
        int minindex = 0;
        for (int i = 0; i < n - 1; i++) { //  as we didn't have to check the last element 
            minindex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[minindex] > arr[j]) {
                    minindex = j;
                }
            }
            swap(arr[minindex], arr[i]);
        }
    }
    // Bubble sort 
    template<typename T>
    void Bubble_sort(T arr[], int n) {
        for (int i = 0; i < n- 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    //shell sort 
    template<typename T> 
    void shell_sort(T arr[], int n){

        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i += 1)
            {
                T temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];
                arr[j] = temp;
            }
        }
    }
    //Merge sort 
    template<typename T>
    void merge(T arr[], const int  l, const int  mid, const int  r)
    {
        const int n1 = mid - l + 1; // size of first array 
        const int  n2 = r - mid; // size of second array 

        T* arr1 = new T[n1]; // first array
        T* arr2 = new T[n2]; // second array 

        for (auto i = 0; i < n1; i++)
            arr1[i] = arr[l + i];
        for (auto j = 0; j < n2; j++)
            arr2[j] = arr[mid + 1 + j];
        //comparing process 
        int i = 0, j = 0;
        int k = l;
        while (i < n1&& j < n2) {
            if (arr1[i]<= arr2[j]) {
                arr[k]= arr1[i];
                i++;
            }
            else {
                arr[k]= arr2[j];
                j++;
            }
            k++;
        }
        // check if there are still elements in the first array
        while (i< n1) {
            arr[k]= arr1[i];
            i++;
            k++;
        }
        // check if there are still elements in the second array 
        while (j< n2) {
            arr[k] = arr2[j];
            j++;
            k++;
        }
        // to avoid memory leak
        delete[] arr1;
        delete[] arr2;
    }
    template<typename T>
    void mergeSort(T array[], int  begin, int  end)
    {
        if (begin >= end)
            return; // Returns recursively

        int mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }
    // Quick sort 
    template<typename T>
    int partition(T arr[], int l, int h) {
        int i = l;
        int j = h;
        T p = arr[l];
        while (i < j) {
            do {
                i++;
            } while (arr[i] <= p);
            do {
                j--;
            } while (arr[j] > p);
            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[l], arr[j]);
        return j;
    }
    template<typename T>
    void Quicksort(T arr[], int l, int h) {
        if (l < h) {
            int piv = partition(arr, l, h);
            Quicksort(arr, l, piv);
            Quicksort(arr, piv + 1, h);
        }
    }
    // count sort 
    int getMax(int a[], int n) {
        int max = INT16_MIN;
        for (int i = 0; i < n; i++) {
            if (a[i] > max)
                max = a[i];
        }
        return max; //maximum element from the array  
    }
    template<typename T>
    void countingSort(T arr[], int n, T min, T max) {
        int range = max - min + 1;
        T* count = new T[range];
        T* output = new T[n];
        for (int i = 0; i < range; i++) {
            count[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            count[arr[i] - min]++;
        }
        for (int i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            output[count[arr[i] - min] - 1] = arr[i];
            count[arr[i] - min]--;
        }
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
        delete[] count;
        delete[] output;
    }

    template<typename T>
    void Print_arr(T arr, int n) {
        for (int i = 0; i < n; i++)cout << arr[i] << " ";
        cout << "\n";
    }
}

using namespace sortlib;
int main() {
    
   int arr[200],arr2[500], arr3[1000], arr4[5000], arr5[10000], arr6[20000], arr7[50000];
   // tracing each algorithm on different sizes of arrays;
    for (int i = 0; i < 200; i++) {
        arr[i] = rand();
        //cout << arr[i] << " ";
    }
    clock_t start = clock();
    //insertion_sort(arr, 200);
    //selection_sort(arr, 200);
    //Bubble_sort(arr, 200);
    //shell_sort(arr, 200);
    //mergeSort(arr,0,199);
    //Quicksort(arr, 0, 200);
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = *max_element(arr, arr + n);
    countingSort(arr, n,0,max);
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    printf("Time measured: %.3f seconds.\n", elapsed);
    for (int i = 0; i < 500; i++) {
        arr2[i] = rand();
        //cout << arr2[i] << " ";
    }
    clock_t start2 = clock();
    //insertion_sort(arr2, 500);
    //selection_sort(arr2, 500);
    //Bubble_sort(arr2, 500);
    //shell_sort(arr2, 500);
    //mergeSort(arr2, 0, 499);
    //Quicksort(arr2, 0, 500);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int max2 = *max_element(arr2, arr2 + n2);
    countingSort(arr2, n2, 0, max2);
    clock_t end2 = clock();
    double elapsed2 = double(end2 - start2) / CLOCKS_PER_SEC;
    printf("Time measured: %.3f seconds.\n", elapsed2);
    //cout << clock()<<"\n";
    for (int i = 0; i < 1000; i++) {
        arr3[i] = rand();
        //cout << arr3[i] << " ";
    }
    clock_t start3 = clock();
    //insertion_sort(arr3, 1000);
    //selection_sort(arr3, 1000);
    //Bubble_sort(arr3, 1000);
    //shell_sort(arr3, 1000);
    //mergeSort(arr3, 0, 999);
    //Quicksort(arr3, 0, 1000);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int max3 = *max_element(arr3, arr3 + n3);
    countingSort(arr3, n3, 0, max3);
    clock_t end3 = clock();
    double elapsed3 = double(end3 - start3) / CLOCKS_PER_SEC;
    printf("Time measured: %.3f seconds.\n", elapsed3);
    for (int i = 0; i < 5000; i++) {
        arr4[i] = rand();
        //cout << arr4[i] << " ";
    }
    clock_t start4 = clock();
    //insertion_sort(arr4, 5000);
    //selection_sort(arr4, 5000);
    //Bubble_sort(arr4, 5000);
    //shell_sort(arr4, 5000);
    //mergeSort(arr4, 0, 4999);
    //Quicksort(arr4, 0, 5000);
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int max4 = *max_element(arr4, arr4 + n4);
    countingSort(arr4, n4, 0, max4);
    clock_t end4 = clock();
    double elapsed4 = double(end4 - start4) / CLOCKS_PER_SEC;
    printf("Time measured: %.3f seconds.\n", elapsed4);
    for (int i = 0; i < 10000; i++) {
        arr5[i] = rand();
        //cout << arr5[i] << " ";
    }
    clock_t start5 = clock();
    //insertion_sort(arr5, 10000);
    //selection_sort(arr5, 10000);
    //Bubble_sort(arr5, 10000);
    //shell_sort(arr5, 10000);
    //mergeSort(arr5, 0, 9999);
    //Quicksort(arr5, 0, 10000);
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int max5 = *max_element(arr5, arr5 + n5);
    countingSort(arr5, n5, 0, max5);
    clock_t end5 = clock();
    double elapsed5 = double(end5 - start5) / CLOCKS_PER_SEC;
    printf("Time measured: %.3f seconds.\n", elapsed5);
    for (int i = 0; i < 20000; i++) {
        arr6[i] = rand();
        //cout << arr6[i] << " ";
    }
    clock_t start6 = clock();
    //insertion_sort(arr6, 20000);
    //selection_sort(arr6, 20000);
    //Bubble_sort(arr6, 20000);
    //shell_sort(arr6, 20000);
    //mergeSort(arr6, 0, 19999);
    //Quicksort(arr6, 0, 20000);
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    int max6 = *max_element(arr6, arr6 + n6);
    countingSort(arr6, n6, 0, max6);
    clock_t end6 = clock();
    double elapsed6 = double(end6 - start6) / CLOCKS_PER_SEC;
    printf("Time measured: %.3f seconds.\n", elapsed6);
    for (int i = 0; i < 50000; i++) {
        arr7[i] = rand();
        //cout << arr7[i] << " ";
    }
    clock_t start7 = clock();
    //insertion_sort(arr7, 50000);
    //selection_sort(arr7, 50000);
    //Bubble_sort(arr7, 50000);
    //shell_sort(arr7, 50000);
    //mergeSort(arr7, 0, 49999);
    //Quicksort(arr7, 0, 49999);
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    int max7 = *max_element(arr7, arr7 + n7);
    countingSort(arr7, n7, 0, max7);
    clock_t end7 = clock();
    double elapsed7 = double(end7 - start7) / CLOCKS_PER_SEC;
    printf("Time measured: %.3f seconds.\n", elapsed7);

    int arraytest[6] = { 1,5,2,8,-1 };
    //insertion_sort(arraytest, 6);
    //selection_sort(arraytest, 6);
    //Bubble_sort(arraytest, 6);
    //shell_sort(arraytest, 6);
    //mergeSort(arraytest, 0, 5);
    //Quicksort(arraytest, 0, 6);
    int arraytestsize = sizeof(arraytest) / sizeof(arraytest[0]);
    int maxnumofarraytest = *max_element(arraytest, arraytest + arraytestsize);
    int minnumofarraylist = *min_element(arraytest, arraytest + arraytestsize);
    countingSort(arraytest, arraytestsize, minnumofarraylist, maxnumofarraytest);
    Print_arr(arraytest, 6);
    char arraytest2[6] = { 'a','o','c','z','b'};
    //insertion_sort(arraytest2, 6);
    //selection_sort(arraytest2, 6);
    //Bubble_sort(arraytest2, 6);
    //shell_sort(arraytest2, 6);
    //mergeSort(arraytest2, 0, 5);
    //Quicksort(arraytest2, 0, 6);
    int arraytestsize2 = sizeof(arraytest2) / sizeof(arraytest2[0]);
    char maxcharofarraytest2 = *max_element(arraytest2, arraytest2 + arraytestsize2);
    char mincharofarraylist2 = *min_element(arraytest2, arraytest2 + arraytestsize2);
    countingSort(arraytest2, arraytestsize2, mincharofarraylist2, maxcharofarraytest2);
    Print_arr(arraytest2, 6);

	

}
