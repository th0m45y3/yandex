#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
	int arr[94] = {};
	std::string str;
	std::ifstream input ("input.txt");
	if (input.is_open()) {
		while(std::getline(input, str)) {
			for (char c : str) {
				int cc = int(c);
				if ((cc > 32)&&(cc < 127)) {
					arr[cc-33] += 1;
				}
			}
		}
		input.close();
	}
	std::vector <std::pair<int,int>> vec;
	std::vector<int> pos;
	str.clear();

	for (int i = 0; i < 94; i ++){
		if (arr[i] != 0) {
			vec.push_back(std::make_pair(arr[i], i + 33));
			pos.push_back(i + 33);
			str += " ";
		}
	}
	
	sort(vec.rbegin(), vec.rend());
	str += '\n';

	std::ofstream output;
  	output.open ("output.txt", std::ios::binary );
	if (output.is_open()) {
		for(int i = 0; i < static_cast<int>(vec.size()); i++) {
			auto it = find(pos.begin(), pos.end(), vec[i].second);
			int index = std::distance( pos.begin(), it );
			str.replace(index, 1, "#");
			for (int j = 0; j < vec[i].first - vec[i + 1].first; j++) {
				output << str;
			}
		}
		output << std::string(static_cast<int>(vec.size()), '#') << '\n';
		for(auto i : pos) {
			output << char(i);
		}
		output << '\n';
	}
  	output.close();

	return 0;
}