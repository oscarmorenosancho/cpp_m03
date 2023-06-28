/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:20:25 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/28 17:27:58 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string n) : name(n)
{
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& b) : name(b.name)
{
	hitPoints = b.hitPoints;
	energyPoints = b.energyPoints;
	attackDamage = b.attackDamage;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& b)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	name = b.name;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target;
		std::cout << ", causing " << attackDamage << " points of damage!" << std::endl;
		if (energyPoints > 0)
			std::cout << energyPoints << "Energy points left!" << std::endl;
		else
			std::cout << "No energy points left!" << std::endl;
		//Target.TakeDamage(attackDamage);
	}
	else
	{
		std::cout << "ClapTrap " << name << " can't attack " << target;
		std::cout << ", because don't have enough Energy ot Hit Points!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	if (hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " got " << amount << "damage points.";
		std::cout << hitPoints << " hit points left!" << std::endl;

	}
	else
	{
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " got " << amount << "damage points.";
		std::cout << "No hit points left!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0)
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " is repaired";
		std::cout << ", increasing " << amount << " hit points!" << std::endl;
		if (energyPoints > 0)
			std::cout << energyPoints << "Energy points left!" << std::endl;
		else
			std::cout << "No energy points left!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << name << " can't be repaired" << std::endl;
	}
}
std::ostream& ClapTrap::displayStatus(std::ostream& os) const
{
	os << "ClapTrap " << name << " status: ( ";
	os << "Energy Points = " << energyPoints;
	os << ", Hit Points = " << hitPoints << " )" << std::endl;
	return (os);
}

std::ostream& operator<<(std::ostream& os, const ClapTrap& ct)
{
	return (ct.displayStatus(os));
}
