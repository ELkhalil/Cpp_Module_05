/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:33 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/08 10:42:26 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// ShrubberyCreationForm Constructors
ShrubberyCreationForm::ShrubberyCreationForm   ( void )
{
    std::cout << "ShrubberyCreationForm Default Constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm   ( std::string const& target ) : AForm(target, 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm Parametrized Constructor" << std::endl;
    
}

ShrubberyCreationForm::ShrubberyCreationForm   ( ShrubberyCreationForm const& other )
{
    std::cout << "ShrubberyCreationForm Copy Constructor" << std::endl;
    (*this) = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm  ( void )
{
    std::cout << "ShrubberyCreationForm Destructor" << std::endl;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=( ShrubberyCreationForm const& other )
{
    std::cout << "ShrubberyCreationForm Copy Assignement Operator" << std::endl;
    if(this != &other)
        this->_target = other._target;
    return (*this);
}

void    ShrubberyCreationForm::execute (Bureaucrat const & executor) const
{
    if (!this->isSigned())
        throw(AForm::FormNotSigned());
    if (executor.getGrade() > this->getGradeToExecute())
        throw(AForm::GradeTooLowException());
    std::ofstream   outputF(this->_target + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
    if (outputF.fail())
    {
        std::cerr << "Error: Creating The Output File..." << std::endl;
        std::exit(1);
    }
    std::string asciiTree =   
                "      _-_        \n"
                "   /~~   ~~\\    \n"
                " /~~       ~~\\ \n"
                "/{            }\\\n"
                "\\  _-     -_  /\n"
                "  ~  \\\\ //  ~\n "
                "_- - | | _- _\n"
                "  _ - | |   -_ \n"
                "     // \\\\ \n"
                "-----     -----\n";
    outputF << asciiTree;
    outputF.close();
}