/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:55:20 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/29 12:22:29 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string n) : ClapTrap(n)
{
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	next = list;
	list = this;
	std::cout << "ScavTrap constructor called for ";
	std::cout << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& b) : ClapTrap(b.name)
{
	hitPoints = b.hitPoints;
	energyPoints = b.energyPoints;
	attackDamage = b.attackDamage;
	next = list;
	list = this;
	std::cout << "ScavTrap copy constructor called for ";
	std::cout << name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& b)
{
	std::cout << "ScavTrap copy assignment operator called for ";
	std::cout << name << " to become " << b.name << std::endl;
	name = b.name;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for ";
	std::cout << name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	ClapTrap::attack(target);
}

void ScavTrap::takeDamage(unsigned int amount)
{
	ClapTrap::takeDamage(amount);
}

void ScavTrap::beRepaired(unsigned int amount)
{
	ClapTrap::beRepaired(amount);
}
std::ostream& ScavTrap::displayStatus(std::ostream& os) const
{
	os << "ClapTrap " << name << " status: ( ";
	os << "Energy Points = " << energyPoints;
	os << ", Hit Points = " << hitPoints << " )" << std::endl;
	return (os);
}

void	ScavTrap::displayList(std::ostream& os)
{
	ClapTrap::displayList(os);
}

std::ostream& operator<<(std::ostream& os, const ScavTrap& st)
{
	return (st.displayStatus(os));
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " guard Gate";
}
