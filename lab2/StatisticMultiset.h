#pragma once

#include <vector>
#include <set>
#include <list>


template <typename T>
struct StatisticMultiset {

	StatisticMultiset();

	void add_num(T const &num);
	void add_num(std::multiset<T> const &numbers);
	void add_num(std::vector<T> const &numbers);
	void add_num(std::list<T> const &numbers);
	void add_num(StatisticMultiset<T> const &numbers);
	void add_nums_from_file(char const * const filename);
	
	T get_max() const;
	T get_min() const;
	float get_avg() const;
	int get_count_under(float const &threshold) const;
	int get_count_above(float const &threshold) const;
	

private:
	std::multiset <T> data;
	T sum;
};

#include "StatisticMultiset.cpp"