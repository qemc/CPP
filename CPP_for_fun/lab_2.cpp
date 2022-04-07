#include <iostream>
#include <string.h>
#include<algorithm>
#include <vector>
using namespace std;
//																							ZAD 1
void is_palindrome(string word) {
	int licz = 0;
	for (size_t u = 0; u < word.size(); u++) {
		if (word[u] == ' ') {
			licz++;
		}
	}
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	remove(word.begin(), word.end(), ' ');
	string wordd = word;

	for (size_t i = 0; i < (wordd.size()/2) + (wordd.size()%2)-licz; i++) {
		if (wordd[i] != wordd[wordd.size()-licz - (i + 1)]) {
			cout << "to nie palindrom ";
			break;
		}
		else if (i== (wordd.size() / 2) + (wordd.size() % 2)-licz - 1) {
			cout << "to jest palindrom";
		}
	}
}
//																							ZAD 2
vector<int> find_all(string letter, string word) {
	vector<int> poz;
	for (size_t i = 0; i < word.size(); i++) {
		if (word[i] == letter[0]) {
			poz.emplace_back(i);
	
		}
	}
	return poz;


}

//																							ZAD 3
void the_lgnst(string word) {
	int pam = 0;
	int accual = 0;
	int licz = 0;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] != ' ') {
			licz++;
		}
		else if (accual<licz) {
			accual = licz;
			pam = i - licz;
			licz = 0;
		}
		else {
			licz = 0;
		}
	}
	if (accual < licz) {
		accual = licz;
		pam = word.size() - licz;
		licz = 0;
	}
	for (int i = pam; i < word.size(); i++) {
		if (word[i] == ' ') {
			break;
		}
		else {
			cout<<word[i];
		}
	}



}

//																							ZAD 4
void split(string sentence, string ok = " ") {
	vector<string> str;
	string przech = "";
	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] != ok[0]) {
			przech = przech + sentence[i];
		
		}
		if(sentence[i] == ok[0] || i == sentence.size() - 1) {
			if (i != sentence.size() - 1) {
				przech.append(",");
			}
			str.emplace_back(przech);
			przech = "";
			
		}
		
	}

	for (int i = 0; i < str.size(); i++) {
		cout << str[i];
	}

}
//																							ZAD 5
void find_and_replace(string text, string find, string replace) {
	int licz = 0;
	int ile = 0;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == find[0]) {
			for (int u = 0; u < find.size(); u++) {
				if (text[i + u] == find[u]) {
					licz++;
				}
				else {
					break;
				}
			}
			if (licz == find.size()) {
				ile++;
				licz = 0;
			}
			else {
				licz = 0;
			}
		}
	}

	cout << ile;

	for(int i = 0; i < ile; i++) {
		text.replace(text.find(find), find.size(), replace);
	}
	cout << text;
}

void fill(vector<int>& ok) {
	for (int i = 0; i < ok.size(); i++) {
		ok[i] = rand() % 100;
		cout << ok[i]<<" ";
	}

}
//																							ZAD 6
void bubble_sort(vector<int>& ok) {

	for (int i = 0; i < ok.size(); i++) {
		for (int j = 0; j < ok.size()-1; j++) {
			if (ok[i] > ok[j]) {
				int k = ok[j];
				ok[j] = ok[i];
				ok[i] = k;
			}
			

		}
	}
	cout << " "<<endl;

	for (int j = 0; j < ok.size(); j++) {
		cout << ok[j]<<" ";

	}
				


}
//																							ZAD 7
void binary_search(vector<int>& vv,int src) {
	int l = 0;
	int p = vv.size();
	int id = 0;
	while (l<p) {
		int id = (l+p)/2 + (vv.size() % 2);
		if (vv[id] < src) {
			l = id+1;
		}else{
			p = id;
		}
		if (vv[id] == src) {
			cout << id << endl;
		}
	}
	

	



}


int main() {
	//																							ZAD 1
	is_palindrome("Never odd or even");


	
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	//																							ZAD 2
	for (int i : find_all("a","Ala ma kota" )) {
		cout << i <<" ";
	}
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	//																							ZAD 3
	the_lgnst("Ala dsdsdsdsd madddd ");

	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	//																							ZAD 4
	split("Ala,ma,kota", ",");

	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	//																							ZAD 5
	find_and_replace("Ala ma kot, duzy kota, kot, kot", "kot", "pies");

	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;


	vector<int> vvv(20);
	fill(vvv);
	vector<int> v;
	//																							ZAD 6
	bubble_sort(vvv);
	for (int i = 0; i < 100; i++) {
		v.emplace_back(i);
		cout << v[i] << endl;
	}



	//																							ZAD 7
	for (int i = 0; i < 100; i++) {
		binary_search(v, i);
	}


	

	return 0;
}