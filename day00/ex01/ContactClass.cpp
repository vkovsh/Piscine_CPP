/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:57:04 by vkovsh            #+#    #+#             */
/*   Updated: 2018/06/18 11:57:06 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ContactClass.hpp"
#include <iostream>
#include <string>

int			Contact::Counter = -1;

Contact::Contact(void) {

}

Contact::~Contact(void) {

}

void	Contact::FillContact(void) {
	std::cout << "Type firstname" << std::endl;
	std::getline(std::cin, this->first_name);
	std::cout << "Type lastname" << std::endl;
	std::getline(std::cin, this->last_name);
	std::cout << "Type nickname" << std::endl;
	std::getline(std::cin, this->nickname);
	std::cout << "Type login" << std::endl;
	std::getline(std::cin, this->login);
	std::cout << "Type postal adress" << std::endl;
	std::getline(std::cin, this->postal_adress);
	std::cout << "Type email adress" << std::endl;
	std::getline(std::cin, this->email_adress);
	std::cout << "Type phone number" << std::endl;
	std::getline(std::cin, this->phone_number);
	std::cout << "Type birthday date" << std::endl;
	std::getline(std::cin, this->birthday_date);
	std::cout << "Type favorite meal" << std::endl;
	std::getline(std::cin, this->favorite_meal);
	std::cout << "Type underwear color" << std::endl;
	std::getline(std::cin, this->underwear_color);
	std::cout << "Type darkest secret" << std::endl;
	std::getline(std::cin, this->darkest_secret);
	std::cout << "Contact filled" << std::endl;
}

void	Contact::Add(void) {
	if (Contact::Counter < Contact::MaxContactsNumber - 1) {
		(Contact::Counter)++;
	}
}

void	Contact::ShowContacts(Contact Contacts[]) {
	for (int i = 0; i < 45; i++) {
		std::cout << '-';
	}
	std::cout << std::endl;
	std::cout << "|" << Contact::FormatString("INDEX");
	std::cout << "|" << Contact::FormatString("FIRSTNAME");
	std::cout << "|" << Contact::FormatString("LASTNAME");
	std::cout << "|" << Contact::FormatString("NICKNAME") << "|" << std::endl;
	for (int i = 0; i < 45; i++) {
		std::cout << '-';
	}
	std::cout << std::endl;
	for (int i = 0; i <= Contact::Counter; i++) {
		std::string a;
		a.push_back(i + 48);
		std::cout << "|" << Contact::FormatString(a) << "|";
		std::cout << Contact::FormatString((Contacts[i]).first_name) << "|";
		std::cout << Contact::FormatString((Contacts[i]).last_name) << "|";
		std::cout << Contact::FormatString((Contacts[i]).nickname) << "|" << std::endl;
		for (int j = 0; j < 45; j++) {
			std::cout << '-';
		}
		std::cout << std::endl;
	}
}

int		Contact::GetMaxContactNumber(void) {
	return (Contact::MaxContactsNumber);
}

int		Contact::GetCounter(void) {
	return (Contact::Counter);
}

std::string	Contact::FormatString(std::string str) {
	if (str.size() <= 10) {
		while (str.size() < 10) {
			str = " " + str;
		}
	}
	else {
		str = str.substr(0, 9);
		str.push_back('.');
	}
	return (str);
}

Contact		Contact::Search(int index, Contact Contacts[]) {
	return (Contacts[index]);
}

void		Contact::PrintContact(void) {
	std::cout << "Firstname: "<< this->first_name << std::endl;
	std::cout << "Lastname: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Login: " << this->login << std::endl;
	std::cout << "Postal adress: " << this->postal_adress << std::endl;
	std::cout << "Email adress: " << this->email_adress << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Birthday date: " << this->birthday_date << std::endl;
	std::cout << "Favorite meal: " << this->favorite_meal << std::endl;
	std::cout << "Underwear color: " << this->underwear_color << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}
