/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:10:55 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/08 15:50:09 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Intern Constructors
Intern::Intern  ( void )
{
    // std::cout << "Intern Default Constructor" << std::endl;
}

Intern::Intern  ( Intern const& other )
{
    // std::cout << "Intern Copy Constructor" << std::endl;
    (*this) = other;
}

Intern&    Intern::operator=( Intern const& other )
{
    // std::cout << "Intern Copy Assignement Operator" << std::endl;
    if (this != &other)
        std::cout << "Nothing to Be copied by the constructor" << std::endl;
    return *this;    
}

Intern::~Intern     ( void )
{
    // std::cout << "Intern Destructor" << std::endl;
}

const char* Intern::FormNotCreated::what( void ) const throw()
{
    return ("Form Not Created By Intern");
}

// Intern Methods
AForm*      Intern::_cloneShrubberyCreationForm(std::string const& target)
{
    return (new ShrubberyCreationForm(target));
}
AForm*      Intern::_cloneRobotomyRequestForm(std::string const& target)
{
    return (new RobotomyRequestForm(target));
}
AForm*      Intern::_clonePresidentialPardonForm(std::string const& target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string const& _formName, std::string const& _formTarget)
{
    int i = 0;
    std::string _availableForms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*ptrTofunc[3])(std::string const&) = { &Intern::_cloneShrubberyCreationForm,
                                                           &Intern::_cloneRobotomyRequestForm,
                                                           &Intern::_clonePresidentialPardonForm };
    while (i < 3 && _formName != _availableForms[i])
        i++;
    if (i < 3)
    {
        std::cout << "Intern creates " << _formName << std::endl;
        return (this->*ptrTofunc[i])(_formTarget);
    }
    else
        throw Intern::FormNotCreated();
    return NULL;
}