#include "VectorForImages/VectorForImages.h"

#include <fstream>

VectorForImages::VectorForImages(const std::string& filename)
{
	std::ifstream in(filename);
	std::string key;
	if (in.is_open())
	{
		while (in >> key)
		{
			add_string(key);
		}
	}
	in.close();
}

void VectorForImages::add_string(std::string& s)
{
	vector_.emplace_back(std::move(s));
}

std::vector<std::string>& VectorForImages::get_vector()
{
	return vector_;
}

const std::vector<std::string>& VectorForImages::get_vector() const
{
	return vector_;
}