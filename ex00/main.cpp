/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
    Bureaucrat president("President", 1);
    Bureaucrat nineth("a 9th grade civil servant", 150);
    Bureaucrat nineth2(nineth);
    nineth2 = nineth;

    try
    {
        Bureaucrat king("King", 0);
        std::cout << "unexpected situation." << std::endl;
        throw 0;
    }
    catch (std::exception& ex)
    {
        std::cout << "It's not a monarchy.: " << ex.what() << std::endl;
    }

    try
    {
        Bureaucrat ten_degree("a ten-degree civil servant", 151);
        std::cout << "unexpected situation." << std::endl;
        throw 0;
    }
    catch (std::exception& ex)
    {
        std::cout << "There are no Grade 10 civil servants.: " << ex.what() << std::endl;
    }

    try
    {
        president.promote();
        std::cout << "unexpected situation." << std::endl;
        throw 0;
    }
    catch (std::exception& ex)
    {
        std::cout << "The president can't get a raise.: " << ex.what() << std::endl;
    }

    try
    {
        nineth.demote();
        std::cout << "unexpected situation." << std::endl;
        throw 0;
    }
    catch (std::exception& ex)
    {
        std::cout << "Cannot go lower than level nine.: " << ex.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "To. " << nineth << std::endl;
    nineth.promote();
    std::cout << "Congratulations! You've been promoted." << std::endl;
    std::cout << "Now you're " << nineth << " Please be responsible." << std::endl;

    std::cout << std::endl;
    std::cout << "To. " << president << std::endl;
    president.demote();
    std::cout << "President, an impeachment motion has been proposed." << std::endl;
    std::cout << "Your authority has been suspended, and now you're " << president << std::endl;

    return 0;
}
