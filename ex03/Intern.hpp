/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include "Form.hpp"
#include <string>

class Intern
{
public:
    Intern();
    Intern(const Intern& that);
    Intern& operator=(const Intern& that);
    ~Intern();
    Form* makeForm(const std::string& name, const std::string& target) const;
};

enum FormType
{
    FORM_NONE,
    FORM_SHRUBBERY_CREATION,
    FORM_ROBOTOMY_REQUEST,
    FORM_PRESIDENTIAL_PARDON
};

struct FormTypeEntry
{
    const char* str;
    FormType type;
};
