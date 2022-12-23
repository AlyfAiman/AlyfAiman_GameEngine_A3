#include "Guid.h"
#include <iostream>
#include <combaseapi.h>

Guid::Guid(std::array<unsigned char, 16>& bytesIn) : bytes(bytesIn) {};

Guid::Guid(std::array<unsigned char, 16>&& bytesIn) : bytes(bytesIn) {};

Guid Guid::createGUID()
{
	GUID g;
	CoCreateGuid(&g);

	unsigned char one, two, three, four, five, six, seven, eight,
		nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen;

	unsigned data1 = g.Data1;
	unsigned data2 = g.Data2;
	unsigned data3 = g.Data3;

	unsigned data4 = g.Data4[0];
	unsigned data41 = g.Data4[1];
	unsigned data42 = g.Data4[2];
	unsigned data43 = g.Data4[3];
	unsigned data44 = g.Data4[4];
	unsigned data45 = g.Data4[5];
	unsigned data46 = g.Data4[6];
	unsigned data47 = g.Data4[7];


	std::array<unsigned char, 16> bytes =
	{
		one = data1 >> 24 & 0xFF,
		two = data1 >> 16 & 0xFF,
		three = data1 >> 8 & 0xFF,
		four = data1 & 0xFF,

		five = data2 >> 8 & 0xFF,
		six = data2 & 0xFF,

		seven = data3 >> 8 & 0xFF,
		eight = data3 & 0xFF,

		nine = data4 & 0xFF,
		ten = data41 & 0xFF,
		eleven = data42 & 0xFF,
		twelve = data43 & 0xFF,
		thirteen = data44 & 0xFF,
		fourteen = data45 & 0xFF,
		fifteen = data46 & 0xFF,
		sixteen = data47 & 0xFF
	};

	return Guid(std::move(bytes));
}

bool Guid::operator == (const Guid& other) const
{
	return bytes == other.bytes;
}

bool Guid::operator != (const Guid& other) const
{
	return bytes != other.bytes;
}

std::string Guid::getString()const
{
	char str[38];
	sprintf_s(str, "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x"
		, bytes[0], bytes[1], bytes[2], bytes[3],
		bytes[4], bytes[5], bytes[6], bytes[7], bytes[8], bytes[9]
		, bytes[10], bytes[11], bytes[12], bytes[13], bytes[14], bytes[15]);

	return std::string(str);
}

Guid a = Guid::createGUID();
Guid b = Guid::createGUID();
bool equal = a == b;