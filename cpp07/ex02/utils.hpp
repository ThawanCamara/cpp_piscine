/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:41:45 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/07 17:47:28 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "Array.hpp"
# include <iostream>
# include <stdint.h>

typedef struct data
{
	int id;
	uintptr_t data;
}	data;

template <typename T>
void printContainer(Array<T> &arr)
{
	int len = arr.size();
	
	std::cout << "[ ";
	for (int i = 0; i < len ; i++)
	{
		if (i > 0)
			std::cout << ", ";
		std::cout << arr[i];
	}
	std::cout << " ]" << std::endl;
}

#endif