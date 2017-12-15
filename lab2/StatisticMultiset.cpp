#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <fstream>


template <typename T>
StatisticMultiset<T>::StatisticMultiset() : sum(0) {}


template <typename T>
void StatisticMultiset<T>::add_num(T const &num) {
	data.insert(num);
	sum += num;
}


template <typename T>
void StatisticMultiset<T>::add_num(std::multiset<T> const &numbers) {
	for (auto &i : numbers) {
		add_num(i);
	}
}


template <typename T>
void StatisticMultiset<T>::add_num(std::vector<T> const &numbers) {
	for (auto &i : numbers) {
		add_num(i);
	}
}


template <typename T>
void StatisticMultiset<T>::add_num(std::list<T> const &numbers) {
	for (auto &i : numbers) {
		add_num(i);
	}
}


template <typename T>
void StatisticMultiset<T>::add_num(StatisticMultiset<T> const &numbers) {
	if (this == &numbers) {
		std::vector <T> tmp;
		for (auto &i : numbers.data) {
			tmp.push_back(i);
		}
		for (size_t i = 0; i < tmp.size(); i++) {
			add_num(tmp[i]);
		}
	} else {
		add_num(numbers.data);
	}
}


template <typename T>
void StatisticMultiset<T>::add_nums_from_file(char const * const filename) {
	std::ifstream in(filename);
	if (!in.good()) {
		std::cerr << "File IO error while opening\n";
	}
	T cur;
	while(in >> cur) { 
		add_num(cur);
	}
}


template <typename T>
T StatisticMultiset<T>::get_min() const {
	return *data.begin();
}


template <typename T>
T StatisticMultiset<T>::get_max() const {
	return *data.rbegin();
}


template <typename T>
float StatisticMultiset<T>::get_avg() const {
	if (data.size() == 0) {
		std::cerr << "StatisticMultiset is empty.\n";
	}
	return (float)sum / data.size();
}


template <typename T>
int StatisticMultiset<T>::get_count_under(float const &threshold) const {
	int res = 0;
	for (auto i = data.begin(); i != data.end() && *i < threshold; i++) {
		res++;
	}
	return res;	 
}


template <typename T>
int StatisticMultiset<T>::get_count_above(float const &threshold) const {
	int res = 0;
	for (auto i = data.rbegin(); i != data.rend() && *i > threshold; i++) {
		res++;
	}
	return res;
}
