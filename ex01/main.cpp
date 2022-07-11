/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main()
{
    Bureaucrat president("President", 1);
    Bureaucrat nineth("a 9th grade civil servant", 150);
    Form form("Appointment of a Minister", 15, 1);

    try
    {
        Form forge("King's sign", 0, 1);
        std::cout << "unexpected situation." << std::endl;
        throw 0;
    }
    catch (std::exception& ex)
    {
        std::cout << "It's not a monarchy.: " << ex.what() << std::endl;
    }

    try
    {
        Form forge("King's execute", 1, 0);
        std::cout << "unexpected situation." << std::endl;
        throw 0;
    }
    catch (std::exception& ex)
    {
        std::cout << "It's not a monarchy.: " << ex.what() << std::endl;
    }

    try
    {
        Form forge("ten's sign", 151, 150);
        std::cout << "unexpected situation." << std::endl;
        throw 0;
    }
    catch (std::exception& ex)
    {
        std::cout << "There are no Grade 10 civil servants.: " << ex.what() << std::endl;
    }

    try
    {
        Form forge("ten's execute", 150, 151);
        std::cout << "unexpected situation." << std::endl;
        throw 0;
    }
    catch (std::exception& ex)
    {
        std::cout << "There are no Grade 10 civil servants.: " << ex.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << form << std::endl;

    std::cout << std::endl;
    nineth.signForm(form);
    std::cout << form << std::endl;

    std::cout << std::endl;
    president.signForm(form);
    std::cout << form << std::endl;

    std::cout << std::endl;
    nineth.signForm(form);
    std::cout << form << std::endl;

    return 0;
}
