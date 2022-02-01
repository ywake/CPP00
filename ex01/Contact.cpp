/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:20:03 by ywake             #+#    #+#             */
/*   Updated: 2022/02/01 17:55:30 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

#include "Contact.hpp"
#include "showTable.hpp"

Contact::Contact() :
  _firstName(),
  _lastName(),
  _nickname(),
  _phoneNumber(),
  _darkestSecret() { };

Contact::Contact(std::string strs[5]) :
  _firstName(strs[0]),
  _lastName(strs[1]),
  _nickname(strs[2]),
  _phoneNumber(strs[3]),
  _darkestSecret(strs[4]) { };

Contact::~Contact() { };

void Contact::showRow(size_t index)
{
  std::cout << "|" << std::setw(10) << index;
  showCell(_firstName);
  showCell(_lastName);
  showCell(_nickname);
  std::cout << "|" << std::endl;
}

void Contact::showInfo(void)
{
  std::cout << std::setw(14) << "first name";
  std::cout << ": " << _firstName << std::endl;
  std::cout << std::setw(14) << "last name";
  std::cout << ": " << _lastName << std::endl;
  std::cout << std::setw(14) << "nickname";
  std::cout << ": " << _nickname << std::endl;
  std::cout << std::setw(14) << "phone number";
  std::cout << ": " << _phoneNumber << std::endl;
  std::cout << std::setw(14) << "darkest secret";
  std::cout << ": " << _darkestSecret << std::endl;
}
