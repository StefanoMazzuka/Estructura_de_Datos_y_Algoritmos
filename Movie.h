#ifndef MOVIE_H_
#define MOVIE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>

#include "Hour.h"

class Movie {

public:

	// Constructora
	Movie() {};
	Movie(Hour end, std::string title) : end(end), title(title) {};

	Hour get_end() const { return this->end; };
	std::string get_title() const { return this->title; };

private:
	Hour end;
	std::string title;
};

inline std::ostream &operator<<(std::ostream &out, Movie const &m) {
	out << m.get_end() << " " << m.get_title();

	return out;
}
#endif