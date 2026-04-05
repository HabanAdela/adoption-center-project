#include "Utils.h"
#include <sstream>

std::vector<std::string> tokenize(std::string input, char separator) {
	std::stringstream is{ input };
	std::vector<std::string> result;
	std::string token;

	while (getline(is, token, separator))
		result.push_back(token);

	return result;
}