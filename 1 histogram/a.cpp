#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
	int arr[94] = {};
	std::string str;
	char c;
	std::ifstream input("input.txt");
	if (input.is_open()) {
		while(input.get(c)) {
			int cc = int(c);
			if (c != ' ' && c != '\n') {
				arr[cc-33] += 1;
			}
		}
		input.close();
	}

	std::ofstream output;
  	output.open ("output.txt");
	if (output.is_open()) {
		for(int i = *std::max_element(arr, arr + 94); i > 0; i--) {
			for(int j : arr) {
				if(j > 0) {
					if (j < i) output << " ";
					else output << "#";
				}
			}
			output << "\n";
		}
	}
	for(int i = 0; i < 94; i++) {
		if (arr[i] > 0) output << static_cast<char>(i + 33);
	}
	output << "\n";
  	output.close();

	return 0;
}