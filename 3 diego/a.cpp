#include <iostream>
#include <set>
#include <vector>

int main()
{
	int num; 
	std::cin >> num;
	std::set<int> diego;
	for (int i = 0; i < num; i++) {
		int j;
		std::cin >> j;
		diego.insert(j);
	}
	std::cin >> num;
	std::vector<int> colls(num, 0);
	for (int i = 0; i < num; i++) {
		int j;
		std::cin >> j;
		colls[i] = j;
	}

	for (auto i : diego) std::cout << i << " ";
	std::cout<< std::endl;
	
	for (int i = 0; i < static_cast<int>(sizeof(colls)); i++) std::cout << colls[i] << " ";
	std::cout<< std::endl;

	for (int i = 0; i < static_cast<int>(sizeof(colls)); i++) {
		int counter = 0; 
		for (int j: diego){
			if ( j < colls[i]) counter++;
			else {
				std::cout << counter << " ";
				break;
			}
		}
	}
	return 0;
}
