#include <algae.hpp>
#include <iostream>
#include <iomanip>

#define LOG(x) std::cout << x << std::endl;

int main(int argc, char** argv)  
{
	PROFILE_FUNCTION();
	
	for (auto i = 0; i < 100; i++) 
	{
		if (algae::isPrime(i)) {
			LOG(i);
		}
	}

	std::cin.get();
}