#include <iostream>
#include <vector>
#include <iomanip>




using namespace std;

//																		zad1
void fill(vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = i;

	}
}
void show(const vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;

	}
}
//																		zad2
double min_max(vector<double> &vec) {
	double min = vec[0];
	double max = vec[0];

	for (int i = 0; i < vec.size(); i++) {
		if (max < vec[i]) {
			max = vec[i];
		}
		else if (vec[i] < min) {
			min = vec[i];
		}


	}
	cout << min << endl<<max << endl;
	return min,max;
}
//																		zad3
uint64_t ok(int n) {
	uint64_t sum = 1;
	for (int i = 1; i <=n; i++) {
		sum = sum * i;
	}
	cout << sum << endl;
	return sum;

}
//																		zad4
uint64_t rek_s(int n) {
	if (n == 0||n==1) {
		return 1;
	}
	else if (n > 0) {
		return n*rek_s(n - 1);
	}

}
//																		zad5
void lp(int n) {
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			if (n == i) {
				cout << "liczba jest pierwsza" << endl;
				break;
			}
			else {
				cout << "liczba nie jest pierwsza" << endl;
				break;
			}
		}
	}
}
//																		zad6
double lbz(double min) {
	double suma = 1;
	double plus = 3;
	double gran = min;
	for (int i = 0; gran >= min; i++) {
		if (gran < min) {
			break;
		}
		if (i % 2 == 0) {
			suma = suma - 1 / plus;
			gran = 1 / plus;
			plus = plus + 2;
			cout << fixed << setprecision(20) << suma * 4 << endl;
		}
		else {
			suma = suma + 1 / plus;
			gran = 1 / plus;
			plus = plus + 2;
			cout << fixed << setprecision(20) << suma * 4 << endl;
		}

	}

	return suma;

}
//																		zad7
void rysuj(int n, bool l, bool r) {
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == n - 1) {
			for (int y = 0; y < n; y++) {
				cout << "#";

			}
			cout << "" << endl;
		}
		else if (l == false && r == false) {
			cout << "#";
			for (int i = 1; i < n - 1; i++) {
				cout << " ";
			}
			cout << "#";
		}
		else if (l == true && r == false) {
			cout << "#";
			for (int y = 2; y < n; y++) {

				if (y == i + 1) {
					cout << "#";
				}
				else {
					cout << " ";
				}
			}
			cout << "#";
			cout << "" << endl;
		}
		else if (r == true && l == false) {
			cout << "#";
			for (int y = 2; y < n; y++) {

				if (y + i == n) {
					cout << "#";
				}
				else {
					cout << " ";
				}
			}
			cout << "#";
			cout << "" << endl;
		}
		else if (r == true && l == true) {
			cout << "#";
			for (int y = 2; y < n; y++) {

				if (y + i == n || y == i + 1 && n % 2 == 0) {
					cout << "#";
				}
				else if (y + i == n || y == i + 1 && n % 2 == 1) {
					cout << "#";
				}
				else {
					cout << " ";
				}
			}
			cout << "#";
			cout << "" << endl;
		}
		if (l == false && r == false) {
			cout << "" << endl;
		}
	}

}
//																		zad8
int nwd(int a, int b) {
	int c = 0;
	while (b > 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}


int main() {
	
	//																		zad1
	vector<int> v(6);
	fill(v);
	show(v);
	//																		zad2
	vector<double> vv = { 1,43,-122,12,33,4424,-23,22424 };
	min_max(vv);
	//																		zad3
	ok(5);
	//																		zad4
	cout << rek_s(5) << endl;
	//																		zad5
	lp(7);
	//																		zad6
	lbz(0.01);
	//																		zad7
	rysuj(21,true,true);
	//																		zad8
	cout << nwd(12, 2);
	

	return 0;
}

