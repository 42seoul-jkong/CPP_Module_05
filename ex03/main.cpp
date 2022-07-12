/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main()
{
    Bureaucrat president("President", 1);
    Intern chief_of_staff;

    Form* form_sc = chief_of_staff.makeForm("shrubbery creation", "home");
    Form* form_rr = chief_of_staff.makeForm("robotomy request", "Seoul");
    Form* form_pp = chief_of_staff.makeForm("presidential pardon", "Rhee");
    Form* form_unk = chief_of_staff.makeForm("unknown", "Target Name");

    form_sc->beSigned(president);
    form_sc->execute(president);

    form_rr->beSigned(president);
    form_rr->execute(president);

    form_pp->beSigned(president);
    form_pp->execute(president);

    delete form_sc;
    delete form_rr;
    delete form_pp;
    delete form_unk;

    return 0;
}
