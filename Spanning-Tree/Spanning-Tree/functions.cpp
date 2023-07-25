#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include "headlines.h"

//Funkcja zczytuje z pliku dane i zapisuje do mapy 

std::map <double, std::pair<int, int>> read_file(std::string file_name)
{
	std::map<double, std::pair<int, int>> graf;
	std::ifstream plik_wejsciowy(file_name);
	char znak;
	int _w1, _w2;
	double _waga;
	if (plik_wejsciowy)
	{
		while (plik_wejsciowy >> znak >> _w1 >> znak >> _w2 >> znak >> _waga >> znak >> znak)
		{
			auto para_wierz = std::make_pair(_w1, _w2);
			for (auto mapa : graf)
			{
				if (mapa.first == _waga)
					_waga += 0.0000001;
			}
			graf[_waga] = para_wierz;
		}
		for (auto mapa : graf)
		{
			std::cout << mapa.first << ": " << mapa.second.first << " " << mapa.second.second << std::endl;
		}
	}
	return graf;
}



int sprawdz(int x, std::vector<int> tablica)
{
	if (tablica[x] == x)
		return x;
	return sprawdz(tablica[x], tablica);
}

void dodaj(int x, int y, std::vector<int>& tablica)
{
	x = sprawdz(x, tablica);
	y = sprawdz(y, tablica);
	tablica[x] = y;
}

std::map<double, std::pair<int, int>> kruskal(std::map<double, std::pair<int, int>> graf, std::vector<int>& wektor)
{
	std::map<double, std::pair<int, int>> minimalne_drzewo;
	for (int i = 0;i < wektor.size();i++)
		wektor[i] = i;

	for (const auto& d : graf)
	{
		double waga = d.first;
		int v1 = d.second.first;
		int v2 = d.second.second;
		if (sprawdz(v1, wektor) != sprawdz(v2, wektor))
		{
			dodaj(v1, v2, wektor);
			auto para = std::make_pair(v1, v2);
			minimalne_drzewo[waga] = para;
		}
	}
	return minimalne_drzewo;
}

void save_file(std::map<double, std::pair<int, int>> minimalne_drzewo, std::string output_file)
{
	std::ofstream plik_wyjsciowy(output_file);
	if (plik_wyjsciowy)
	{
		for (auto d : minimalne_drzewo)
		{
			double waga = d.first;
			int v1 = d.second.first;
			int v2 = d.second.second;
			plik_wyjsciowy << "(" << v1 << ", " << v2 << ", " << waga << "), ";
		}
	}
}