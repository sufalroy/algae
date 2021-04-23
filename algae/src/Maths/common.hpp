#pragma once

#include <cstdint>
#include <cmath>

namespace algae 
{
	/// <summary>
	/// checks whether an unsigned integer is a prime number.
	/// </summary>
	constexpr inline bool is_prime(const long value) 
	{
		if (value < 2) return false;
		if (value == 2 || value == 3) return true;
		if (value % 2 == 0 || value % 3 == 0) return false;

		long limit = static_cast<long>(sqrt(value));

		for (auto i = 5; i < limit; i += 6) {
			if (value % i == 0 || value % (i + 2) == 0) {
				return false;
			}
		}

		return true;
	}

	/// <summary>
	/// computes the Greatest Common Divisor (GCD) of two numbers.
	/// </summary>
	constexpr inline long gcd(const long a, const long b)
	{
		return b == 0 ? (a < 0 ? -a : a) : gcd(b, a % b);
	}

	/// <summary>
	/// computes the Least Common Multiple (LCM) of two numbers.
	/// </summary>
	constexpr inline long lcm(const long a, const long b)
	{
		long lcm = (a / gcd(a, b)) * b;
		return lcm > 0 ? lcm : -lcm;
	}
}