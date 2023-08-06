/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:45:45 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/06 13:12:08 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Bureaucrat Constructors
Bureaucrat::Bureaucrat  ( void )
{
    std::cout << "Bureaucrat Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat  ( std::string const& name, int grade ) : _name(name)
{
    std::cout << "Bureaucrat Parametrized Constructor" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat  ( Bureaucrat const& other )
{
    std::cout << "Bureaucrat Copy Constructor" << std::endl;
    (*this) = other;
}

Bureaucrat::~Bureaucrat  ( void )
{
    std::cout << "Bureaucrat Destructor" << std::endl;
}

// Bureaucrat Operators
Bureaucrat& Bureaucrat::operator=( Bureaucrat const& other )
{
    std::cout << "Bureaucrat Copy Assignement Operators" << std::endl;
    if (this != &other)
    {
        (std::string)this->_name = other.getName();
        this->_grade = other.getGrade();
    }
    return (*this);
}

// Bureaucrat Methods
const std::string Bureaucrat::getName( void ) const
{
    return (this->_name);
}

int Bureaucrat::getGrade( void ) const
{
    return (this->_grade);
}

void    Bureaucrat::incrementGrade( void )
{
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade --;
}

void    Bureaucrat::decrementGrade( void )
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade ++;
}

// Output Stream Overload
std::ostream& operator<< (std::ostream &out, Bureaucrat const &other)
{
    out << other.getName() <<  ", bureaucrat grade " << other.getGrade() << std::endl;
    return out;
}