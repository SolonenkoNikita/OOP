#include "MakeCharacteristicForGolem/MakeCharacteristicForGolem.h"

#include <fstream>


Characteristics ForGolem::make_characteristics(const std::string& filename)
{
	std::ifstream in(filename);
	std::string key;
	int value;
	Characteristics ch;
	if (in.is_open())
	{
		while (in >> key >> value)
		{
			ch.set_characteristic(GetStringName(key), value);
		}
	}
	in.close();
	return ch;
}