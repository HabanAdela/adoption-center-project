#pragma once
#include <string>
#include <exception>

class Exception : public std::exception {
private:
	std::string message;
public:
	Exception(std::string message) : message(message) {};
	std::string getMessage()
	{
		return this->message;
	}
};
