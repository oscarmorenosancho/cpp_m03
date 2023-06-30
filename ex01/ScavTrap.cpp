/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:55:20 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/30 11:23:41 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string n) : ClapTrap(n)
{
	robotType = "ScavTrap";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor called for ";
	std::cout << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& b) : ClapTrap(b.name)
{
	robotType = "ScavTrap";
	hitPoints = b.hitPoints;
	energyPoints = b.energyPoints;
	attackDamage = b.attackDamage;
	std::cout << "ScavTrap copy constructor called for ";
	std::cout << name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& b)
{
	std::cout << "ScavTrap copy assignment operator called for ";
	std::cout << name << " to become " << b.name << std::endl;
	name = b.name;
	hitPoints = b.hitPoints;
	energyPoints = b.energyPoints;
	attackDamage = b.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for ";
	std::cout << name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap delegates attack to ClapTrap;\n\t";
	ClapTrap::attack(target);
}

void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap delegates takeDamage to ClapTrap;\n\t";
	ClapTrap::takeDamage(amount);
}

void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap delegates beRepaired to ClapTrap;\n\t";
	ClapTrap::beRepaired(amount);
}

std::ostream& ScavTrap::displayStatus(std::ostream& os) const
{
	ClapTrap::displayStatus(os);
	return (os);
}

std::ostream& operator<<(std::ostream& os, const ScavTrap& st)
{
	return (st.displayStatus(os));
}

void ScavTrap::guardGate()
{
	std::cout << robotType << " ";
	std::cout << name << " guard Gate" << std::endl;
}