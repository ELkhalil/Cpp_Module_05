/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:51:57 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/07 21:14:13 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class   ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm   ( std::string const& target );
    ShrubberyCreationForm   ( ShrubberyCreationForm const& other );
    ~ShrubberyCreationForm  ( void );
    ShrubberyCreationForm&  operator=( ShrubberyCreationForm const& other );
    void                    execute (Bureaucrat const & executor) const;
    
private:
    ShrubberyCreationForm   ( void );
    std::string             _target;
};
#endif