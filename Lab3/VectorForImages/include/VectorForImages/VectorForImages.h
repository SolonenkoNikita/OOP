#ifndef _VectorForImages_H_
#define _VectorForImages_H_

#include <iostream>
#include <vector>

class VectorForImages
{
private:
	std::vector<std::string> vector_;
public:

	VectorForImages(const std::string& filename);

	VectorForImages(VectorForImages&&) = default;

	VectorForImages(const VectorForImages&) = default;

	void add_string(std::string& s);

	std::vector<std::string>& get_vector();

	const std::vector<std::string>& get_vector() const;

	~VectorForImages() = default;
};

#endif