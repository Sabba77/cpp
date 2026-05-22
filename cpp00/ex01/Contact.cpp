#include "Contact.hpp"

Contact::Contact()
{}

void Contact::set(Field field, const std::string &value)
{
	if (field < 0 || field >= FIELD_COUNT)
		return;
	m_fields[field] = value;
}

const std::string &Contact::get(Field field) const
{
	static const std::string empty;
	if (field < 0 || field >= FIELD_COUNT)
		return empty;
	return m_fields[field];
}
