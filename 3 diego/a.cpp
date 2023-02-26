#include <iostream>
#include <vector>
#include <fstream> 
#include <algorithm>

int count_less_than_N(const std::vector<int>& arr, int N) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < N) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

int main()
{
	int num; 
	std::ifstream input("input.txt");
	input >> num;
	std::vector<int> diego;
	for (int i = 0; i < num; i++) {
		int j;
		input >> j;
		diego.push_back(j);
	}
	input >> num;
	std::sort(diego.begin(), diego.end());
	diego.erase( unique( diego.begin(), diego.end() ), diego.end() );

	std::ofstream output("output.txt"); 

	for (int i = 0; i < num; i++) {
		int j;
		input >> j;

		output << count_less_than_N(diego, j) << std::endl;
		
        }
	input.close();
	output.close();
	return 0;
}
