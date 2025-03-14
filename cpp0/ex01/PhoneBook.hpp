/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:52:26 by cgaratej          #+#    #+#             */
/*   Updated: 2025/03/08 11:00:08 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>

#define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact _contacts[8];
		int numContact;
		int indexContact;
	public:
		PhoneBook();
		~PhoneBook();

		void AddContact();
		void SearchContact() const;
		void PrintContact(int index) const;
};

#endif