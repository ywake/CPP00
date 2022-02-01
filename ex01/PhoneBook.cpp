/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:37:20 by ywake             #+#    #+#             */
/*   Updated: 2022/02/01 17:53:19 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

#include "PhoneBook.hpp"
#include "showTable.hpp"

PhoneBook::PhoneBook() : _index(0), _contacts_num(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::run()
{
  const std::string cmds[] = {"EXIT", "ADD", "SEARCH"};
  void (PhoneBook::*funcs[])(void) = {
    &PhoneBook::_exit, &PhoneBook::_add, &PhoneBook::_search
  };

  while (true) {
    std::string input;

    std::cout << "> ";
    if (!std::getline(std::cin, input)) {
      std::cout << std::endl;
      break;
    }
    for (size_t i = 0; i < 3; i++) {
      if (input == cmds[i]) {
        (this->*funcs[i])();
      }
    }
  }
}

void PhoneBook::_exit(void)
{
  std::exit(0);
}

void PhoneBook::_add(void)
{
  std::string pronpts[] = {"first name", "last name", "nickname",
    "phone number", "darkest secret"};
  std::string inputs[5];
  size_t i = 0;
  while (i < 5)
  {
    std::cout << pronpts[i];
    std::cout << "> ";
    if (!std::getline(std::cin, inputs[i]))
    {
      std::cout << std::endl;
      exit(1);
    } else {
      i++;
    }
  }
  _addContact(Contact(inputs));
}

void PhoneBook::_addContact(Contact contact)
{
  _contacts[_index] = contact;
  _index = (_index + 1) % 8;
  _contacts_num++;
}

void PhoneBook::_search(void)
{
  _showTable();

  int index = -1;
  while (true)
  {
    std::cout << "index> ";
    std::string buf;
    if (!std::getline(std::cin, buf))
    {
      std::cout << std::endl;
      exit(1);
    } else {
      if (buf.length() == 1 && std::isdigit(buf[0])) {
        std::istringstream(buf) >> index;
        if (0 <= index && index < 8)
          break;
      }
    }
  }
  _contacts[index].showInfo();
}

void PhoneBook::_showTable(void)
{
  showHeader();
  for (size_t i = 0; i < 8 && i < _contacts_num; i++)
    _contacts[i].showRow(i);
  showHorizonLine();
}
