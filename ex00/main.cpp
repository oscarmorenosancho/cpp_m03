/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:35:57 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/30 11:17:13 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap* p = new ClapTrap("Omega");
	ClapTrap a("Alpha");
	ClapTrap b( a );
	ClapTrap c("Charly");
	c = *p;
	std::cout << *p;
	std::cout << a;
	std::cout << b;
	delete p;
	std::cout << c;
	a.attack("Alpha");
	c.attack("Alpha");
	c.attack("Charly");
	c.attack("Omega");
	a.beRepaired(800);
	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << "Display list" << std::endl;
	ClapTrap::displayList(std::cout);
	return 0; 
}
