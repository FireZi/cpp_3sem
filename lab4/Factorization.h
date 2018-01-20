// #pragma once 

#include <vector>
#include <cstdint>

struct Factorization {
	Factorization();

	std::vector<uint64_t> get_factorization(uint64_t const) const;

	void file_factorize(char const * const, char const * const) const;

private:
	static std::size_t const size_ = (int)1e7;
	std::vector<int> mprime;
	std::vector<int> primes;
};