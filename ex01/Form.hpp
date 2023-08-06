/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:06:44 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/06 15:16:21 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class   Form
{
public:
    Form    ( void );
    Form    ( Form const& other );
    ~Form   ( void );
    Form&   operator=( Form const& other );

    const std::string&  getName( void ) const;
    bool                isSigned( void ) const;
    const int           getGradeToSigne( void ) const;
    const int           getGradeToExecute( void ) const;
    
    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw()
        {
            return "Grade Too High";
        }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw()
        {
            return "Grade Too Low";
        }
    };
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeToSigne;      // sane as bureaucrats from 1 to 150
    const int           _gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, Form const& other);

#endif