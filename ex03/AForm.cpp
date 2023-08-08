/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:49:52 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/08 15:49:53 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// AForm Constructors
AForm::AForm  ( void ) : _name("DefaultAForm"), _gradeToSigne(10), _gradeToExecute(10), _isSigned(false)
{
    // std::cout << "AForm Default Constructor" << std::endl;
    std::cout << "A Default AForm Created Successfully" << std::endl;
    std::cout << "Checking AForm Infos..." << std::endl;
    std::cout << "isSigned : " << this->_isSigned;
    std::cout << "gradeToSignee : " << this->_gradeToSigne;
    std::cout << "gradeToExecute : " << this->_gradeToExecute;
}

AForm::AForm    ( std::string const& name, const int gToSigne, const int gToExecute )
    : _name(name), _gradeToSigne(gToSigne), _gradeToExecute(gToExecute), _isSigned(false)
{
    // std::cout << "AForm Parametrized Constructor" << std::endl;
    if (_gradeToSigne < 1 || _gradeToExecute < 1)
        throw(AForm::GradeTooHighException());
    else if (_gradeToSigne > 150 || _gradeToExecute > 150)
        throw(AForm::GradeTooLowException());
}

AForm::AForm    ( AForm const& other ) 
    : _name(other._name), _gradeToSigne(other._gradeToSigne), _gradeToExecute(other._gradeToExecute), _isSigned(false)
{
    // std::cout << "AForm Copy Constructor" << std::endl;
}

AForm::~AForm     ( void )
{
    // std::cout << "AForm Destructor" << std::endl;
}

// AForm Copy Assignement Operator
AForm&   AForm::operator=( AForm const& other )
{
    // std::cout << "AForm Copy Assignement Operator" << std::endl;
    if (this != &other)
    {
        this->_isSigned = other.isSigned();
    }
    return *this;
}

// AForm Getter Methods
const std::string&  AForm::getName( void ) const { return this->_name; }
bool                AForm::isSigned( void ) const { return this->_isSigned; }
int                 AForm::getGradeToSigne( void ) const { return this->_gradeToSigne; }
int                 AForm::getGradeToExecute( void ) const { return this->_gradeToExecute; }

// AForm Exception Ovveride
const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}

const char* AForm::FormNotSigned::what() const throw()
{
    return ("Form Not Signed");
}

// Overloading the insertion Operator
std::ostream& operator<<(std::ostream& out, AForm const& form)
{
    out << "*** Form Informations ***" << std::endl;
    out << "Form Name: " << form.getName() << std::endl;
    out << "Form Signature: ";
    if (form.isSigned())
        out << "true" << std::endl;
    else
        out << "false" << std::endl;
    out << "Form Grade To Sign: " << form.getGradeToSigne() << std::endl;
    out << "Form Grade To Execute: " << form.getGradeToExecute() << std::endl;
    return out;
}

// Form Link to Bureaucrat
void    AForm::beSigned( Bureaucrat const& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSigne)
        throw(AForm::GradeTooLowException());
    else
        this->_isSigned = true;
}
