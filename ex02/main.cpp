/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:36:17 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/04 23:32:02 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int> mstack;
	std::cout << "push 5" << std::endl;
	mstack.push(5);
	std::cout << "push 17" << std::endl;
	mstack.push(17);
	std::cout << "top() = " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size() = " << mstack.size() << std::endl;
	std::cout << "push 3" << std::endl;
	mstack.push(3);
	std::cout << "push 5" << std::endl;
	mstack.push(5);
	std::cout << "push 737" << std::endl;
	mstack.push(737);
	std::cout << "push 0" << std::endl;
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	int	idx = 0;
	while (it != ite)
	{
		std::cout << "mystack::iteratot[" << idx << "] = " << *it << std::endl;
		idx++;
		++it;
	}
	std::stack<int> stack(mstack);

	while (--idx >= 0)
	{
		std::cout << "originalStack::iteratot[" << idx << "] = " << stack.top() << std::endl;
		stack.pop();
	}
	return (0);
}
