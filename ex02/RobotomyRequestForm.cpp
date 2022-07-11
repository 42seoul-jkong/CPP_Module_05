/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : Form(), target() {} // = delete

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : Form("Robotomy Request", 72, 45), target(target)
{
#ifdef VERBOSE
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
#endif
    // No-OP
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& that)
    : Form(that), target(that.target)
{
#ifdef VERBOSE
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
#endif
    // No-OP
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& that)
{
#ifdef VERBOSE
    std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
#endif
    if (this != &that)
    {
        this->RobotomyRequestForm::operator=(that);
        const_cast<std::string&>(this->target) = that.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
#ifdef VERBOSE
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
#endif
    // No-OP
}

void RobotomyRequestForm::executeInternal() const
{
    std::cout << " * [ drilling noises ] * " << std::endl;
    char byte;
    {
        if (!std::ifstream("/dev/urandom").get(byte))
        {
            std::cout << " ! FATAL: Open or Read /dev/urandom failed. ! " << std::endl;
            std::srand(std::time(NULL));
            byte = static_cast<char>(std::rand());
        }
    }
    if (byte & 1)
    {
        std::cout << " * " << this->target << " has been robotomized!! * " << std::endl;
    }
    else
    {
        std::cout << " * " << this->target << " has failed robotomy... * " << std::endl;
    }
}
