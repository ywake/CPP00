/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:37:20 by ywake             #+#    #+#             */
/*   Updated: 2022/01/29 12:55:53 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
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
  return ;
}

void PhoneBook::_exit(void)
{
  std::exit(0);
}

void PhoneBook::_add(void)
{
  std::cout << "ADD" << std::endl;
}

void PhoneBook::_search(void)
{
  std::cout << "SEARCH" << std::endl;
}
