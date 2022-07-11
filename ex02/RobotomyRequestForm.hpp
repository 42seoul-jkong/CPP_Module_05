/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

class RobotomyRequestForm : public Form
{
private:
    const std::string target;

public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& that);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& that);
    ~RobotomyRequestForm();

protected:
    void executeInternal() const;

private:
    RobotomyRequestForm(); // = delete
};
