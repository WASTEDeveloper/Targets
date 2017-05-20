#include "Product.h"

void toXML(std::string filename) {
	std::ifstream fin(filename + ".txt");
	std::ofstream fout(filename + ".xml", std::ios_base::trunc);

	if (!fin.is_open() || !fout.is_open())	return;
	
	std::string input, data;
	std::string output = "<article>";

	fout << "<article>" << "\n";
	fin >> input;
	fout << "<title>" << input << "</title>" << "\n";
	fin >> input;
	std::vector<std::string> authors = parse(input);

	for (auto it = authors.begin(); it != authors.end(); it++) fout << "<author>" << (*it) << "</author>" << "\n";

	fout << "<text>" << "\n";
	fin >> input;
	while (!fin.eof()){
		data += input;	// for hashcode
		fout << input;
		fin >> input;
	}
	fout << "</text>" << "\n";

	std::hash<std::string> hash_fn;
	size_t hash = hash_fn(data);

	fout << "<hashcode>" << "\n" << hash << "\n" << "</hashcode>" << "\n";

	if (hash != std::stoul(input)) fout << "<warning>" << "\n" << "Hashcodes mismatch!" << "\n" << "</warning>" << "\n";

	fout << "</article>";

	fout.close();
	fin.close();
}

std::vector<std::string>parse(std::string toParse) {
	std::vector<std::string> authors(0);
	std::string name;

	auto it = toParse.begin();
	while (it != toParse.end()) {
		if ((*it) == ',') {
			authors.emplace_back(name);
			name.erase();
		}
		else { 
			name += (*it); 
		}
		it++;
	}
	authors.emplace_back(name);

	return authors;
}
