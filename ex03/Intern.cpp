/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {} // = default

Intern::Intern(const Intern& that) { (void)&that; } // = default

Intern& Intern::operator=(const Intern& that)
{
    (void)&that;
    return *this;
} // = default

Intern::~Intern() {} // = default

static void string_lowcase(std::string& str)
{
    for (std::string::iterator it = str.begin(); it != str.end(); it++)
    {
        *it = std::tolower(*it);
    }
}

static FormType get_form_type(std::string name)
{
    string_lowcase(name);
    FormTypeEntry cls[] = {
        {"shrubbery creation", FORM_SHRUBBERY_CREATION},
        {"robotomy request", FORM_ROBOTOMY_REQUEST},
        {"presidential pardon", FORM_PRESIDENTIAL_PARDON},
    };
    for (std::size_t i = 0; i < sizeof(cls) / sizeof(cls[0]); i++)
    {
        if (name == cls[i].str)
        {
            return cls[i].type;
        }
    }
    return FORM_NONE;
}

Form* Intern::makeForm(const std::string& name, const std::string& target) const
{
    FormType type = get_form_type(name);
    Form* form;
    switch (type)
    {
    case FORM_SHRUBBERY_CREATION:
        form = new ShrubberyCreationForm(target);
        break;
    case FORM_ROBOTOMY_REQUEST:
        form = new RobotomyRequestForm(target);
        break;
    case FORM_PRESIDENTIAL_PARDON:
        form = new PresidentialPardonForm(target);
        break;
    default:
        form = NULL;
        break;
    }
    if (form)
    {
        std::cout << "Intern creates " << *form << std::endl;
    }
    else
    {
        std::cout << "Form not found.: " << name << " (target: " << target << ")" << std::endl;
    }
    return form;
}
