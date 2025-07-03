#include <iostream>
#include <vector>

using namespace std;

struct Nums {
    int ones;
    int twos;
    int zeros;
    int size;

    int lastTwo;
    int lastZero;
};

void sort(std::vector<int>&);

int main()
{
    std::vector<int> arr = {1, 0};

    if (arr.size() > 1) sort(arr);

    puts("");

    for (int i : arr) cout << i << " ";

}

void sort(vector<int>& arr) {
    int lo = 0, hi = arr.size() - 1;
    int mid = 0;

    while (mid <= hi) {

        if (arr[mid] == 0) {
            swap(arr[lo], arr[mid]);
            ++lo;
            ++mid;
        }
        else if (arr[mid] == 1)
            ++mid;
        else {
            swap(arr[hi], arr[mid]);
            --hi;
        }

        for (int i : arr) cout << i << " ";
        puts("");
    }
}

/*
void sort(vector<int>& arr) {
    Nums nums = { 0 };
    nums.size = arr.size();
    int pos = 0;

    for (int i : arr) {
        if (i == 0) {
            nums.zeros++;
            nums.lastZero = pos;
        }
        else if (i == 2) {
            nums.twos++;
        }
        pos++;
    }
    nums.ones = nums.size - nums.twos - nums.zeros;

    for (int i = 0; i < nums.size; i++) {
        if (i < nums.zeros) arr[i] = 0;
        else if (i < nums.zeros + nums.ones) arr[i] = 1;
        else arr[i] = 2;
    }


    cout << nums.size << '\n';
    cout << nums.zeros << ' ' << nums.ones << ' ' << nums.twos << ' ' << nums.lastZero << ' ' << nums.lastTwo << ' ';
}*/

//it works from both sides
/*
void sort(std::vector<int>& arr) {
    int size = arr.size();
    bool t = false;

    while (!t) {
        t = true;

        for (int i = 1; i < size; i++) {
            int index = i;
            int size1 = size - 1;

            if (arr[i] < arr[index - 1]) {
                int temp = arr[index - 1];
                arr[index - 1] = arr[i];
                arr[i] = temp;
                t = false;
            }

            if (arr[size1 - i] > arr[size1 - (index - 1)]) {
                int temp = arr[size1 - (index - 1)];
                arr[size1 - (index - 1)] = arr[size1 - i];
                arr[size1 - i] = temp;
            }
        }
    }
}
*/