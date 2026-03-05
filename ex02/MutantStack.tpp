/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:15:36 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/04 23:24:06 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include <stack>

template<typename T>
MutantStack<T>::MutantStack(void): std::stack<T>() {};

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other): std::stack<T>(other) {};

template<typename T>
MutantStack<T>::~MutantStack(void) {};

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &other)
{
	if (this == &other)
		return (*this);
	this->c = other.c;
	return (*this);
};

template<typename T>
typename MutantStack<T>::iterator		MutantStack<T>::begin()
{
	return (this->c.begin());
};

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return (this->c.begin());
};

template<typename T>
typename MutantStack<T>::iterator		MutantStack<T>::end()
{
	return (this->c.end());
};

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return (this->c.end());
};

#endif
