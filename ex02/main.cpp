/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:35:57 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/30 12:05:56 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
	ClapTrap* p = new ClapTrap("Omega");
	ClapTrap a("Alpha");
	ClapTrap b( a );
	ClapTrap c("Charly");
	ScavTrap d("Delta");
	c = *p;
	ScavTrap e("Epsilon");
	ScavTrap i(e);
	e = d;
	FragTrap k("Phi");
	FragTrap f(k);
	FragTrap ts("Tsi");
	k = ts;
	std::cout << *p;
	delete p;
	std::cout << a;
	std::cout << b;
	std::cout << c;
	a.attack("Alpha");
	c.attack("Alpha");
	c.attack("Charly");
	c.attack("Omega");
	d.attack("Alpha");
	a.beRepaired(800);
	a.attack("Delta");
	d.guardGate();
	ts.highFivesGuys();
	k.highFivesGuys();
	k.attack("Phi");
	ts.attack("Phi");
	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << "Display list" << std::endl;
	ClapTrap::displayList(std::cout);
	// ClapTrap::displayList(std::cout);
	return 0; 
}
