#include "ini_parser.h"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
	std::string file_name = argv[1];
	Ini_parser parser;
	parser.initialize(file_name);

	std::cout << parser.is_have_section("DEBUG") << "\n";
	std::cout << parser.is_have_section("BUG") << "\n";
	std::cout << parser.is_have_param("NCMD", "SampleRate") << "\n"; 
	std::cout << parser.is_have_param("NCMD", "DBAddressIP") << "\n";
	std::cout << parser.is_have_param("NCMD_1", "SampleRate") << "\n";
	std::cout << parser.get_value<std::string>("DEBUG", "DBAddressIP") << "\n";
	std::cout << parser.get_value<int>("NCMD", "EnableChannelControl") << "\n";
}