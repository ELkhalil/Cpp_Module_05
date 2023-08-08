/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:10:53 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/08 15:11:11 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class   Intern
{
public:
    Intern      ( void );
    Intern      ( Intern const& other );
    Intern&     operator=( Intern const& other );
    ~Intern     ( void );
    
    AForm*      makeForm(std::string const& _formName, std::string const& _formTarget);
    class       FormNotCreated : public std::exception
    {
        public:
            const char* what( void ) const throw();
    };
private:
    AForm*      _cloneShrubberyCreationForm(std::string const& target);
    AForm*      _cloneRobotomyRequestForm(std::string const& target);
    AForm*      _clonePresidentialPardonForm(std::string const& target);
};

#endif