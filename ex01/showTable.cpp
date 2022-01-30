/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showTable.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:56:25 by ywake             #+#    #+#             */
/*   Updated: 2022/01/30 15:59:35 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

void showHorizonLine(void)
{
  for (size_t i = 0; i < 4; i++)
    std::cout << "+----------";
  std::cout << "+" << std::endl;
}

void showCell(std::string str)
{
  if (str.length() > 10)
    str = str.substr(0, 9) + ".";
  std::cout << "|" << std::setw(10) << str;
}

void showHeader(void)
{
  showHorizonLine();
  const std::string headers[] = {
    "index", "first name", "last name", "nickname"};
  for (size_t i = 0; i < 4; i++)
    showCell(headers[i]);
  std::cout << "|" << std::endl;
  showHorizonLine();
}
