#include <iostream>
#include <MyVector/MyVector.hpp>
#include <vector>

int main()
{
	MyVector<std::string> v = { "a", "b", "c" };
	MyVector<std::string> v1 = { "g", "h", "l" };
	std::cout << v;
	v.insert(2, "asdf");
	std::cout << v;
	//for (int i = 0; i < 5; i++)
	//{
	//	v1.push_back(i);
	//	v.push_back(i);
	//}
	//auto it = v.end();
	////it += 2;
	//v.insert(2, 6);
	//for (size_t i = 0; i < v.size(); i++)
	//{
	//	std::cout << v[i] << " ";
	//}
	//std::cout << '\n';
	//v.pop_back();
	//v.pop_back();
	//for (size_t i = 0; i < v.size(); i++)
	//{
	//	std::cout << v[i] << " ";
	//}
	/*std::cout << v.size();
	std::cout << v1.capacity();*/
	return 0;
};