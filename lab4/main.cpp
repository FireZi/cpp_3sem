#include <iostream>
#include <vector>
#include "Factorization.h"

int main(int argc, char ** argv) {
	Factorization f;
	f.file_factorize(argv[1], argv[2]);
}