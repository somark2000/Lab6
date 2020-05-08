#pragma once
#include <string>
#include "Filme.h"
#include <vector>

class MovieException
{
private:
	std::vector<std::string> errors;

public:
	MovieException(std::vector<std::string> _errors);
	std::vector<std::string> getErrors() const;
};

class MovieValidator
{
public:
	MovieValidator() {}
	static void validate(const Filme& m);
};

