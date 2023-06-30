/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:11:41 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/30 12:47:57 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : ScavTrap, FragTrap
{
private:
	std::string name;
public:
	DiamondTrap(std::string n);
	DiamondTrap(const DiamondTrap& b);
	~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap& b);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::ostream& displayStatus(std::ostream& os) const;
	void guardGate();
    void highFivesGuys(void);
	void whoAmI();
};

#endif //__DIAMONDTRAP_HPP__