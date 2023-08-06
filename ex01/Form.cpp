/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:44:14 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/06 18:53:58 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Form Constructor
Form::Form    ( void ) 
{
    std::cout << "Form Default Constructor" << std::endl;
}

Form::Form    ( Form const& other )
{
    std::cout << "Form Copy Constructor" << std::endl;
    (*this) = other;
}

