#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <list>
int randomInt(int min, int max) {
	static std::default_random_engine e{ static_cast<long unsigned int>(time(0)) };
	std::uniform_int_distribution<int> d{ min, max };
	return d(e);
}
std::vector<int> fill(int n, std::vector<int>&v) {
	for (int i = 0; i < n; i++) {
		v.emplace_back(randomInt(-20, 20));
	}
	return v;

}

std::vector<int> del(std::vector<int>& s) {
	int i;
	std::cout << "podaj liczbe do usuniecia" << std::endl;
	std::cin >> i;

	s.erase(std::find(s.begin(), s.end(), i));
	 

	 return s;
}

std::list<int> fill_lista(std::list<int>&lista1, int l_element) {

	for (int i = 0; i < l_element; i++) {
		lista1.emplace_back(randomInt(-20, 20));
	}
	return lista1;
}

auto licz(std::list<int>lista) {
	std::vector<int>ok;

	for (auto itr = lista.begin(); itr != lista.end(); ++itr) {
		
		std::cout << *itr << " - " << std::count(lista.begin(), lista.end(), *itr) << std::endl;
			
		
	}


}


int main() {
	std::vector<int> vv;
	fill(10, vv);

	for (auto itr = vv.begin(); itr != vv.end(); ++itr) {

		std::cout << *itr << std::endl;
	}

	//del(vv);
	std::cout << std::endl;




	std::list<int>lista;


	std::cout << std::endl;


	fill_lista(lista, 10);
	for (auto it = lista.begin(); it != lista.end(); ++it) {
		
		std::cout << *it << std::endl;
	}


	std::cout << std::endl;
	std::cout << "Min element by min_element" << std::endl;
	auto min_e  = std::min_element(vv.begin(),vv.end());
	std::cout << *min_e << std::endl;
	std::cout << std::endl;
	std::cout << "Max & min element by minmax_element from list" << std::endl;
	auto minmax = std::minmax_element(lista.begin(), lista.end());
	std::cout << *minmax.first << std::endl;
	std::cout << *minmax.second;


	std::stable_sort(lista.begin(), lista.end(),std::greater<>());
	std::cout << std::endl;
	std::cout << std::endl;

	for (auto it = lista.begin(); it != lista.end(); ++it) {

		std::cout << *it << std::endl;
	}

	auto compare = [](int a, int b) {return a > b; };

	std::sort(vv.begin(), vv.end(), compare);
	std::cout << std::endl;
	std::cout << std::endl;
	for (auto it = vv.begin(); it != vv.end(); ++it) {

		std::cout << *it << std::endl;
	}

	licz(lista);

	



	return 0;
}