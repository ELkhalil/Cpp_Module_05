/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:08:58 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/08 08:59:50 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//PresidentialPardonForm Constructors

PresidentialPardonForm::PresidentialPardonForm    ( void )
{
    std::cout << "PresidentialPardonForm Default Constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm ( std::string const& target ) : AForm(target, 25,5), _target(target)
{
    std::cout << "PresidentialPardonForm Parametrized Constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm ( PresidentialPardonForm const& other )
{
    std::cout << "PresidentialPardonForm Copy Constructor" << std::endl;
    (*this) = other;
}

PresidentialPardonForm::~PresidentialPardonForm ( void )
{
    std::cout << "PresidentialPardonForm Destructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( PresidentialPardonForm const& other )
{
    std::cout << "PresidentialPardonForm Copy Assignement Operator" << std::endl;
    if (this != &other)
        this->_target = other._target;
    return (*this);
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned())
        throw(AForm::FormNotSigned());
    if (executor.getGrade() > this->getGradeToExecute())
        throw(AForm::GradeTooLowException());
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}