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
		int counter = 0; 
		for (int j: diego){
			if (j < i) counter++;
			else break;
		}
		output << counter << "\n";
	}
	output.close();
	return 0;
}
