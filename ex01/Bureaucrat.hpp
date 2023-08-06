/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:31:06 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/06 15:06:01 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
public:
    Bureaucrat(std::string const& name, int grade);
    Bureaucrat(Bureaucrat const& other);
    Bureaucrat& operator=(Bureaucrat const& other);
    ~Bureaucrat(void);

    const std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

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
    Bureaucrat(void);
    const std::string _name;
    int _grade; // from 1 (Highest Grade) to 150 (Lowest Grade)
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const& other);

#endif
