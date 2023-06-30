/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:35:57 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/30 15:44:18 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

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
	DiamondTrap ace("Ace");
	std::cout << *p;
	delete p;
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
	ace.whoAmI();
	ace.guardGate();
	ace.highFivesGuys();
	ace.attack("Phi");
	ts.attack("Ace");
	ts.attack("Ace_clap_name");

	std::cout << "Extract operations" << std::endl;
	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;
	std::cout << e;
	std::cout << i;
	std::cout << k;
	std::cout << f;
	std::cout << ts;
	std::cout << ace;
	std::cout << "Display list" << std::endl;
	ClapTrap::displayList(std::cout);
	return 0; 
}
