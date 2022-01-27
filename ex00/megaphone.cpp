/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:37:00 by ywake             #+#    #+#             */
/*   Updated: 2022/01/27 12:37:01 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  } else {
    for (size_t i = 1; i < (size_t)argc; i++) {
      std::string str = "";
      for (size_t j = 0; argv[i][j]; j++) {
        str += std::toupper(argv[i][j]);
      }
      std::cout << str;
    }
		std::cout << std::endl;
  }
}
