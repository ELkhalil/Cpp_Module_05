/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:24:12 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/06 17:37:41 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void    testingConstuction ( void )
{
    try
    {
        Bureaucrat  bureaucrat("WrongBureacrat", 0);
        std::cout << bureaucrat;
    }
    catch(Bureaucrat::GradeTooHighException e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void    testingHighGradeIncrementations( void )
{
    Bureaucrat  master("Master", 5);
    std::cout << "the Current status :" << std::endl;
    std::cout << master;
    std::cout << "Rising " << master.getName() << " Grade..." << std::endl;
    try 
    {
        for (int i = 0; i < 10; i++)
        {
            master.incrementGrade();
            std::cout << master;
        }
    }
    catch(Bureaucrat::GradeTooHighException e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void    testingLowGradeIncrementations( void )
{
    Bureaucrat  iron("Iron", 145);
    std::cout << "the Current status :" << std::endl;
    std::cout << iron;
    std::cout << "Lowering " << iron.getName() << " Grade..." << std::endl;
    try 
    {
        for (int i = 0; i < 10; i++)
        {
            iron.decrementGrade();
            std::cout << iron;
        }
    }
    catch(Bureaucrat::GradeTooLowException e)
    {
        std::cerr << e.what() << std::endl;
    }
}


int main( void )
{
    std::cout << " *** Testing False Grade at Construction *** " << std::endl;
    testingConstuction();
    std::cout << std::endl;

    std::cout << " *** Testing Incrementing the Grade *** " << std::endl;
    testingHighGradeIncrementations();
    std::cout << std::endl;
    
    std::cout << " *** Testing Decrementing the Grade *** " << std::endl;
    testingLowGradeIncrementations();
    std::cout << std::endl;

    return 0;
}