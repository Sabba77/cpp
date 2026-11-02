#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer&)
{
}

Serializer& Serializer::operator=(const Serializer&)
{
	return *this;
}

Serializer::~Serializer()
{
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	std::cout << GREEN << "data " << ptr << " serialized." << RESET << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	std::cout << RED << "uintptr_t " << raw << " deserialized." << RESET << std::endl;
	return (reinterpret_cast<Data*>(raw));
}