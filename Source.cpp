#include <iostream>
#include <unordered_set>
#include <iomanip>

int main() {
	double previousRatio = 0.0;
	std::cout << std::fixed << std::setprecision(20) << std::endl; //sets precision of output to 20 decimal points
	std::unordered_set<int> primes; //stores prime numbers 
	for (int i = 1; i < pow(10.0, 100.0); ++i) { // runs from 1-10^100)
		for (int j = 2; j < i; ++j) { //loops through numbers below the current prime to check if the current (i) is prime.
			if (i % j != 0) { //i % j with a return value of zero indicates a possible prime number.
				if (j == (i - 1)) { //checks if loop is at last element in loop. If it is a prime number has been found
					primes.insert(i);
					std::cout << "| We found " << (primes.size() + 1) << " prime numbers. | The most recent being: " << i << ". |" <<
						" The prime to non-prime index ratio is: " << ((primes.size() + 1) / static_cast<double>(i) * 100)
						<< ". | " << "The change in ratios is[percentage point difference]: " 
						<< std::abs(previousRatio - ((primes.size() + 1) / static_cast<double>(i) * 100))  << " |" <<std::endl;
						
					previousRatio = ((primes.size() + 1) / static_cast<double>(i) * 100);

					break;
				}
				else { //continues through numbers below (i) 
					continue;
				}
			}
			else { //breaks if (j) loop is complete without being broken from i.e. no prime found.
				break;
			}
		}
	}
	return 0;
}
