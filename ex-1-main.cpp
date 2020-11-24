// sample.cpp

#include <iostream>
using namespace std;
#define CPP2_PRIME_UPPER_LIMIT 1000000 //’Tõ‚·‚é’l‚ÌãŒÀ’lB

int nth_prime(unsigned int a, unsigned int d, unsigned int n){
	int i, j, y;
	int x = 0;

	for (i = a; i <= CPP2_PRIME_UPPER_LIMIT; i+=d) {
		y = 0;
		for (j = 1; j <= i; j++) {
			if (i%j == 0)y++;
		}

		if (y == 2)x++;
		if (x == n)break;
	}
	return i;
		}

int main() {

	std::cout << "367, 186, 151=92809 " << nth_prime(367, 186, 151) << std::endl;
	std::cout << "179, 10, 203=6709 " << nth_prime(179, 10, 203) << std::endl;
	std::cout << "271, 37, 39=12037 " << nth_prime(271, 37, 39) << std::endl;
	std::cout << "103, 230, 1=103 " << nth_prime(103, 230, 1) << std::endl;
	std::cout << "27, 104, 185=93523 " << nth_prime(27, 104, 185) << std::endl;
	std::cout << "253, 50, 85=14503 " << nth_prime(253, 50, 85) << std::endl;
	std::cout << "1, 1, 1=2 " << nth_prime(1, 1, 1) << std::endl;
	std::cout << "9075, 337, 210=899429 " << nth_prime(9075, 337, 210) << std::endl;
	std::cout << "307, 24, 79=5107 " << nth_prime(307, 24, 79 ) << std::endl;
	std::cout << "331, 221, 177=412717 " << nth_prime(331, 221, 177) << std::endl;
	std::cout << "259, 170, 40=22699 " << nth_prime(259, 170, 40) << std::endl;
	std::cout << "269, 58, 102=25673 " << nth_prime(269, 58, 102) << std::endl;

    cin.get();
    return 0;
}

