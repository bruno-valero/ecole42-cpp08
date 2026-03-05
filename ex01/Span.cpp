/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:15:31 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/04 20:28:24 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <algorithm>

Span::Span(unsigned int size): _size_max(size), _array(new int[size]), _size(0), _min_value(std::numeric_limits<int>::max()), _max_value(std::numeric_limits<int>::min()) {};
Span::Span(const Span &other): _size_max(other._size_max), _array(new int[other._size_max]), _size(other._size), _min_value(other._min_value), _max_value(other._max_value)
{
	for (unsigned int i = 0; i < _size_max; i++)
		_array[i] = other._array[i];
};

Span::~Span(void)
{
	std::cout << "Destroying::Span()" << std::endl;
};

Span			&Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	_min_value = other._min_value;
	_max_value = other._max_value;
	_size = other._size;
	if (_size_max != other._size_max)
	{
		_size_max = other._size_max;
		if (_array)
			delete[] _array;
		if (other._size_max == 0)
		{
			_array = NULL;
			return (*this);
		}
	}
	_array = new int[_size_max];
	for (unsigned int i = 0; i < _size_max; i++)
		_array[i] = other._array[i];
	return (*this);
};

unsigned int	Span::shortestSpan(void) const
{
	if (_size == 0 || _size == 1) throw	std::runtime_error("Not enough elements to calculate Span!");

	std::vector<unsigned int> vector(_array, _array + _size);
	std::sort(vector.begin(), vector.end());

	unsigned int	lowest_diff = std::numeric_limits<unsigned int>::max();
	for (unsigned int i = 1; i < vector.size(); i++)
	{
		unsigned int	diff = static_cast<unsigned int>(vector[i] - vector[i - 1]);
		if (diff < lowest_diff)
			lowest_diff = diff;
	}
	return (lowest_diff);
};

unsigned int	Span::longestSpan(void) const
{
	if (_size == 0 || _size == 1) throw std::runtime_error("Not enough elements to calculate Span!");
	unsigned int	diff = static_cast<unsigned int>(_max_value - _min_value);
	return (diff);
};

void			Span::addNumber(int number)
{
	if (_size == _size_max) throw std::out_of_range("Not enough space in Span to insert elements.");
	_array[_size++] = number;
	if (number < _min_value)
		_min_value = number;
	if (number > _max_value)
		_max_value = number;
};
