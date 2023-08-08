/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:53:23 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/08 12:28:17 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
    // Intern Form Creation Failure
    try 
    {
        Intern someRandomIntern;
        AForm* rrf;

        rrf = someRandomIntern.makeForm("hhhh", "Bender");
    }
    catch(Intern::FormNotCreated e)
    {
        std::cerr << e.what() << std::endl;
    }
    // Intern Form Creation Success
    {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
    }
    return 0;
}