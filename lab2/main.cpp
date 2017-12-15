#include "StatisticMultiset.h"

#include <iostream>
#include <vector>
#include <set>
#include <list>

int main() {
	std::vector<int> v = {42, 17};
	std::list<int> l = {-5, 1, 3};
	std::multiset<int> ms = {8};

	StatisticMultiset<int> s;

	s.add_num(4);
	s.add_num(v);
	s.add_num(s);
	s.add_num(l);
	s.add_num(ms);

	std::cout << s.get_min() << '\n';
	std::cout << s.get_max() << '\n';
	std::cout << s.get_avg() << '\n';
	std::cout << s.get_count_under(5) << '\n';
	std::cout << s.get_count_above(8) << '\n';
}