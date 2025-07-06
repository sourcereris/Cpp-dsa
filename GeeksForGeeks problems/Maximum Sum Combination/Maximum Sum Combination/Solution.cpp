#include "Solution.h"

std::vector<int> Solution::topKSumPairs(std::vector<int> arr1, std::vector<int>arr2, int k)
{
    std::vector<int> res;

    std::sort(arr1.rbegin(), arr1.rend());
    std::sort(arr2.rbegin(), arr2.rend());

    int p1 = 0, p2 = 0;
    int index = 0;

    while (index != k) {

        res.push_back(arr1.at(p1) + arr2.at(p2));
        ++index;

        if (arr1.at(p1) > arr2.at(p2)) {
            ++p2;
        }
        else {
            
        }
    }

    return std::vector<int>();
}
