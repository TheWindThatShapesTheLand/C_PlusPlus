//Ќаходим совершенные числа из числа чисел unsigned long long
#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(unsigned long long n) {
	unsigned long long i = 2;
		while (i < sqrt(n)) {
			if (n % i == 0) return false;
			i += 1;
		}
	return true;
}

int main() {
	unsigned long long k, n = 2;
	while (k = 2 * n - 1) {
		if (is_prime(k)) cout << n * k << " ";
		n <<= 1;
	}
	return 0;
}