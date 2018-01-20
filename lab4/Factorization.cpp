#include <vector>
#include <fstream>
#include <iostream>
#include "Factorization.h"


Factorization::Factorization() {
	mprime.resize(size_);
	for (int i = 2; i < (int)size_; i++) {
		if (mprime[i] == 0) {
			mprime[i] = i;
			primes.push_back(i);
		}
		for (size_t j = 0; j < size_ && primes[j] <= mprime[i] && i * primes[j] <= (int)size_; j++) {
			mprime[i * primes[j]] = primes[j];
		}
	}
}


std::vector<uint64_t> Factorization::get_factorization(uint64_t const n) const {
	uint64_t num = n;
	std::vector<uint64_t> res;
	for (int i = 0; i < (int)primes.size() && num >= size_; i++) {
		while (num % primes[i] == 0) {
			res.push_back(primes[i]);
			num /= primes[i];
		}
	}
	if (num < size_) {
		while (num > 1) {
			res.push_back(mprime[num]);
			num /= mprime[num];
		}
	} else {
		for (uint64_t i = size_; i * i <= num; i++) {
			while (num % i == 0) {
				res.push_back(i);
				num /= i;
			}
		}
		if (num > 1) {
			res.push_back(num);
		}
	}
	return std::move(res);
}


void Factorization::file_factorize(char const * const file_in, char const * const file_out) const {
	std::ifstream in(file_in);
    std::ofstream out(file_out);
    if (!in.good() || !out.good()) {
        std::cerr << "File IO error while opening\n";
    }
    uint64_t n;
    while (in >> n) {
    	std::cout << n << "\n";
    	std::vector<uint64_t> res = get_factorization(n);
    	out << n << " factorization is: ";
    	for (size_t i = 0; i < res.size(); i++) {
    		out << res[i] << " ";
    		if (i != res.size() - 1) {
    			out << "* ";
    		}
    	}
    	out << "\n";
    }
    in.close();
    out.close();
}