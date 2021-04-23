#include <algae.hpp>
#include <iostream>
#include <iomanip>
#include <vector>
#include <array>

#define LOG(x) std::cout << x << std::endl

struct vector3
{
	float x = 0.0f, y = 0.0f, z = 0.0f;

	vector3() {}
	vector3(float scalar) 
		: x(scalar), y(scalar), z(scalar) {}	
	vector3(float x, float y, float z)
		: x(x), y(y), z(z) {}
	vector3(const vector3& other)
		: x(other.x), y(other.y), z(other.z) 
	{
	
	}
	vector3(vector3&& other) noexcept
		: x(other.x), y(other.y), z(other.z)
	{
	
	}
	~vector3()
	{
	}

	vector3& operator =(const vector3& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	vector3& operator =(vector3&& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;


	}
};

int main(int argc, char** argv)  
{
	PROFILE_FUNCTION();
	

	algae::static_array<int, 5> array;

	std::memset(array.data(), 0, array.size() * sizeof(int));

	array[0] = 1;
	array[2] = 3;
	array[3] = 4;

	LOG("Static Array Demo");
	for (auto& it = array.begin(); it != array.end(); it++)
		LOG(*it);

	LOG("--------------------------");

	algae::dynamic_array<vector3> vector;

	vector.emplace_back(0.2);
	vector.emplace_back(0.0, 1.0, 0.0);
	vector.pop_back();
	vector.emplace_back(1.3, 1.3, 1.3);
	vector.emplace_back(2.4, 4.2, 5.6);
	vector.emplace_back(1.2);

	LOG("Dynamic Array Demo");
	for (auto& vec : vector)
		std::cout << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]" << std::endl;

	std::cin.get();
}