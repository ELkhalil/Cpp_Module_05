/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:10:53 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/08 12:08:15 by aelkhali         ###   ########.fr       */
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
};

#endif