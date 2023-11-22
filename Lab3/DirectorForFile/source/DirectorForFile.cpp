
#include <DirectorForFile/DirectorForFile.h>

#include <fstream>

Creature DirectorForFile::make(Creator_Creature& cr, const std::string& filename)
{
	std::ifstream in(filename);
	std::string key;
	int value;
	if (in.is_open())
	{
		in >> key;
		cr.set_name(key);
		Characteristics ch;
		in >> key;
		cr.set_fraction(GetFraction(key));
		while (in >> key >> value)
		{
			ch.set_characteristic(GetStringName(key), value);
		}
		cr.make_characteristic(ch);
	}
	in.close();
	return *cr.get_creature();
}