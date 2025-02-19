#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <numeric> 

using namespace std;
const string FILENAME = "sorting_data.csv";


void write_to_csv(const string& algorithm_name,int size, int comparisons, int swaps, 
                  chrono::microseconds duration) {
    ofstream outfile(FILENAME, ios::app); 
    if (!outfile.is_open()) {
        cerr << "Error: Could not open file " << FILENAME << endl;
        return;
    }

    outfile << algorithm_name << "," << size << "," << comparisons << "," << swaps << "," 
            << duration.count() << endl;
    outfile.close();
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void gen_random(int a1[], int a2[], int a3[], int a4[], int a5[], int a6[], int n) {
      for(int i=0;i<n;i++){  
                a1[i]=rand()%10000+1;
                a2[i]=a1[i];
                a3[i]=a1[i];
                a4[i]=a1[i];
                a5[i]=a1[i];
                a6[i]=a1[i];
        }
}

// Bubble Sort Function
void b_sort(int arr[], int n, int& comparisons, int& swaps) {
    for (int i = 0; i < n - 1; ++i) {
        int cnt=0;
        for (int j = 0; j < n - i - 1; ++j) {
            ++comparisons;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                ++swaps;
                cnt++;
            }
        }
        if(cnt==0) break;
    }
}

// Insertion Sort Function
void insertion_sort(int arr[], int n, int& comparisons, int& swaps) {
    for (int i = 1; i < n; ++i) {
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[j + 1]) {
            ++comparisons;
            swap(arr[j], arr[j + 1]);
            ++swaps;
            --j;
        }
    }
}

// Selection Sort Function
void s_sort(int arr[], int n, int& comparisons, int& swaps) {
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            ++comparisons;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            ++swaps;
        }
    }
}

// Merge Sort Function
void merges(int arr[], int low, int mid, int high, int& comparisons, int& swaps) {
    vector<int> temp(high - low + 1);
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        ++comparisons;
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (int i = low; i <= high; ++i) {
        arr[i] = temp[i - low];
        ++swaps; // Consider each assignment as a swap
    }
}

void merge_sort(int arr[], int low, int high, int& comparisons, int& swaps) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid, comparisons, swaps);
        merge_sort(arr, mid + 1, high, comparisons, swaps);
        merges(arr, low, mid, high, comparisons, swaps);
    }
}

// Quick Sort

int parti(int arr[], int low, int high,int &comparisons,int &swaps) {
    int pivot=arr[low];
    int left = low;
    int right = high;

    while (left < right) {

        while(arr[left] <= pivot && left<=high-1) {
            comparisons++;
            left++;
        }
        while (arr[right] > pivot && right>=low+1) {
            comparisons++;
            right--;
        }
        if (left < right) {
            swaps++;
            swap(arr[left], arr[right]);
        }
    }
    swaps++;
    swap(arr[low],arr[right]);
    return right;
}


void quick_sort(int arr[],int low,int high,int &comparisons,int& swaps){
        if(low<high){
                int partition=parti(arr,low,high,comparisons,swaps);
                quick_sort(arr,low,partition-1,comparisons,swaps);
                quick_sort(arr,partition+1,high,comparisons,swaps);

        }
}


// Heap Sort
void heapify(int arr[], int n, int i, int& comparisons, int& swaps) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        ++comparisons;
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        ++comparisons;
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        ++swaps;
        heapify(arr, n, largest, comparisons, swaps);
    }
}

void heap_sort(int arr[], int n, int& comparisons, int& swaps) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i, comparisons, swaps);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        ++swaps;
        heapify(arr, i, 0, comparisons, swaps);
    }
}

int main() {
    const int INITIAL_ARRAY_SIZE = 10000; 
    const int INCREMENT_STEP = 500;
    const int NUM_RUNS = 50; 
    ofstream outfile(FILENAME, ios::out);
    if (!outfile.is_open()) {
        cerr << "Error: Could not create file " << FILENAME << endl;
        return 1;
    }
    outfile << "Algorithm,Size,Comparisons,Swaps,Time(microseconds)\n";
    outfile.close();

    // Vectors to store durations for each algorithm
    vector<chrono::microseconds> bubble_sort_times, insertion_sort_times, 
                                selection_sort_times, merge_sort_times, 
                                quick_sort_times, heap_sort_times;

    for (int run = 0; run < NUM_RUNS; ++run) {
        int ARRAY_SIZE = INITIAL_ARRAY_SIZE + (run * INCREMENT_STEP); 
        int arr1[ARRAY_SIZE], arr2[ARRAY_SIZE], arr3[ARRAY_SIZE], 
            arr4[ARRAY_SIZE], arr5[ARRAY_SIZE], arr6[ARRAY_SIZE];

        gen_random(arr1, arr2, arr3, arr4, arr5, arr6, ARRAY_SIZE);

        // Bubble Sort
        {
            int comparisons = 0, swaps = 0;
            auto start = chrono::high_resolution_clock::now();
            b_sort(arr1, ARRAY_SIZE, comparisons, swaps);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            write_to_csv("Bubble Sort", ARRAY_SIZE, comparisons, swaps, duration);
            bubble_sort_times.push_back(duration); 
        }

        // Insertion Sort
        {
            int comparisons = 0, swaps = 0;
            auto start = chrono::high_resolution_clock::now();
            insertion_sort(arr2, ARRAY_SIZE, comparisons, swaps);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            write_to_csv("Insertion Sort", ARRAY_SIZE, comparisons, swaps, duration);
            insertion_sort_times.push_back(duration); 
        }

        // Selection Sort
        {
            int comparisons = 0, swaps = 0;
            auto start = chrono::high_resolution_clock::now();
            s_sort(arr3, ARRAY_SIZE, comparisons, swaps);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            write_to_csv("Selection Sort", ARRAY_SIZE, comparisons, swaps, duration);
            selection_sort_times.push_back(duration); 
        }

        // Merge Sort
        {
            int comparisons = 0, swaps = 0;
            auto start = chrono::high_resolution_clock::now();
            merge_sort(arr4, 0, ARRAY_SIZE - 1, comparisons, swaps);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            write_to_csv("Merge Sort", ARRAY_SIZE, comparisons, swaps, duration);
            merge_sort_times.push_back(duration); 
        }

        // Quick Sort
        {
            int comparisons = 0, swaps = 0;
            auto start = chrono::high_resolution_clock::now();
            quick_sort(arr5, 0, ARRAY_SIZE - 1, comparisons, swaps);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            write_to_csv("Quick Sort", ARRAY_SIZE, comparisons, swaps, duration);
            quick_sort_times.push_back(duration); 
        }

        // Heap Sort
        {
            int comparisons = 0, swaps = 0;
            auto start = chrono::high_resolution_clock::now();
            heap_sort(arr6, ARRAY_SIZE, comparisons, swaps);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            write_to_csv("Heap Sort", ARRAY_SIZE, comparisons, swaps, duration);
            heap_sort_times.push_back(duration); 
        }
    }
    cout << "Data written to " << FILENAME << endl;

    return 0;
}