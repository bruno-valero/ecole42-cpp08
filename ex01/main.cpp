/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 20:00:03 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/04 21:03:04 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <vector>
#include "Span.hpp"

std::vector<int>	generate_random_vector(unsigned int size, int range)
{
	std::srand(std::time(NULL));
	range = range == 0 ? 2000000 : range;
	std::vector<int>	random_vector(size);
	for (unsigned int i = 0; i < size; i++)
	{
		int	rand_int = std::rand() % (range + 1);
		if (std::rand() % 2 == 0)
			rand_int = -rand_int;
		random_vector[i] = rand_int;
	}

	return (random_vector);
}

void	test_from_subject(void)
{
	std::cout << "\n\nTest from Subject!" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Sortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	try
	{
		sp.addNumber(55);
		std::cout << "Sortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	test_with_random_values_1(int size, int range)
{
	size = size == 0 ? 10000 : size;
	std::cout << "\n\nTest " << size << " random values!" << " With range between " << -range << " and " << range << "!" << std::endl;
	std::vector<int>	vector = generate_random_vector(size, range);
	Span sp = Span(size);
	try
	{
		sp.insert(vector.begin(), vector.end());
		std::cout << "Sortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main(void)
{
	test_from_subject();
	test_with_random_values_1(10000, 2000000);
	test_with_random_values_1(500, 2000000);
	test_with_random_values_1(60, 75000);
	return (0);
}
