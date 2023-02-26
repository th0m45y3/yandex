#include <iostream>
#include <set>
#include <vector>
#include <fstream>

int main()
{
	int num; 
	std::set<int> diego;
	std::ifstream input("input.txt");
	input >> num;
	for (int i = 0; i < num; i++) {
		int j;
		input >> j;
		diego.insert(j);
	}
	input >> num;
	std::vector<int> colls;
	for (int i = 0; i < num; i++) {
		int j;
		input >> j;
		colls.push_back(j);
	}
	input.close();
	
	std::ofstream output("output.txt");
	for (int i : colls) {
    	if (i <= *diego.begin()) {
        	output << 0 << "\n";
        	continue;
        }
    	else if (i > *diego.rbegin()) {
        	output << static_cast<int>(diego.size()) << "\n";
        	continue;
        }
		auto id = diego.find(i);
		if (id == diego.end()) {
			diego.insert(i);
			auto id = diego.find(i);
			int index = std::distance( diego.begin(), id );
        	output << index << "\n";
			diego.erase(id); 
		}
		else {
			int index = std::distance( diego.begin(), id );
			output << index << "\n";
		}
	}
	output.close();
	return 0;
}
