/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

#define PRESIDENT_NAME "Zaphod Beeblebrox"

class PresidentialPardonForm : public Form
{
private:
    const std::string target;

public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& that);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& that);
    ~PresidentialPardonForm();

protected:
    void executeInternal() const;

private:
    PresidentialPardonForm(); // = delete
};
