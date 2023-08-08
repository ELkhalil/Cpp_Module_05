/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:06:29 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/07 22:08:39 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class   PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm ( std::string const& target );
    PresidentialPardonForm ( PresidentialPardonForm const& other );
    ~PresidentialPardonForm ( void );
    PresidentialPardonForm& operator=( PresidentialPardonForm const& other );
    void    execute(Bureaucrat const & executor) const;
private:
    PresidentialPardonForm  ( void );
    std::string             _target;
};

#endif