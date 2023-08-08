/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:00:09 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/08 10:56:03 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

int RobotomyRequestForm::_count = 0;

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
    if (!this->isSigned())
        throw(AForm::FormNotSigned());
    if (executor.getGrade() > this->getGradeToExecute())
        throw(AForm::GradeTooLowException());
    if (this->_count % 2 == 0)
    {
        std::cout << "Zzzz......!!!! Zzzz......!!!!" << std::endl;
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << this->_target << " robotomy failed." << std::endl;
    }
    this->_count++;
}