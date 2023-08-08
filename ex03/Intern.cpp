/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:10:55 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/08 12:25:48 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Intern Constructors
Intern::Intern  ( void )
{
    std::cout << "Intern Default Constructor" << std::endl;
}

Intern::Intern  ( Intern const& other )
{
    std::cout << "Intern Copy Constructor" << std::endl;
    (*this) = other;
}

Intern&    Intern::operator=( Intern const& other )
{
    std::cout << "Intern Copy Assignement Operator" << std::endl;
    if (this != &other)
        std::cout << "Nothing to Be copied by the constructor" << std::endl;
    return *this;    
}

Intern::~Intern     ( void )
{
    std::cout << "Intern Destructor" << std::endl;
}

const char* Intern::FormNotCreated::what( void ) const throw()
{
    return ("Form Not Created By Intern");
}

 AForm*      Intern::makeForm(std::string const& _formName, std::string const& _formTarget)
{
    std::string     _availableForms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int             i = 0;

    for (i = 0; i < 3; i++)
    {
        if (_formName == _availableForms[i])
            break;
    }
    switch(i)
    {
        case 0:
            std::cout << "Intern " << "creates " << _formName << std::endl;
            return(new ShrubberyCreationForm(_formTarget));
            break;
        case 1:
            std::cout << "Intern " << "creates " << _formName << std::endl;
            return(new RobotomyRequestForm(_formTarget));
            break;
        case 2:
            std::cout << "Intern " << "creates " << _formName << std::endl;
            return(new PresidentialPardonForm(_formTarget));
            break;
        default:
            throw(Intern::FormNotCreated());
    }
    return NULL;
}