/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:31:06 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/06 18:58:20 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
public:
    Bureaucrat          (std::string const& name, int grade);
    Bureaucrat          (Bureaucrat const& other);
    Bureaucrat&         operator=(Bureaucrat const& other);
    ~Bureaucrat         (void);

    const std::string   getName() const;
    int                 getGrade() const;
    void                incrementGrade();
    void                decrementGrade();

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
    Bureaucrat          ( void );
    const std::string   _name;
    int                 _grade;
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const& other);

#endif
