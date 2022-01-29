/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:36:52 by ywake             #+#    #+#             */
/*   Updated: 2022/01/29 19:15:47 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
  int _index;
  Contact _contacts[8];
  void _exit(void);
  void _add(void);
  void _addContact(Contact contact);
  void _search(void);
  void _showTable(void);

public:
	PhoneBook();
	~PhoneBook();
	void run();
};

#endif
