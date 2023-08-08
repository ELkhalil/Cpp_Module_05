/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:06:44 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/08 09:56:19 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class   AForm
{
public:
    AForm                ( void );
    AForm                ( std::string const& name, const int gToSigne, const int gToExecute );
    AForm                ( AForm const& other );
    virtual ~AForm       ( void );
    AForm&               operator=( AForm const& other );

    const std::string&   getName( void ) const;
    bool                 isSigned( void ) const;
    int                  getGradeToSigne( void ) const;
    int                  getGradeToExecute( void ) const;
    void                 beSigned( Bureaucrat const& bureaucrat);
    virtual void         execute(Bureaucrat const & executor) const = 0;
    
    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };
    class FormNotSigned : public std::exception
    {
    public:
        const char* what() const throw();
    };
private:
    const std::string    _name;
    const int            _gradeToSigne;
    const int            _gradeToExecute;
    bool                 _isSigned;
};

std::ostream& operator<<(std::ostream& out, AForm const& form);

#endif