//
// Created by amartya on 07/02/22.
//

#include <iostream>

using namespace std;

// template class for Quick Sorting Algo
template<class T>
class Quick {
public:
    // creating necessary variables
    int size;
    int counter;
    T *array;

    // constructor for initialization
    Quick(int n) {
        size = n;
        counter = 0;
        array = new T[n];
    }

    // array input function
    void inputArray() {
        for (int i = 0; i < size; i++) {
            cout << "Enter Element [" << i << "]: ";
            cin >> array[i];
        }
    }

    // array print function
    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << ", ";
        }
        cout << "\b\b\n";
    }

    int partition(int start, int end) {
        // using last element as pivot
        T pivEle = array[end];
        // smaller element index
        int i = start-1;

        for (int j = start; j < end; j++) {
            // swapping when the element in less than the pivot element
            if (array[j] <= pivEle) {
                counter++;
                i++;
                swap(array[j], array[i]);
            }
        }
        // swapping pivot element to correct position
        swap(array[i+1], array[end]);

        // return the index of pivot element
        return (i+1);
    }

    // quick sort function
    void quickSort(int start, int end) {
        if (start < end) {
            counter++;
            // creating pivot index using the partition function
            int pivotInd = partition(start, end);

            // recursively calling quickSort function to sort the arrays divided through pivot
            quickSort(start, pivotInd-1);
            quickSort(pivotInd+1, end);
        }
    }

    void CallingFunctions() {
        inputArray();
        cout << "---------------------------------------------------------\n";
        cout << "The Array you have entered is ";
        printArray();
        quickSort(0, size-1);
        cout << "The Array After Quick Sort is ";
        printArray();
        cout << "The Total no of comparisons is " << counter << endl;
    }
};

int main() {
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\tTemplate Program to implement Quick Sort Algorithm\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "1. For Integer\n2. For Character\n3. For Float\nSelect your DataType: ";
    int dataType;
    cin >> dataType;

    cout << "---------------------------------------------------------\n";
    cout << "Enter the Size of the Array: ";
    int n;
    cin >> n;

    if (dataType == 1) {
        Quick<int> obj(n);
        obj.CallingFunctions();
    } else if (dataType == 2) {
        Quick<char> obj(n);
        obj.CallingFunctions();
    } else if (dataType == 3) {
        Quick<float> obj(n);
        obj.CallingFunctions();
    } else { cout << "Wrong Data Type\n"; }

    return 0;
}
