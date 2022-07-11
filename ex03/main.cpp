/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main()
{
    Bureaucrat president("President", 1);
    Bureaucrat nineth("a 9th grade civil servant", 150);

    ShrubberyCreationForm form_sc("home");
    RobotomyRequestForm form_rr("Seoul");
    PresidentialPardonForm form_pp("Rhee");

    try
    {
        form_sc.execute(president);
        std::cout << "unexpected situation." << std::endl;
        throw 0;
    }
    catch (std::exception& ex)
    {
        std::cout << "Not signed.: " << ex.what() << std::endl;
    }

    try
    {
        form_rr.execute(president);
        std::cout << "unexpected situation." << std::endl;
        throw 0;
    }
    catch (std::exception& ex)
    {
        std::cout << "Not signed.: " << ex.what() << std::endl;
    }

    try
    {
        form_pp.execute(president);
        std::cout << "unexpected situation." << std::endl;
        throw 0;
    }
    catch (std::exception& ex)
    {
        std::cout << "Not signed.: " << ex.what() << std::endl;
    }

    try
    {
        form_sc.beSigned(nineth);
        std::cout << "unexpected situation." << std::endl;
        throw 0;
    }
    catch (std::exception& ex)
    {
        std::cout << "Access denied.: " << ex.what() << std::endl;
    }

    try
    {
        form_rr.beSigned(nineth);
        std::cout << "unexpected situation." << std::endl;
        throw 0;
    }
    catch (std::exception& ex)
    {
        std::cout << "Access denied.: " << ex.what() << std::endl;
    }

    try
    {
        form_pp.beSigned(nineth);
        std::cout << "unexpected situation." << std::endl;
        throw 0;
    }
    catch (std::exception& ex)
    {
        std::cout << "Access denied.: " << ex.what() << std::endl;
    }

    form_sc.beSigned(president);
    form_sc.execute(president);

    form_rr.beSigned(president);
    form_rr.execute(president);

    form_pp.beSigned(president);
    form_pp.execute(president);

    return 0;
}
