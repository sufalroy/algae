#pragma once

#include <cstdint>
#include <cmath>

namespace algae 
{
	/// <summary>
	/// checks whether an unsigned integer is a prime number.
	/// </summary>
	inline bool isPrime(const uint64_t value) 
	{
		if (value < 2) return false;
		if (value == 2 || value == 3) return true;
		if (value % 2 == 0 || value % 3 == 0) return false;

		uint64_t limit = static_cast<uint64_t>(sqrt(value));

		for (auto i = 5; i < limit; i += 6) {
			if (value % i == 0 || value % (i + 2) == 0) {
				return false;
			}
		}

		return true;
	}
}