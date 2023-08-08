/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:31:06 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/08 09:52:15 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
class   AForm;

class Bureaucrat
{
public:
    Bureaucrat          ( void );
    Bureaucrat          (std::string const& name, int grade);
    Bureaucrat          (Bureaucrat const& other);
    Bureaucrat&         operator=(Bureaucrat const& other);
    ~Bureaucrat         (void);

    const std::string   getName() const;
    int                 getGrade() const;
    void                incrementGrade();
    void                decrementGrade();
    void                signForm(AForm& form);
    void                executeForm(AForm const & form);
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
    const std::string   _name;
    int                 _grade;
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const& other);

#endif
