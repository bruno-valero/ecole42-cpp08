/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:15:40 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/04 23:19:57 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <cstdlib>
# include <stack>

template <class T>
class MutantStack: public std::stack<T>
{
	private:
		typedef typename std::stack<T>::container_type	container_type;

	public:
		typedef typename container_type::iterator		iterator;
		typedef typename container_type::const_iterator	const_iterator;

		MutantStack(void);
		MutantStack(const MutantStack &other);
		~MutantStack(void);
		MutantStack	&operator=(const MutantStack &other);

		iterator		begin();
		const_iterator	begin() const;
		iterator		end();
		const_iterator	end() const;
};

# include "MutantStack.tpp"

#endif
