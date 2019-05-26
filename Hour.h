#ifndef HOUR_H_
#define HOUR_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>

class Hour {

public:

	// Constructora
	Hour() {};
	Hour(int HH, int MM, int SS) : HH(HH), MM(MM), SS(SS) {
		if (HH < 0 || HH > 23 || MM < 0 || MM > 59 || SS < 0 || SS > 59)
			throw std::invalid_argument("ERROR");
	};

	int get_HH() const { return this->HH; };
	int get_MM() const { return this->MM; };
	int get_SS() const { return this->SS; };

	bool operator<(Hour const& h) const {
		if (HH < h.get_HH()) return true;
		else if (HH > h.get_HH()) return false;
		else if (MM < h.get_MM()) return true;
		else if (MM > h.get_MM()) return false;
		else if (SS < h.get_SS()) return true;
		else return false;
	}

	bool operator==(Hour const& h) const {
		if (HH == h.get_HH() && MM == h.get_MM() && SS == h.get_SS()) return true;
		else return false;
	}

	Hour operator+(Hour const &h) const {
		int HH = this->HH + h.get_HH();
		int MM = this->MM + h.get_MM();
		int SS = this->SS + h.get_SS();

		if (SS > 59) { MM += SS / 60; SS = SS % 60; }
		if (MM > 59) { HH += MM / 60; MM = MM % 60; }
		if (HH > 23) HH = HH % 60;

		Hour hSum(HH, MM, SS);

		return hSum;
	}

private:
	int HH;
	int MM;
	int SS;
};

inline std::istream &operator>>(std::istream &in, Hour &h) {
	char dot;
	int HH;
	int MM;
	int SS;
	in >> HH >> dot >> MM >> dot >> SS;
	Hour h2(HH, MM, SS);
	h = h2;
	return in;
}

inline std::ostream &operator<<(std::ostream &out, Hour const &h) {
	if (h.get_HH() < 10) out << "0" << h.get_HH() << ":";
	else out << h.get_HH() << ":";

	if (h.get_MM() < 10) out << "0" << h.get_MM() << ":";
	else out << h.get_MM() << ":";

	if (h.get_SS() < 10) out << "0" << h.get_SS();
	else out << h.get_SS();

	return out;
}
#endif