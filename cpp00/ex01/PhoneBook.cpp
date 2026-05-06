#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : m_nextIndex(0), m_count(0) {
}

void PhoneBook::addContact(const Contact &contact) {
    m_contacts[m_nextIndex] = contact;
    m_nextIndex = (m_nextIndex + 1) % 8;
    if (m_count < 8) {
        m_count += 1;
    }
}

int PhoneBook::getCount() const {
    return m_count;
}

const Contact &PhoneBook::getContact(int index) const {
    return m_contacts[index];
}

bool PhoneBook::isValidIndex(int index) const {
    return index >= 0 && index < m_count;
}
