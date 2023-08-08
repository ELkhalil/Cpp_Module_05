/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:53:23 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/08 11:05:39 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void    testingShrubberyCreationForm ( void )
{
    // Failure Test Grade too low to sign or Execute
    {
        Bureaucrat  bureaucrat("Master", 150);
        AForm   *form = new ShrubberyCreationForm("home");
        try
        {
            bureaucrat.signForm(*form);
            form->execute(bureaucrat);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete form;
    }
    std::cout << "--------------------------------" << std::endl;
    // Successfull
    {
        Bureaucrat  bureaucrat("Master", 1);
        AForm   *form = new ShrubberyCreationForm("home");
        try
        {
            bureaucrat.signForm(*form);
            form->execute(bureaucrat);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete form;
    }
}

void    testingRobotomyRequestForm ( void )
{
    // Failure Test Grade too low to sign or Execute
    {
        Bureaucrat  bureaucrat("Master", 150);
        AForm   *form = new RobotomyRequestForm("home");
        try
        {
            bureaucrat.signForm(*form);
            form->execute(bureaucrat);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete form;
    }
    std::cout << "--------------------------------" << std::endl;
    // Successfull
    {
        Bureaucrat  bureaucrat("Master", 1);
        AForm   *form = new RobotomyRequestForm("home");
        try
        {
            bureaucrat.signForm(*form);
            form->execute(bureaucrat);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete form;
    }
}

void    testingPresidentialPardonForm ( void )
{
    // Failure Test Grade too low to sign or Execute
    {
        Bureaucrat  bureaucrat("Master", 150);
        AForm   *form = new PresidentialPardonForm("home");
        try
        {
            bureaucrat.signForm(*form);
            form->execute(bureaucrat);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete form;
    }
    std::cout << "--------------------------------" << std::endl;
    // Successfull
    {
        Bureaucrat  bureaucrat("Master", 1);
        AForm   *form = new PresidentialPardonForm("home");
        try
        {
            bureaucrat.signForm(*form);
            form->execute(bureaucrat);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete form;
    }
}

int main( void )
{
    // testingShrubberyCreationForm();
    // testingRobotomyRequestForm();
    // testingPresidentialPardonForm();
    return 0;
}