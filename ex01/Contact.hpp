/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:19:59 by ywake             #+#    #+#             */
/*   Updated: 2022/01/29 19:17:13 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
  std::string _firstName;
  std::string _lastName;
  std::string _nickname;
  std::string _phoneNumber;
  std::string _darkestSecret;

public:
  Contact() :
    _firstName(),
    _lastName(),
    _nickname(),
    _phoneNumber(),
    _darkestSecret() {};
  Contact(std::string strs[5]) :
    _firstName(strs[0]),
    _lastName(strs[1]),
    _nickname(strs[2]),
    _phoneNumber(strs[3]),
    _darkestSecret(strs[4]) {};
  ~Contact() {};
  void showRow(void);
};

#endif
