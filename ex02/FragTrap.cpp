/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:55:20 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/30 12:15:56 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string n) : ClapTrap(n)
{
	robotType = "FragTrap";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap constructor called for ";
	std::cout << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& b) : ClapTrap(b.name)
{
	robotType = "FragTrap";
	hitPoints = b.hitPoints;
	energyPoints = b.energyPoints;
	attackDamage = b.attackDamage;
	std::cout << "FragTrap copy constructor called for ";
	std::cout << name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& b)
{
	std::cout << "FragTrap copy assignment operator called for ";
	std::cout << name << " to become " << b.name << std::endl;
	name = b.name;
	hitPoints = b.hitPoints;
	energyPoints = b.energyPoints;
	attackDamage = b.attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for ";
	std::cout << name << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap delegates attack to ClapTrap;\n\t";
	ClapTrap::attack(target);
}

void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap delegates takeDamage to ClapTrap;\n\t";
	ClapTrap::takeDamage(amount);
}

void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FragTrap delegates beRepaired to ClapTrap;\n\t";
	ClapTrap::beRepaired(amount);
}

std::ostream& FragTrap::displayStatus(std::ostream& os) const
{
	ClapTrap::displayStatus(os);
	return (os);
}

std::ostream& operator<<(std::ostream& os, const FragTrap& st)
{
	return (st.displayStatus(os));
}

void FragTrap::highFivesGuys()
{
	std::cout << robotType << " ";
	std::cout << name << " High fives!" << std::endl;
}
