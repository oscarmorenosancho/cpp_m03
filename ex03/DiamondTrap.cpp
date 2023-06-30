/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:11:52 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/30 15:47:18 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string n) :
									ClapTrap (n + "_clap_name"),
										name(n)
{
	robotType = "DiamondTrap";
	FragTrap::hitPoints = 100;
	ScavTrap::energyPoints = 100;
	FragTrap::attackDamage = 30;
	std::cout << "DiamondTrap constructor called for ";
	std::cout << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& b) :
									ClapTrap(b.ClapTrap::name),
										name(b.ClapTrap::name)
{
	robotType = "DiamondTrap";
	FragTrap::hitPoints = b.hitPoints;
	ScavTrap::energyPoints = b.energyPoints;
	FragTrap::attackDamage = b.attackDamage;
	std::cout << "DiamondTrap copy constructor called for ";
	std::cout << name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& b)
{
	std::cout << "DiamondTrap copy assignment operator called for ";
	std::cout << name << " to become " << b.name << std::endl;
	name = b.name;
	FragTrap::hitPoints = b.hitPoints;
	ScavTrap::energyPoints = b.energyPoints;
	FragTrap::attackDamage = b.attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for ";
	std::cout << name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const DiamondTrap& st)
{
	return (st.displayStatus(os));
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am ";
	std::cout << name << " as " << robotType << " and ";
	std::cout << ClapTrap::name << " as ClapTrap." << std::endl;
}

