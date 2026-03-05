/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:41:11 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/04 15:55:39 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "easyfind.hpp"

void	test_find(std::vector<int> container, int number)
{
	try
	{
		std::cout << *easyfind(container, number) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "value " << number <<" not found!" << std::endl;
	}
}

int main(void)
{
	std::vector<int> vector;
	vector.reserve(3);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	test_find(vector, 1);
	test_find(vector, 2);
	test_find(vector, 3);
	test_find(vector, 4);
}
