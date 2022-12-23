#pragma once
#include <array>
#include <string>
class Guid
{
public:
	Guid(std::array<unsigned char, 16>& bytesIn);
	Guid(std::array<unsigned char, 16>&& bytesIn);

	static Guid createGUID();

	bool operator == (const Guid& other) const;
	bool operator != (const Guid& other) const;

	std::string getString()const;

private:

	std::array<unsigned char, 16> bytes;
};