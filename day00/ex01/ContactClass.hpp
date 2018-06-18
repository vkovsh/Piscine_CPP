/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:57:21 by vkovsh            #+#    #+#             */
/*   Updated: 2018/06/18 11:57:24 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
# include <string>

class					Contact {

private: 
	//methods
	static std::string	FormatString(std::string str);

	//static size of contact book
	static const int	MaxContactsNumber = 8;

	/*
	// counter on array
	// -1 on initialize(empty), 7 - max value
	*/
	static int			Counter;

	//fields
	std::string			first_name;
	std::string			last_name;
	std::string			nickname;
	std::string			login;
	std::string			postal_adress;
	std::string			email_adress;
	std::string			phone_number;
	std::string 		birthday_date;
	std::string			favorite_meal;
	std::string			underwear_color;
	std::string			darkest_secret;

public:
	//methods
	std::string			ToString(void);
	void				PrintContact(void);
	void				FillContact(void);
	
	//static getters
	static int			GetMaxContactNumber(void);
	static int			GetCounter(void);

	//getters
	std::string			GetFirstName(void);
	std::string			GetLastName(void);
	std::string			GetNickname(void);
	std::string			GetLogin(void);
	std::string			GetPostalAdress(void);
	std::string			GetEmailAdress(void);
	std::string			GetPhoneNumber(void);
	std::string			GetBirthdayDate(void);
	std::string			GetFavoriteMeal(void);
	std::string			GetUnderwearColor(void);
	std::string			GetDarkestSecret(void);

	//static methods
	static void			ShowContacts(Contact Contacts[]);			
	static Contact		Search(int index, Contact Contacts[]);
	static void			Add(void);

	Contact(void);
	~Contact(void);
};

#endif
