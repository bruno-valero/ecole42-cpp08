/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:03:08 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/04 20:52:28 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <cmath>
# include <iostream>
# include <limits>
# include <typeinfo>
#include <stdexcept>

class Span
{
	private:
		unsigned int	_size_max;
		int				*_array;
		unsigned int	_size;
		int				_min_value;
		int				_max_value;

	public:
		Span(unsigned int size);
		Span(const Span &other);
		~Span(void);
		Span			&operator=(const Span &other);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		void			addNumber(int number);

		template <typename Iterator>
		void			insert(Iterator begin, Iterator end)
		{
			if (typeid(*begin) != typeid(int))
				throw std::runtime_error("Iterator does not point to the correct type!");
			Iterator begin_copy = begin;
			unsigned int size = 0;
			while (begin_copy != end)
			{
				begin_copy++;
				size++;
			}
			if (size + _size > _size_max)
				throw std::out_of_range("Not enough space in Span to insert elements.");
			while (begin != end)
				addNumber(*(begin++));
		}
};

#endif
