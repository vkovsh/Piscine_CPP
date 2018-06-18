/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:57:40 by vkovsh            #+#    #+#             */
/*   Updated: 2018/06/18 11:57:41 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ContactClass.hpp"
#include "phonebook.h"
#include <iostream>

static std::string	read_command(void)
{
	std::string		command;
	std::locale		loc;

	command.erase();
	std::getline(std::cin, command);
	for (std::string::size_type i = 0; i < command.length(); i++)
		command[i] = std::toupper(command[i], loc);
	return (command);
}

int					main(void)
{
	std::string		command;
	Contact			Contacts[Contact::GetMaxContactNumber()];	

	std::cout << WELCOME_STR << std::endl;
	while (true) {
		std::cout << LOOP_STR << std::endl;
		command = read_command();
		if (command == EXIT_CMD) {
			break ;
		}
		else if (command == ADD_CMD) {
			if (Contact::GetCounter() < Contact::GetMaxContactNumber() - 1) {
				Contact::Add();
				Contacts[Contact::GetCounter()].FillContact();
			}
			else {
				std::cout << "Phonebook is full!" << std::endl;
			}
		}
		else if (command == SEARCH_CMD) {
			Contact::ShowContacts(Contacts);
			if (Contact::GetCounter() < 0) {
				std::cout << "Phonebook is empty!" << std::endl;
			}
			else {
				bool success = false;
				while (!success) {
					int index;
					std::cout << "Input index: ";
					std::string buffer;
					std::getline(std::cin, buffer);
					if (buffer.size() == 1 && buffer[0] >= '0' && buffer[0] <= '8') {
						index = buffer[0] - '0';
						if (index <= Contact::GetCounter()) {
							std::cout << "Contact " << index << std::endl;
							(Contact::Search(index, Contacts)).PrintContact();
							success = true;
						}
						else {
							std::cout << "No contact with such name!" << std::endl;
						}
					}
					else {
						std::cout << "Bad input!" << std::endl;
					}
				}
			}
		}
		else {
			std::cout << "'" <<command << "' ";
			std::cout << "undefined" << std::endl;
			std::cout << USAGE_STR << std::endl;
		}
	}
	return (0);
}
