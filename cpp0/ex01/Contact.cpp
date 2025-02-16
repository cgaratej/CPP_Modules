/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:52:39 by cgaratej          #+#    #+#             */
/*   Updated: 2025/02/16 22:12:13 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFristName(std::string &fristName){
	this->_firstName = fristName;
}

void Contact::setLastName (std::string &lastName){
	this->_lastName = lastName;
}

void Contact::setNickName(std::string &nickName){
	this->_nickName = nickName;
}

void Contact::setPhoneNumber(std::string &phoneNumber){
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string &darkestSecret){
	this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const {
    return this->_firstName;
}

std::string Contact::getLastName() const {
    return this->_lastName;
}

std::string Contact::getNickname() const {
    return this->_nickName;
}

std::string Contact::getPhoneNumber() const {
    return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return this->_darkestSecret;
}
