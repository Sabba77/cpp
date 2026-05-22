#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
    Contact();

	enum Field {
		FIRST_NAME = 0,
		LAST_NAME,
		NICKNAME,
		PHONE_NUMBER,
		DARKEST_SECRET,
		FIELD_COUNT
	};

	void set(Field field, const std::string &value);
	const std::string &get(Field field) const;

private:
	std::string m_fields[FIELD_COUNT];
};

#endif
