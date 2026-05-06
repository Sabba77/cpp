#include "Contact.hpp"

Contact::Contact() {
}

void Contact::set(const std::string &firstName,
                  const std::string &lastName,
                  const std::string &nickname,
                  const std::string &phoneNumber,
                  const std::string &darkestSecret) {
    m_firstName = firstName;
    m_lastName = lastName;
    m_nickname = nickname;
    m_phoneNumber = phoneNumber;
    m_darkestSecret = darkestSecret;
}

const std::string &Contact::getFirstName() const {
    return m_firstName;
}

const std::string &Contact::getLastName() const {
    return m_lastName;
}

const std::string &Contact::getNickname() const {
    return m_nickname;
}

const std::string &Contact::getPhoneNumber() const {
    return m_phoneNumber;
}

const std::string &Contact::getDarkestSecret() const {
    return m_darkestSecret;
}
