#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
    Contact();

    void set(const std::string &firstName,
             const std::string &lastName,
             const std::string &nickname,
             const std::string &phoneNumber,
             const std::string &darkestSecret);

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getNickname() const;
    const std::string &getPhoneNumber() const;
    const std::string &getDarkestSecret() const;

private:
    std::string m_firstName;
    std::string m_lastName;
    std::string m_nickname;
    std::string m_phoneNumber;
    std::string m_darkestSecret;
};

#endif
