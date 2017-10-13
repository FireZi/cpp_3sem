#include "ini_parser.h"

#include <fstream>
#include <map>
#include <string>
#include <iostream>


Ini_parser::~Ini_parser() {
	for (auto &sec : data) {
		delete 	sec.second;
	}
}

void Ini_parser::initialize(std::string const &filename_cstr) {
	std::cout << "Initialize is running...\n";
	in.open(filename_cstr);
	std::cout << "file \"" << filename_cstr << "\" opened\n";
	if (!in.good()) {
		std::cerr << "\nFile IO error while opening\n";
	}
	std::string line, cur_section = "";
	while (getline(in, line)) {
		format_line(line);
		std::cout << "\nFormatted line: " << line << "\n";
		if (!line.size()) {
			continue;
		}

		if (line[0] == '[' && line[line.size() - 1] == ']') {
			cur_section = line.substr(1, line.size() - 2);
			std::cout << "Section " << cur_section << " found\n";
			data[cur_section] = new Section();
			continue;
		} 
		
		if (is_correct_ini_param(line) && cur_section.size()) {
			std::string param_name = "";
			std::string param_value = "";
			size_t i = 0;
			while (line[i] != '=') {
				param_name += line[i];
				i++;
			}
			i++;
			while (i < line.size()) {
				param_value += line[i];
				i++;
			}
			data[cur_section]->push(param_name, param_value);
			continue;
		}
		std::cerr << "\nError: Ini line format error in: \n";
		std::cerr << line << "\n";
	}
	std::cout << "\nInitialize finished\n\n\n";
}

bool Ini_parser::is_have_section(std::string const &section_name) const {
	return data.find(section_name) != data.end();
}

bool Ini_parser::is_have_param(std::string const &section_name, std::string const &param_name) const {
	if (is_have_section(section_name)) {
		return data.at(section_name)->is_exists_param(param_name);
	}
	std::cout << section_name << " Section not found\n";
	return false;
}

void Ini_parser::format_line(std::string &line) {
	size_t i = 0;
	std::string new_line = "";
	while (i < line.size() && line[i] != ';') {
		if (line[i] != ' ') {
			new_line += line[i];
		}
		i++;
	}
	line = new_line;
}

bool Ini_parser::is_correct_ini_param(std::string const &line) const {
	size_t i = 0;
	while (i < line.size() && line[i] != '=') {
		i++;
	}
	if (i == line.size()) {
		return false;
	}
	return true;
} 





