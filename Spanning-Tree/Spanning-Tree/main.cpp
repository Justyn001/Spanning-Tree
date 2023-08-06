#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "headlines.h"

int main(int dlugosc_tablicy, char* tablica[])
{
	//if (dlugosc_tablicy == 5)
		//std::cout << "6";
	//std::string input_file, output_file;
	//input_file = tablica[2];
	//output_file = tablica[4];
	/*for (int i = 1;i < dlugosc_tablicy;i++)
	{
		std::cout << tablica[i] << " ";
		if (std::string(tablica[i]) == "-g")
			input_file = tablica[i + 1];
		if (std::string(tablica[i]) == "-d")
			output_file = tablica[i + 1];
	}
	
	if (input_file.empty())
	{
		std::cout << "Nie podano nazwy pliku";
		exit(0);
	}
	*/

	const int N{ 100 };
	std::vector<int> wektor(N);

	const std::string input_file{ "graph.txt" };
	const std::string output_file{ "minimal_tree.txt" };
	std::map<double, std::pair<int, int>> graf = read_file(input_file);

	std::map<double, std::pair<int, int>> minimalne_drzewo = kruskal(graf, wektor);

	save_file(minimalne_drzewo, output_file);
	return 0;
};