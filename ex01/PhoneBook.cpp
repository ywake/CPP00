/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:37:20 by ywake             #+#    #+#             */
/*   Updated: 2022/01/29 19:23:35 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0), _contacts()
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
    std::getline(std::cin, input);
    if (std::cin.fail()) {
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
    getline(std::cin, inputs[i]);
    i++;
  }
  _addContact(Contact(inputs));
}

void PhoneBook::_addContact(Contact contact)
{
  _contacts[_index] = contact;
  _index = (_index + 1) % 8;
}

void showHorizonLine()
{
  for (size_t i = 0; i < 4; i++)
    std::cout << "+----------";
  std::cout << "+" << std::endl;
}

void showHeader()
{
  showHorizonLine();
  const std::string headers[] = {
    "index", "first name", "last name", "nickname"};
  for (size_t i = 0; i < 4; i++)
    std::cout << "|" << std::setw(10) << headers[i];
  std::cout << "|" << std::endl;
  showHorizonLine();
}

void PhoneBook::_showTable(void)
{
  showHeader();
  for (size_t i = 0; i < 8; i++)
  {
    std::cout << "|" << std::setw(10) << i;
    _contacts[i].showRow();
  }
  showHorizonLine();
}

void PhoneBook::_search(void)
{
  _showTable();
}
