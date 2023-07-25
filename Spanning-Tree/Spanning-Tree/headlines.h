#ifndef headlines_h
#define headlines_h


/**@file*/
/**
* @param x pierwszy wierzcholek grafu
* @param tablica wektor sprawdzajacy
* @return zwraca wartosc z wektora
*/
int sprawdz(int x, std::vector<int> tablica);

/**
* @param x pierwszy wierzcholek grafu
* @param y drugi wierzcholek grafu
* @param tablica wektor
*/
void dodaj(int x, int y, std::vector<int>& tablica);

std::map<double, std::pair<int, int>> read_file(std::string file_name);

std::map<double, std::pair<int, int>> kruskal(std::map<double, std::pair<int, int>> graf, std::vector<int>& wektor);

void save_file(std::map<double, std::pair<int, int>>, std::string output_file);

#endif