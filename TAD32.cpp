/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using key = std::string;
using value = int;

struct tData {
	std::string sport;
	int count;
};

bool sortSports(tData a, tData b) {
	return (a.count > b.count || (a.count == b.count && a.sport < b.sport));
}

bool isSport(std::string sport) {
	int lenght = sport.size();
	for (int i = 0; i < lenght; ++i)
		if (islower(sport.at(i))) return false;
	return true;
}

bool resuelveCaso() {

	key myKey;
	std::cin >> myKey;

	if (!std::cin) return false;
	
	std::map<key, value> sportList;
	int i = 0;
	while (myKey != "_FIN_") {
		if (isSport(myKey)) sportList[myKey] = i;
		else if (sportList.find(myKey) != sportList.end()) {
			if (sportList[myKey] != i) {
				sportList[myKey] = -1;
			}
		}
		else sportList[myKey] = i;
		std::cin >> myKey;
		if (isSport(myKey)) ++i;
	}

	auto it = sportList.begin();
	std::vector<tData> sportCount(i, {"", 0});
	while (it != sportList.end()) {
		if (it->second != -1) {
			if (isSport(it->first)) sportCount[it->second].sport = it->first;
			else sportCount[it->second].count += 1;
		}
		++it;
	}

	sort(sportCount.begin(), sportCount.end(), sortSports);

	int lenght = sportCount.size();
	for (int i = 0; i < lenght; ++i) {
		std::cout << sportCount[i].sport << " " 
			<< sportCount[i].count << '\n';
	}

	std::cout << "***" << '\n';
	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD32.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}