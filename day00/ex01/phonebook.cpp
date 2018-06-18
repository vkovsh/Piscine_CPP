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
#include <cstdlib>

static std::string	read_command(void)
{
	std::string		command;
	std::locale		loc;

	command.erase();
	std::cin >> command;
	for (std::string::size_type i = 0; i < command.length(); i++)
		command[i] = std::toupper(command[i], loc);
	return (command);
}

int					main(void)
{
	std::string	command;

	std::cout << WELCOME_STR << std::endl;
	while (true) {
		std::cout << LOOP_STR << std::endl;
		command = read_command();
		if (command == EXIT_CMD) {
			Contact::Exit();
			break ;
		}
		else if (command == ADD_CMD) {
				Contact *obj = new Contact();
				Contact::Add(obj);
		}
		else if (command == SEARCH_CMD) {
			Contact::ShowContacts();
			int index;
			Contact *contact =  NULL;
			while (contact == NULL) {
				std::cout << "Input index: ";
				std::string buffer;
				std::cin >> buffer;
				index = atoi(buffer.c_str());
				if ((contact = Contact::Search(index)) != NULL) {
					std::cout << "Contact " << index << std::endl;
					contact->PrintContact();
				}
				else {
					std::cout << "Bad input. Try again." << std::endl;
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
