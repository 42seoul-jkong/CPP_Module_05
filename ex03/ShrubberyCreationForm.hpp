/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public Form
{
private:
    const std::string target;

public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& that);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& that);
    ~ShrubberyCreationForm();

protected:
    void executeInternal() const;

private:
    ShrubberyCreationForm(); // = delete
};
