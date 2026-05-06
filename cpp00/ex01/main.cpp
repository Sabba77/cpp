#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

static bool readNonEmpty(const std::string &label, std::string &out)
{
    while (true)
	{
        std::cout << label << std::endl;
        if (!std::getline(std::cin, out))
            return false;
        if (out.find_first_not_of(" \t\r\n") != std::string::npos)
            return true;
    }
}

static std::string formatField(const std::string &value)
{
    if (value.length() > 10) {
        return value.substr(0, 9) + ".";
    }
    return value;
}

static void printRow(int index, const Contact &contact)
{
    std::cout << std::right << std::setw(10) << index << "|";
    std::cout << std::setw(10) << formatField(contact.getFirstName()) << "|";
    std::cout << std::setw(10) << formatField(contact.getLastName()) << "|";
    std::cout << std::setw(10) << formatField(contact.getNickname()) << std::endl;
}

static void runSearch(const PhoneBook &phoneBook)
{
    int count = phoneBook.getCount();
    if (count == 0)
        return;

    std::cout << std::right
              << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < count; ++i)
        printRow(i + 1, phoneBook.getContact(i));

    std::cout << "Enter index to display:" << std::endl;
    std::string line;
    if (!std::getline(std::cin, line))
        return;
    std::istringstream iss(line);
    int index = 0;
    if (!(iss >> index) || (iss >> std::ws, !iss.eof())
        || !phoneBook.isValidIndex(index - 1))
	{
        std::cout << "Invalid index." << std::endl;
        return;
    }

    const Contact &contact = phoneBook.getContact(index - 1);
    std::cout << "First name: " << contact.getFirstName() << std::endl;
    std::cout << "Last name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

static bool runAdd(PhoneBook &phoneBook)
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    if (!readNonEmpty("First name:", firstName))
        return false;
    if (!readNonEmpty("Last name:", lastName))
        return false;
    if (!readNonEmpty("Nickname:", nickname))
        return false;
    if (!readNonEmpty("Phone number:", phoneNumber))
        return false;
    if (!readNonEmpty("Darkest secret:", darkestSecret))
        return false;

    Contact contact;
    contact.set(firstName, lastName, nickname, phoneNumber, darkestSecret);
    phoneBook.addContact(contact);
    return true;
}

int main()
{
    PhoneBook	phoneBook;
    std::string	command;

    while (true)
	{
        std::cout << "Enter command (ADD, SEARCH, EXIT):" << std::endl;
        if (!std::getline(std::cin, command))
        	break;

        if (command == "ADD")
		{
            if (!runAdd(phoneBook))
                break;
		}
		else if (command == "SEARCH")
            runSearch(phoneBook);
		else if (command == "EXIT")
            break;
    }
    return 0;
}
