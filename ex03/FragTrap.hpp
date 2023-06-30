/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:55:11 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/30 12:37:20 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

# include <string>
# include "ClapTrap.hpp"

class FragTrap : protected ClapTrap
{
public:
	FragTrap(std::string n);
	FragTrap(const FragTrap& b);
	~FragTrap();
	FragTrap& operator=(const FragTrap& b);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::ostream& displayStatus(std::ostream& os) const;
	static void	displayList(std::ostream& os);
    void highFivesGuys(void);
};

std::ostream& operator<<(std::ostream& os, const FragTrap& ct);

#endif //__FRAGTRAP_HPP__