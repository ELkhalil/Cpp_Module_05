/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:24:12 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/07 19:43:39 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void    testingFormExceptions( void )
{
    try
    {
        Form    form("Test", -1, 0);
    }
    catch (Form::GradeTooHighException e)
    {
        std::cerr << "Exception: ";
        std::cerr << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException e)
    {
        std::cerr << "Exception: ";
        std::cerr << e.what() << std::endl;
    }
}

int main( void )
{
    std::cout << "-----Construction of Objects-----" << std::endl;
    std::cout << "----------------------" << std::endl;
    Bureaucrat  master("Master", 150);
    Form        form("Beginnger", 10, 5);
    std::cout << "-----Construction End-----" << std::endl << std::endl;

    std::cout << master;
    std::cout << form;
    master.signForm(form);

    std::cout << std::endl;
    std::cout << "-----Destruction of Objects-----" << std::endl;
    return 0;
}