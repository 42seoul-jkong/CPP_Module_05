/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() {} // = delete

Bureaucrat::Bureaucrat(const std::string& name, Bureaucrat::grade_t grade)
    : name(name), grade(grade)
{
#ifdef VERBOSE
    std::cout << "Bureaucrat Default constructor called" << std::endl;
#endif
    if (grade < Bureaucrat::higest_grade)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > Bureaucrat::lowest_grade)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& that)
{
#ifdef VERBOSE
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
#endif
    *this = that;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& that)
{
#ifdef VERBOSE
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
#endif
    if (this != &that)
    {
        const_cast<std::string&>(this->name) = that.name;
        this->grade = that.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
#ifdef VERBOSE
    std::cout << "Bureaucrat Destructor called" << std::endl;
#endif
    // No-OP
}

const std::string& Bureaucrat::getName() const
{
    return this->name;
}

Bureaucrat::grade_t Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::promote()
{
    Bureaucrat::grade_t new_grade = this->grade - 1;
    if (new_grade < Bureaucrat::higest_grade)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade = new_grade;
}

void Bureaucrat::demote()
{
    Bureaucrat::grade_t new_grade = this->grade + 1;
    if (new_grade > Bureaucrat::lowest_grade)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade = new_grade;
}

void Bureaucrat::signForm(Form& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << *this << " signed " << form << std::endl;
    }
    catch (std::exception& ex)
    {
        std::cout << *this << " couldn't sign " << form << " because " << ex.what() << std::endl;
    }
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "bureaucrat grade too high";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "bureaucrat grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
}
