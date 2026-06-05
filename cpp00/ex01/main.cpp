#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

static const char *const g_fieldNames[Contact::FIELD_COUNT] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};

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
	return (value.length() > 10) ? (value.substr(0, 9) + ".") : value;
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
	{
		const Contact &c = phoneBook.getContact(i);
		std::cout << std::right << std::setw(10) << (i + 1) << "|"
				  << std::setw(10) << formatField(c.get(Contact::FIRST_NAME)) << "|"
				  << std::setw(10) << formatField(c.get(Contact::LAST_NAME)) << "|"
				  << std::setw(10) << formatField(c.get(Contact::NICKNAME)) << std::endl;
	}

	std::cout << "Enter index to display:" << std::endl;
	std::string line;
	if (!std::getline(std::cin, line))
		return;
	std::istringstream iss(line);
	int index = 0;
	if (!(iss >> index) || (iss >> std::ws, !iss.eof()) || !phoneBook.isValidIndex(index - 1))
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}

	const Contact &contact = phoneBook.getContact(index - 1);
	for (int f = 0; f < Contact::FIELD_COUNT; ++f)
		std::cout << g_fieldNames[f] << ": " << contact.get(static_cast<Contact::Field>(f)) << std::endl;
}

static bool runAdd(PhoneBook &phoneBook)
{
	Contact contact;
	std::string value;

	for (int f = 0; f < Contact::FIELD_COUNT; ++f)
	{
		std::string prompt = std::string(g_fieldNames[f]) + ":";
		if (!readNonEmpty(prompt, value))
			return false;
		contact.set(static_cast<Contact::Field>(f), value);
	}
	phoneBook.addContact(contact);
	return true;
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	for (;;)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT):" << std::endl;
		if (!std::getline(std::cin, command))
			break;
		if ((command == "ADD" || command == "add") && !runAdd(phoneBook))
			break;
		else if (command == "SEARCH" || command == "search")
			runSearch(phoneBook);
		else if (command == "EXIT" || command == "exit")
			break;
	}
	return 0;
}
