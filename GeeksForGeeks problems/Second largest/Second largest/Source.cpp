#include <iostream>
#include <vector>

using namespace std;

int main() {
	
    vector<int> arr = { 17296, 9524, 28446, 12750, 422, 7888, 25584 };

    int size = arr.size();

    if (size <= 1) return -1;

    int largest = -1;
    int slargest = -1;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > largest) {
            slargest = largest;
            largest = arr[i];
        }else if(arr[i] < largest && arr[i] > slargest){
            slargest = arr[i];
        }
    }

    cout << largest << " " << slargest;
}