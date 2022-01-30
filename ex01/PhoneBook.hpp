/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:36:52 by ywake             #+#    #+#             */
/*   Updated: 2022/01/30 14:39:39 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
  int _index;
  size_t _contacts_num;
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
