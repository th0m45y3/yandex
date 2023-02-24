#include <iostream>
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
					//std::cout << c << ":" << cc << "\t NEW VAL = " << arr[cc-33] << std::endl;
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
	//std::cout << str.length() << std::endl;
	str += "\n";

	std::ofstream output;
  	output.open ("output.txt");
	if (output.is_open()) {
		for(int i = 0; i < static_cast<int>(vec.size()); i++) {
			auto it = find(pos.begin(), pos.end(), vec[i].second);
			//std::cout<< "i = " << i << "\nvec i sec = " << vec[i].second << "\nit = " << *it << std::endl;
			int index = std::distance( pos.begin(), it );
			//std::cout<< "index = " << index << std::endl;
			// str[index] = "#";
			str.replace(index, 1, "#");
			//std::cout << str << std::endl;
			for (int j = 0; j < vec[i].first - vec[i + 1].first; j++) {
				output << str;
			}
		}
		output << std::string(static_cast<int>(vec.size()), '#') << std::endl;
		for(auto i : pos) {
			output << char(i);
		}
	}
  	output.close();

	// for (int i = 0; i < sizeof(arr); i++) {
	// 	std::cout << i+33 << ": " << arr[i] << std::endl;
	// }
	
	// for (auto i : vec) {
	// 	std::cout << i.first << " : " << i.second << "; ";
	// }
	// std::cout << std::endl;
	// for (auto i : pos) {
	// 	std::cout << i << "; ";
	// }
	
	// std::cout << std::endl << str << ")";

	return 0;
}