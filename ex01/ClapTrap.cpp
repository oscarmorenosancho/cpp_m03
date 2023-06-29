/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:20:25 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/29 12:01:50 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ClapTrap.hpp"

ClapTrap* ClapTrap::list = nullptr;

ClapTrap::ClapTrap(std::string n) : name(n)
{
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	next = list;
	list = this;
	std::cout << "ClapTrap constructor called for ";
	std::cout << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& b) : name(b.name)
{
	hitPoints = b.hitPoints;
	energyPoints = b.energyPoints;
	attackDamage = b.attackDamage;
	next = list;
	list = this;
	std::cout << "ClapTrap copy constructor called for ";
	std::cout << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& b)
{
	std::cout << "ClapTrap copy assignment operator called for ";
	std::cout << name << " to become " << b.name << std::endl;
	name = b.name;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	if (list == this)
		list = next;
	else
	{	
		ClapTrap* cur = list;
		while (cur && cur->next != this)
			cur = cur->next;
		if (cur && cur->next == this)
			cur->next = this->next;
	}
	next = nullptr;
	std::cout << "ClapTrap destructor called for ";
	std::cout << name << std::endl;
}

ClapTrap*	ClapTrap::findTarget(const std::string& target)
{
	ClapTrap* cur = list;
	while (cur && (cur->name!=target || cur == this))
		cur = cur->next;
	return (cur);
}

void ClapTrap::attack(const std::string& target)
{
	ClapTrap* ct = findTarget(target);
	if (!ct)
	{
		std::cout << "ClapTrap " << name << " can't attack " << target;
		std::cout << ", because target " << target;
		std::cout << " does't exist!" << std::endl;
		return ;
	}
	if (hitPoints > 0 && energyPoints > 0)
	{
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target;
		std::cout << ", causing " << attackDamage;
		std::cout << " points of damage! ";
		if (energyPoints > 0)
			std::cout << energyPoints << " energy points left!" << std::endl;
		else
			std::cout << "No energy points left!" << std::endl;
		
		ct->takeDamage(attackDamage);
		return ;
	}
	std::cout << "ClapTrap " << name << " can't attack " << target;
	std::cout << ", because don't have enough Energy or Hit Points!";
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	if (hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " got " << amount << " damage points. ";
		std::cout << hitPoints << " hit points left!" << std::endl;

	}
	else
	{
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " got " << amount << " damage points. ";
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
			std::cout << energyPoints << " energy points left!" << std::endl;
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

void	ClapTrap::displayList(std::ostream& os)
{
	ClapTrap* cur = list;
	while (cur)
	{
		cur->displayStatus(os);
		cur = cur->next;
	}
}

std::ostream& operator<<(std::ostream& os, const ClapTrap& ct)
{
	return (ct.displayStatus(os));
}

