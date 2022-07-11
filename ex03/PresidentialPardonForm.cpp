/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : Form(), target() {} // = delete

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : Form("Presidential Pardon", 25, 5), target(target)
{
#ifdef VERBOSE
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
#endif
    // No-OP
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& that)
    : Form(that), target(that.target)
{
#ifdef VERBOSE
    std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
#endif
    // No-OP
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& that)
{
#ifdef VERBOSE
    std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
#endif
    if (this != &that)
    {
        this->PresidentialPardonForm::operator=(that);
        const_cast<std::string&>(this->target) = that.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
#ifdef VERBOSE
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
#endif
    // No-OP
}

void PresidentialPardonForm::executeInternal() const
{
    std::cout << this->target << " has been pardoned by " << PRESIDENT_NAME << std::endl;
}
