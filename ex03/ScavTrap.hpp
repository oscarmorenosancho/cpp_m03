/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:55:11 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/30 12:38:25 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : protected ClapTrap
{
public:
	ScavTrap(std::string n);
	ScavTrap(const ScavTrap& b);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& b);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::ostream& displayStatus(std::ostream& os) const;
	void guardGate();
};

std::ostream& operator<<(std::ostream& os, const ScavTrap& ct);

#endif //__SCAVTRAP_HPP__