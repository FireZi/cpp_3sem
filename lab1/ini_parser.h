#pragma once

#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <sstream>

struct Ini_parser {
	~Ini_parser();

	// Opens Ini file.
	void initialize(std::string const &filename_cstr);

	// Checks if a section exists.
	bool is_have_section(std::string const &section_name) const;

	// Checks if a pair param-section exists.
	bool is_have_param(std::string const &section_name, std::string const &param_name) const;

	// Returns value for a pair param-section.
	template <typename T>
	T get_value(std::string const &section_name, std::string const &param_name) const {
		std::stringstream ss;
		T result;
		ss << map.at(section_name)->get(param_name);
		ss >> result;
		return result;
	}

private:
	struct Section {
		std::map <std::string, std::string> map;

		void push(std::string const &param_name, std::string const &param_value) {
			map[param_name] = param_value;
			std::cout << "Parameter added.\n";
			std::cout << "name: " << param_name << "\n";
			std::cout << "value: " << param_value << "\n";
		}

		bool is_exists_param(std::string const &param_name) const {
			return map.find(param_name) != map.end();
		}

		std::string get(std::string const &param_name) const {
			return map.at(param_name);
		}
	};

	void format_line(std::string &line);

	bool is_correct_ini_param(std::string const &line) const;

	std::ifstream in;
	std::map <std::string, Section*> map;
};