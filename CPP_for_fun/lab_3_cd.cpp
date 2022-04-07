#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <sstream>
#include <fstream>
enum class TypRosliny { Owoc, Warzywo };

struct Roslina
{
	TypRosliny typ;
	std::string nazwa;
};


struct day {

	std::string date;
	double usd;
	double eur;
	std::string num;

};
using Koszyk = std::vector<Roslina>;
using days = std::vector<day>;

Koszyk fill(Koszyk &kosz) {
	std::vector<std::string>nazwa1 = {"banan","jarmuz","gruszka","pomidor"};

	
	for (int i = 0; i <nazwa1.size(); ++i) {
		Roslina ros;
		ros.nazwa = nazwa1[i];
		if (i % 2 == 0) {
			ros.typ = TypRosliny::Owoc;
		}
		else {
			ros.typ = TypRosliny::Warzywo;
		}
		kosz.emplace_back(ros);
	}


	return kosz;
}
Koszyk fill2(Koszyk& kosz) {
	std::vector<std::string>nazwa1 = { "jablko","jarmuz","gruszka","ogorek" };


	for (int i = 0; i < nazwa1.size(); ++i) {
		Roslina ros;
		ros.nazwa = nazwa1[i];
		if (i % 2 == 0) {
			ros.typ = TypRosliny::Owoc;
		}
		else {
			ros.typ = TypRosliny::Warzywo;
		}
		kosz.emplace_back(ros);
	}


	return kosz;
}



std::ostream& operator<<(std::ostream& out, const Roslina& roslina) { 
	std::string typ;
	if (roslina.typ == TypRosliny::Owoc) {
		typ = "Owoc";
	}
	else {
		typ = "Warzywo";
	}

	return out << roslina.nazwa << " - " << typ;
 

}


std::ostream& operator<<(std::ostream& out, const Koszyk& koszyk) {

	for (auto itr = koszyk.begin(); itr != koszyk.end(); ++itr) {
		 return  out << *itr;
	}
}

std::ostream& operator<<(std::ostream& out, const day& day) {

	return out << day.date << " - " << day.usd << " - " << day.eur << " - " << day.num;
}

std::ostream& operator<<(std::ostream& out, const days& koszyk) {

	for (auto itr = koszyk.begin(); itr != koszyk.end(); ++itr) {
		return  out << *itr;
	}
}
//return out << day.date << " - " << day.usd << " - " << day.eur << " - " << day.num;

bool czy_jest_gruszka_pom(Roslina ok) {
	if (ok.nazwa == "gruszka") {
		return true;
	}
	else {
		return false;
	}



}
bool czy_jest_gruszka(Koszyk &koszyk) {

	auto is = std::find_if(koszyk.begin(), koszyk.end(), czy_jest_gruszka_pom);
	
	if (is != koszyk.end()) {
		std::cout << "jest" << std::endl;
		return true;
		
	}else{
		std::cout << "nie jest" << std::endl;
		return false;
		
	}

	

}

bool czy_same_owoce(const Koszyk& koszyk) {
	return std::all_of(koszyk.begin(), koszyk.end(),
		[](const Roslina& roslina) { return roslina.typ == TypRosliny::Owoc; }
	);
}

bool czy_brak_owoc(const Koszyk& koszyk) {
	return std::none_of(koszyk.begin(), koszyk.end(),
		[](const Roslina& roslina) { return roslina.typ != TypRosliny::Owoc; }
	);
}


int zlicz_owoce(const Koszyk& koszyk) {
	return std::count_if(koszyk.begin(), koszyk.end(), [](const Roslina& roslina) {
		return roslina.typ == TypRosliny::Owoc;
		});
}

int zlicz_warzywa(const Koszyk& koszyk) {
	return std::count_if(koszyk.begin(), koszyk.end(), [](const Roslina& roslina) {
		return roslina.typ == TypRosliny::Warzywo;
		});
}



Koszyk del_od_lit(Koszyk& koszyk,  std::string lit) {
	
	koszyk.erase(std::remove_if(koszyk.begin(), koszyk.end(),
		[lit](const Roslina& roslina) {
			return roslina.nazwa[0] == lit[0];
		}),koszyk.end());

	return koszyk;


}
bool operator<(const Roslina& r1, const Roslina& r2) {

	if (r1.nazwa > r2.nazwa) {
		return true;
	}
	else {
		return false;
	}

}

bool operator<(const day& r1, const day& r2) {

	if (r1.usd > r2.usd) {
		return true;
	}
	else {
		return false;
	}

}





days fi(days &lista) {

	std::fstream fin;

	fin.open("kursy_usd_eur.csv", std::fstream::in);

	std::string word;

 	while (std::getline(fin, word)) {

		std::stringstream strs(word);
		day ok;

		std::getline(strs, ok.date, ',');
		std::string usd_t;
		std::getline(strs, usd_t, ',');
		ok.usd = stod(usd_t);
		std::string eur_t;
		std::getline(strs, eur_t, ',');
		ok.eur = stod(eur_t);
		getline(strs, ok.num, ',');

		lista.emplace_back(ok);
	}
	std::cout << lista.size()<<std::endl;
	return lista;



}




int main() {
	Koszyk koszyk;
	Koszyk koszyk2;
	fill(koszyk);
	fill2(koszyk2);

	days lista;

	






	for (auto itr = koszyk.begin(); itr != koszyk.end(); ++itr) {
		std::cout << *itr<<std::endl;
	}
	
	czy_jest_gruszka(koszyk);

	if (czy_same_owoce(koszyk) == true) {
		std::cout << "tak same owoce" << std::endl;

	}
	else {
		std::cout << "nie same owoce"<<std::endl;
	}

	if (czy_brak_owoc(koszyk) == true) {
		std::cout << "tak brak owoc" << std::endl;

	}
	else {
		std::cout << "nie, sa owoce" << std::endl;
	}


	std::cout << zlicz_owoce(koszyk) << std::endl;
	std::cout << zlicz_warzywa(koszyk) << std::endl;

	//del_od_lit(koszyk, "g");
	for (auto itr = koszyk.begin(); itr != koszyk.end(); ++itr) {
		std::cout << *itr << std::endl;
	}


	auto compare = [](Roslina a, Roslina b) {return a < b; };


	std::sort(koszyk.begin(), koszyk.end(), compare);

	std::sort(koszyk2.begin(), koszyk2.end(), compare);
	std::cout << std:: endl;
	for (auto itr = koszyk.begin(); itr != koszyk.end(); ++itr) {
		std::cout << *itr << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	for (auto itr = koszyk2.begin(); itr != koszyk2.end(); ++itr) {
		std::cout << *itr << std::endl;
	}

	Koszyk koszyk_wspolne;
	std::set_intersection(koszyk.begin(), koszyk.end(),
	koszyk2.begin(), koszyk2.end(),
	std::back_inserter(koszyk_wspolne));


	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << koszyk_wspolne << std::endl;

	Koszyk roznica;
	std::set_difference(koszyk.begin(), koszyk.end(),
	koszyk2.begin(), koszyk2.end(),
	std::back_inserter(koszyk_wspolne));


	Koszyk all;

	std::cout << std::endl;
	std::set_union(koszyk.begin(), koszyk.end(), koszyk2.begin(), koszyk2.end(), std::back_inserter(all));

	for (auto itr = all.begin(); itr != all.end(); ++itr) {
		std::cout << *itr << std::endl;
	}




	std::cout << std::endl;
	std::cout << std::endl;



	fi(lista);


	


	auto gr = [](day a, day b) {return a < b; };

	std::sort(lista.begin(), lista.end(), gr);
	

	for (auto itr = lista.begin(); itr != lista.end(); ++itr) {
		std::cout << *itr << std::endl;
	}






	

	





	return 0;
}