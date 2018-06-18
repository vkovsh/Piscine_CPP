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
	static const int	MaxContactsNumber = 9;

	//static array with contacts
	static Contact		*Contacts[Contact::MaxContactsNumber];

	/*
	// counter on array
	// -1 on initialize(empty), 8 - max value
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
	static void			Exit(void);
	static void			ShowContacts(void);			
	static Contact		*Search(int index);
	static void			Add(Contact *new_contact);

	//constructors
	Contact(std::string first_name,
			std::string last_name,
			std::string nickname,
			std::string login,
			std::string postal_adress,
			std::string email_adress,
			std::string phone_number,
			std::string birthday_date,
			std::string favorite_meal,
			std::string underwear_color,
			std::string darkest_secret);

	Contact(void);

	//destructor
	~Contact(void);

};

#endif
