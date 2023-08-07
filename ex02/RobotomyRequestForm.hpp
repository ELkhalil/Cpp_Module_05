/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:56:31 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/07 22:03:43 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class   RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm ( std::string const& target );
    RobotomyRequestForm ( RobotomyRequestForm const& other );
    ~RobotomyRequestForm ( void );
    RobotomyRequestForm& operator=( RobotomyRequestForm const& other );
    void    execute(Bureaucrat const & executor) const;

private:
    RobotomyRequestForm ( void );
    std::string             _target;
};

#endif