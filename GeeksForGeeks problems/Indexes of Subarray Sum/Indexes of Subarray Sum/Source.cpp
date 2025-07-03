#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
	vector<int> subarraySum(vector<int>& arr, int target) {
		vector<int> res = { -1 };
		int tg = 0;

		for (int i = 0; i < arr.size(); i++) {
			int index = i;
			while (tg < target && index < arr.size()) {
				tg += arr[index];
				
				if (tg == target) {

					res.resize(2);
					res[0] = { i + 1 };
					res[1] = { index + 1 };

					return res;
				}
				index++;
			}
			tg = 0;
		}
		return res;
	}
};

int main() {
	puts("Hello World");

	vector<int> arr = { 5, 3, 1, 6, 9, 4, 5, 6, 3, 1, 2 };

	Solution s;
	auto res = s.subarraySum(arr, 7);

	for(int i : res)
		cout << i << " ";
}

