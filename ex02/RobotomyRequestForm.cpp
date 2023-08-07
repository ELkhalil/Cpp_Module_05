/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:00:09 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/07 22:04:43 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//RobotomyRequestForm Constructors

RobotomyRequestForm::RobotomyRequestForm    ( void )
{
    std::cout << "RobotomyRequestForm Default Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm ( std::string const& target ) : AForm(target, 72,45), _target(target)
{
    std::cout << "RobotomyRequestForm Parametrized Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm ( RobotomyRequestForm const& other )
{
    std::cout << "RobotomyRequestForm Copy Constructor" << std::endl;
    (*this) = other;
}

RobotomyRequestForm::~RobotomyRequestForm ( void )
{
    std::cout << "RobotomyRequestForm Destructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( RobotomyRequestForm const& other )
{
    std::cout << "RobotomyRequestForm Copy Assignement Operator" << std::endl;
    if (this != &other)
        this->_target = other._target;
    return (*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    
}