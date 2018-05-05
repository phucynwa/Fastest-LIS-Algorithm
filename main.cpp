#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

/**
 * This function return the smallest position has property larger than argument value
 * @param number is array of input value
 * @param lpArr is array of last position, with id is array length
 * @param beginPos
 * @param endPos
 * @param value is argument value
 * @return
 */

int findSLP(
        int inputArr[],
        int lpArr[],
        int beginPos,
        int endPos,
        int value
);

/**
 * This function get the longest increase list
 * @param number is input array
 * @param length is length of input array
 * @param gback is array it returns
 * @param maxLen is length it return
 */
void lis(
        int *inputArr,
        int inputArrLength,
        int *&lisArr,
        int &lisLength
);

/**
 * This function print array[length] to screen
 * @param array
 * @param length
 */
void printArray(int array[], int length);

void createRandomArray(int *&array, int *&length);

void useTypeArray(int *&array, int *&length);

int main(int argc, char **argv) {
    int *inputArr;
    auto *inputArrLength = new int;

    int *lisArr;
    auto *lisLength = new int;

    //createRandomArray(inputArr, inputArrLength);
    useTypeArray(inputArr, inputArrLength);


    cout << "Input: " << endl;
    printArray(inputArr, *inputArrLength);

    clock_t time = clock();

    lis(inputArr, *inputArrLength, lisArr, *lisLength);


    cout << endl << "Output: " << endl;
    printArray(lisArr, *lisLength);

    cout << endl << "Process time is " <<
         (float) (clock() - time) / CLOCKS_PER_SEC <<
         "s" << endl;

    delete[](inputArr);
    delete[](lisArr);

    delete inputArrLength;
    delete lisLength;

    return 0;
}


int findSLP(int inputArr[],
            int lpArr[],
            int beginPos,
            int endPos,
            int value) {
    if (inputArr[lpArr[beginPos]] >= value) {
        return beginPos;
    } else if (beginPos + 1 == endPos) {
        return endPos;
    } else {
        int midPos = (beginPos + endPos) / 2;
        if (value < inputArr[lpArr[midPos]]) {
            return findSLP(inputArr,
                           lpArr,
                           beginPos,
                           midPos,
                           value);
        } else {
            return findSLP(inputArr,
                           lpArr,
                           midPos,
                           endPos,
                           value);
        }
    }
}

void lis(int *inputArr,
         int inputArrLength,
         int *&lisArr,
         int &lisLength) {
    int lastOfLen[inputArrLength];
    int before[inputArrLength];
    int tmpNumber;
    lisLength = 1;
    lastOfLen[1] = 0;
    for (uint i = 0; i < inputArrLength; ++i) before[i] = -1;
    for (uint i = 1; i < inputArrLength; ++i) {
        if (inputArr[i] > inputArr[lastOfLen[lisLength]]) {
            before[i] = lastOfLen[lisLength];
            lastOfLen[++lisLength] = i;
            continue;
        }
        tmpNumber = findSLP(inputArr, lastOfLen, 1, lisLength, inputArr[i]);
        lastOfLen[tmpNumber] = i;
        if (tmpNumber > 1) before[i] = lastOfLen[tmpNumber - 1];
    }
    int it = lastOfLen[lisLength];
    lisArr = new int[lisLength];
    for (int pos = lisLength - 1;; it = before[it]) {
        lisArr[pos--] = inputArr[it];
        if (before[it] < 0) break;
    }
}

void printArray(int array[], int length) {
    cout << "Array[" << length << "] = {\t";
    --length;
    for (int i = 0; i < length; ++i) {
        cout << setw(6) << array[i] << ", ";
        if(i % 100 == 99) {
            cout << endl << "\t\t\t\t";
        }
    }
    cout << setw(6) << array[length] << "}" << endl;
}

void useTypeArray(int *&array, int *&length) {
    length = new int;
    cin >> *length;
    array = new int[*length];
    for(int i = 0; i < *length; ++i) cin >> array[i];
}

void createRandomArray(int *&array, int *&length) {
    srand(static_cast<unsigned int>(time(nullptr)));
    if(!length) {
        length = new int(rand() % 600000);
    }
    array = new int[*length];
    for (int i = 0; i < *length; ++i) {
        array[i] = rand() % *length - *length/2;
    }
}