/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:52:31 by cgaratej          #+#    #+#             */
/*   Updated: 2025/03/08 11:06:00 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : numContact(0), indexContact(0) {}

PhoneBook::~PhoneBook() {}

bool IsAlpha(std::string str)
{
	for (int i = 0; str.length() < i; i++)
		if (!std::isalpha(str[i]))
			return false;
	return true;
}

bool IsDigit(std::string str)
{
	for (int i = 0; str.length() < i; i++)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

void IsVaidInput(const std::string &message, std::string &input, bool isAlpha, bool isNull)
{
	while (true)
	{
		std::cout << message;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "EOF detectcet. Finish Program" << std::endl;
			exit(0);
		}
		if (input.empty())
		{
			std::cout << "Empty Input" << std::endl;
			continue;
		}
		if (!isNull)
		{
			if ((isAlpha && !IsAlpha(input)) || (!isAlpha && !IsDigit(input)))
			{
				std::cerr << "Error: Invalid " << (isAlpha ? "letters" : "digits") << " input.\n";
				continue;
			}
		}
		break;
	}
}

void PhoneBook::AddContact()
{
	Contact newContact;
	std::string input;

	IsVaidInput("Entre Frist Name: ", input, true, false);
	newContact.setFristName(input);
	IsVaidInput("Entre Last Name: ", input, true, false);
	newContact.setLastName(input);
	IsVaidInput("Entre NickName: ", input, true, true);
	newContact.setNickName(input);
	IsVaidInput("Entre Phone Numer: ", input, false, false);
	newContact.setPhoneNumber(input);
	IsVaidInput("Enter darkest secret: ", input, false, true);
    newContact.setDarkestSecret(input);

	if (numContact < MAX_CONTACTS)
        _contacts[numContact++] = newContact;
    else
    {
        _contacts[indexContact] = newContact;
        indexContact = (indexContact + 1) % MAX_CONTACTS;
    }
    std::cout << "Contact added successfully." << std::endl;
}

void PhoneBook::PrintContact(int index) const
{
	std::cout << "Frist Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone Numbre: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

void printColumn(const std::string &str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << str;
}

int stringToInt(const std::string &str)
{
    std::istringstream iss(str);
    int num;
    iss >> num;
    return num;
}

void PhoneBook::SearchContact() const
{
	if (numContact == 0){
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
	for (int i = 0; i < numContact; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		printColumn(_contacts[i].getFirstName());
		std::cout << "|";
		printColumn(_contacts[i].getLastName());
		std::cout << "|";
		printColumn(_contacts[i].getNickname());
		std::cout << std::endl;
	}

	std::string index;
    while (42)
    {
        IsVaidInput("Enter index of the contact you want to display: ", index, true, false);
        std::ostringstream oss;
        oss << (numContact);
        if (index.length() == 1 && index[0] >= '1' && index[0] <= oss.str()[0])
            break;
		std::cout << "Invalid index. Please enter a number between 1 and " << numContact << "." << std::endl;
    }
    std::istringstream iss(index);
    PrintContact(stringToInt(index) - 1);
}