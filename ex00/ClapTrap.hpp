/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:30:39 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/29 11:57:31 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

# include <string>

class ScavTrap
{
private:
	static ScavTrap* list;
	ScavTrap* next;
	std::string name;
	int hitPoints;
	int energyPoints;
	int	attackDamage;
	ScavTrap*	findTarget(const std::string& target);

public:
	ScavTrap(std::string n);
	ScavTrap(const ScavTrap& b);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& b);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::ostream& displayStatus(std::ostream& os) const;
	static void	displayList(std::ostream& os);
};

std::ostream& operator<<(std::ostream& os, const ScavTrap& ct);

#endif //__CLAPTRAP__