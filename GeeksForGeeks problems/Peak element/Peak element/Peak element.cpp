#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> arr = {1, 2, 4, 9, 7, 8, 3};

    for (int i = 0; i < arr.size(); ++i) {

        bool onLeft = false, onRight = false;
        if (i > 0 && arr[i] > arr[i - 1]) onLeft = true;
        if (i < arr.size()-1 && arr[i] > arr[i + 1]) onRight = true;

        if (onLeft && onRight) { cout << arr[i] << " "; break; }
        
    }
}