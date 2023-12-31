/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:30:39 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/30 11:15:46 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

# include <string>

class ClapTrap
{
private:
	static ClapTrap* list;
	ClapTrap* next;
	std::string name;
	int hitPoints;
	int energyPoints;
	int	attackDamage;
	ClapTrap*	findTarget(const std::string& target);

public:
	ClapTrap(std::string n);
	ClapTrap(const ClapTrap& b);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& b);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::ostream& displayStatus(std::ostream& os) const;
	static void	displayList(std::ostream& os);
};

std::ostream& operator<<(std::ostream& os, const ClapTrap& ct);

#endif //__CLAPTRAP__