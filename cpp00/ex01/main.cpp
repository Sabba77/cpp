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

static const char *fieldName(Contact::Field field)
{
	switch (field)
	{
		case Contact::FIRST_NAME: return "First name";
		case Contact::LAST_NAME: return "Last name";
		case Contact::NICKNAME: return "Nickname";
		case Contact::PHONE_NUMBER: return "Phone number";
		case Contact::DARKEST_SECRET: return "Darkest secret";
		default: return "";
	}
}

static void printRow(int index, const Contact &contact)
{
	std::cout << std::right << std::setw(10) << index << "|";
	std::cout << std::setw(10) << formatField(contact.get(Contact::FIRST_NAME)) << "|";
	std::cout << std::setw(10) << formatField(contact.get(Contact::LAST_NAME)) << "|";
	std::cout << std::setw(10) << formatField(contact.get(Contact::NICKNAME)) << std::endl;
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
	for (int f = 0; f < Contact::FIELD_COUNT; ++f)
	{
		Contact::Field field = static_cast<Contact::Field>(f);
		std::cout << fieldName(field) << ": " << contact.get(field) << std::endl;
	}
}

static bool runAdd(PhoneBook &phoneBook)
{
	Contact contact;
	std::string value;

	for (int f = 0; f < Contact::FIELD_COUNT; ++f)
	{
		Contact::Field field = static_cast<Contact::Field>(f);
		std::string prompt = std::string(fieldName(field)) + ":";
		if (!readNonEmpty(prompt, value))
			return false;
		contact.set(field, value);
	}
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
