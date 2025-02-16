/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:52:26 by cgaratej          #+#    #+#             */
/*   Updated: 2025/02/16 22:19:18 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <string>

class PhoneBook
{
	private:
		Contact _contacts[8];
		int numContact;
		int indexContact;
	public:
		PhoneBook();
		~PhoneBook();

		void addContact();
		void searchContact();
		void printContact();
};

#endif