/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:24:12 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/06 14:58:51 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
    {
        try {
            Bureaucrat  bureaucrat("test", -100);
            std::cout << bureaucrat.getGrade() << std::endl;
        }
        catch(Bureaucrat::GradeTooHighException e)
        {
            std::cout << e.what() << std::endl;
        }
        catch(Bureaucrat::GradeTooLowException e)
        {
            std::cout << e.what() << std::endl;
        }
        try 
        {
            Bureaucrat  bureaucrat2("test", 2);
            std::cout << bureaucrat2.getGrade() << std::endl;
            bureaucrat2.incrementGrade();
            std::cout << bureaucrat2.getGrade() << std::endl;
            bureaucrat2.incrementGrade();
            std::cout << bureaucrat2.getGrade() << std::endl;
        }
        catch(Bureaucrat::GradeTooHighException e)
        {
            std::cout << e.what() << std::endl;
        }
        catch(Bureaucrat::GradeTooLowException e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    
    return 0;
}