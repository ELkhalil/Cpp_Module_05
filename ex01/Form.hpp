/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:06:44 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/07 12:16:48 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class   Form
{
public:
    Form                ( void );
    Form                ( std::string const& name, const int gToSigne, const int gToExecute );
    Form                ( Form const& other );
    ~Form               ( void );
    Form&               operator=( Form const& other );

    const std::string&  getName( void ) const;
    bool                isSigned( void ) const;
    int                 getGradeToSigne( void ) const;
    int                 getGradeToExecute( void ) const;
    void                beSigned( Bureaucrat const& bureaucrat);

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

private:
    const std::string   _name;
    const int           _gradeToSigne;
    const int           _gradeToExecute;
    bool                _isSigned;
};

std::ostream& operator<<(std::ostream& out, Form const& form);

#endif