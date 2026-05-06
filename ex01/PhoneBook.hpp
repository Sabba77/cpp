#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook();

    void addContact(const Contact &contact);
    int getCount() const;
    const Contact &getContact(int index) const;
    bool isValidIndex(int index) const;

private:
    Contact m_contacts[8];
    int m_nextIndex;
    int m_count;
};

#endif
