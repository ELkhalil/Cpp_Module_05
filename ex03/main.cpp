/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:53:23 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/08 16:00:06 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


void    InternCreationForm( std::string formName )
{
    std::cout << "***Testing The Case Where Intern can't Create " << formName << " ***" << std::endl;
    try
    {
        Intern  ahmed;
        AForm*  shrubBeryTest;
        shrubBeryTest = ahmed.makeForm(formName + "Nothing", "TestForm");
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "*** Testing The Case Where Intern Creates "<< formName << " ***" << std::endl;
    try
    {
        Bureaucrat  bureaucrat("Master", 1);
        Intern  ahmed;
        AForm*  shrubBeryTest;
        shrubBeryTest = ahmed.makeForm(formName, "TestForm");
        shrubBeryTest->beSigned(bureaucrat);
        shrubBeryTest->execute(bureaucrat);
        delete shrubBeryTest;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void    subjectTest( void )
{
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
    }
}

int main( void )
{
    InternCreationForm("shrubbery creation");
    std::cout << "----------------" << std::endl;
    InternCreationForm("robotomy request");
    std::cout << "----------------" << std::endl;
    InternCreationForm("presidential pardon");
    std::cout << "----------------" << std::endl;
    std::cout << "***** Subject Test ******" << std::endl;
    std::cout << "----------------" << std::endl;
    subjectTest();
    return 0;
}