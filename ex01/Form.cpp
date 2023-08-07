/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:44:14 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/07 12:28:15 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Form Constructors
Form::Form  ( void ) : _name("DefaultForm"), _gradeToSigne(10), _gradeToExecute(10), _isSigned(false)
{
    std::cout << "Form Default Constructor" << std::endl;
    std::cout << "A Default Form Created Successfully" << std::endl;
    std::cout << "Checking Form Infos..." << std::endl;
    std::cout << "isSigned : " << this->_isSigned;
    std::cout << "gradeToSignee : " << this->_gradeToSigne;
    std::cout << "gradeToExecute : " << this->_gradeToExecute;
}

Form::Form    ( std::string const& name, const int gToSigne, const int gToExecute )
    : _name(name), _gradeToSigne(gToSigne), _gradeToExecute(gToExecute), _isSigned(false)
{
    std::cout << "Form Parametrized Constructor" << std::endl;
    if (_gradeToSigne < 1 || _gradeToExecute < 1)
        throw(Form::GradeTooHighException());
    else if (_gradeToSigne > 150 || _gradeToExecute > 150)
        throw(Form::GradeTooLowException());
}

Form::Form    ( Form const& other ) 
    : _name(other._name), _gradeToSigne(other._gradeToSigne), _gradeToExecute(other._gradeToExecute), _isSigned(false)
{
    std::cout << "Form Copy Constructor" << std::endl;
}

Form::~Form     ( void )
{
    std::cout << "Form Destructor" << std::endl;
}

// Form Copy Assignement Operator
Form&   Form::operator=( Form const& other )
{
    std::cout << "Form Copy Assignement Operator" << std::endl;
    if (this != &other)
        *this = Form(other);
    return *this;
}

// Form Getter Methods
const std::string&  Form::getName( void ) const { return this->_name; }
bool                Form::isSigned( void ) const { return this->_isSigned; }
int           Form::getGradeToSigne( void ) const { return this->_gradeToSigne; }
int           Form::getGradeToExecute( void ) const { return this->_gradeToExecute; }

// Form Exception Ovveride
const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}
const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}

// Overloading the insertion Operator
std::ostream& operator<<(std::ostream& out, Form const& form)
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
void    Form::beSigned( Bureaucrat const& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSigne)
        throw(Form::GradeTooLowException());
    else
        this->_isSigned = true;
}