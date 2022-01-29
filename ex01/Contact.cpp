/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:20:03 by ywake             #+#    #+#             */
/*   Updated: 2022/01/30 01:12:34 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Contact.hpp"

void showCell(std::string str)
{
  if (str.length() > 10)
    str = str.substr(0, 9) + ".";
  std::cout << "|" << std::setw(10) << str;
}

void Contact::showRow(void)
{
  showCell(_firstName);
  showCell(_lastName);
  showCell(_nickname);
  std::cout << "|" << std::endl;
}
