#pragma once

#include <string>
#include <fstream>
#include <vector>

#include "Product.h"

class Director {
public:
	class ConverterXML;

	Director(std::string _filename) : filename(_filename) {};

	void convertXML();
private:
	std::string filename;
};

class Director::ConverterXML {
public:
	void convert(std::string);
};