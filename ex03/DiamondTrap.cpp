/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:11:52 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/30 13:09:40 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string n) : ScavTrap(n + "_clap_name"), 
											FragTrap(n + "_clap_name"),
												name(n)
{
	robotType = "DiamondTrap";
	FragTrap::hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "DiamondTrap constructor called for ";
	std::cout << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& b) : ScavTrap(b.name), FragTrap(b.name)
{
	robotType = "DiamondTrap";
	hitPoints = b.hitPoints;
	energyPoints = b.energyPoints;
	attackDamage = b.attackDamage;
	std::cout << "DiamondTrap copy constructor called for ";
	std::cout << name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& b)
{
	std::cout << "DiamondTrap copy assignment operator called for ";
	std::cout << name << " to become " << b.name << std::endl;
	name = b.name;
	// hitPoints = b.hitPoints;
	// energyPoints = b.energyPoints;
	// attackDamage = b.attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for ";
	std::cout << name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	std::cout << "DiamondTrap delegates attack to ClapTrap;\n\t";
	ClapTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	std::cout << "DiamondTrap delegates takeDamage to ClapTrap;\n\t";
	ClapTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	std::cout << "DiamondTrap delegates beRepaired to ClapTrap;\n\t";
	ClapTrap::beRepaired(amount);
}

std::ostream& DiamondTrap::displayStatus(std::ostream& os) const
{
	ClapTrap::displayStatus(os);
	return (os);
}

std::ostream& operator<<(std::ostream& os, const DiamondTrap& st)
{
	return (st.displayStatus(os));
}

void DiamondTrap::highFivesGuys()
{
	std::cout << robotType << " ";
	FragTrap::highFivesGuys();
}
void DiamondTrap::guardGate()
{
	std::cout << robotType << " ";
	ScavTrap::guardGate();
}
void DiamondTrap::whoAmI()
{
	std::cout << "I am " << robotType << " ";
	std::cout << name << " and ";
	std::cout << ClapTrap::name << "as ClapTrap." << std::endl;
}

