#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
int ropes(vector<int>& arr); 
void quickSort(vector<int>&, int low, int high);
*/

int rope(vector<int>&);

int main()
{
    vector<int> arr = {4, 3, 2, 6};

    

    /*cout << '\n' << ropes(arr);*/
}

int rope(vector<int>& arr) {
    int res = 0;

    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

    while (pq.size() != 1) {
        int one = 0, two = 0;
        one = pq.top();
        pq.pop();
        two = pq.top();
        pq.pop();

        res += one + two;

        pq.push(one + two);
    }

    return res;
}

/*
int ropes(vector<int>& arr) {
    int size = arr.size();

    quickSort(arr, 0, size - 1);

    for (int i : arr) cout << i << ' ';
    int res = 0;
    while (arr.size() > 1) {
        int comb = arr[0] + arr[1];
        arr.erase(arr.begin(), arr.begin() + 2);

        auto pos = lower_bound(arr.begin(), arr.end(), comb);

        arr.insert(pos, comb);
        res += comb;
    }

    return res;
}
int partition(vector<int>& arr, int low, int high) {
    
    int pivot = arr[high];

    int i = low - 1; 

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    
    if (low < high) {
    
        int pi = partition(arr, low, high);
    
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}*/