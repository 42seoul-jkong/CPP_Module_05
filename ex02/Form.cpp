/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Form.hpp"
#include <iostream>

Form::Form()
    : name(), reqSignGrade(), reqExecGrade() {} // = delete

Form::Form(const std::string& name, Bureaucrat::grade_t reqSignGrade, Bureaucrat::grade_t reqExecGrade)
    : name(name), signatured(false), reqSignGrade(reqSignGrade), reqExecGrade(reqExecGrade)
{
#ifdef VERBOSE
    std::cout << "Form Default constructor called" << std::endl;
#endif
    if (reqSignGrade < Bureaucrat::higest_grade)
    {
        throw Form::GradeTooHighException(true);
    }
    if (reqSignGrade > Bureaucrat::lowest_grade)
    {
        throw Form::GradeTooLowException(true);
    }
    if (reqExecGrade < Bureaucrat::higest_grade)
    {
        throw Form::GradeTooHighException(false);
    }
    if (reqExecGrade > Bureaucrat::lowest_grade)
    {
        throw Form::GradeTooLowException(false);
    }
}

Form::Form(const Form& that)
    : name(that.name), signatured(that.signatured), reqSignGrade(that.reqSignGrade), reqExecGrade(that.reqExecGrade)
{
#ifdef VERBOSE
    std::cout << "Form Copy constructor called" << std::endl;
#endif
    // No-OP
}

Form& Form::operator=(const Form& that)
{
#ifdef VERBOSE
    std::cout << "Form Copy assignment operator called" << std::endl;
#endif
    if (this != &that)
    {
        const_cast<std::string&>(this->name) = that.name;
        this->signatured = that.signatured;
        const_cast<Bureaucrat::grade_t&>(this->reqSignGrade) = that.reqSignGrade;
        const_cast<Bureaucrat::grade_t&>(this->reqExecGrade) = that.reqExecGrade;
    }
    return *this;
}

Form::~Form()
{
#ifdef VERBOSE
    std::cout << "Form Destructor called" << std::endl;
#endif
    // No-OP
}

const std::string& Form::getName() const
{
    return this->name;
}

bool Form::isSignatured() const
{
    return this->signatured;
}

Bureaucrat::grade_t Form::getReqSignGrade() const
{
    return this->reqSignGrade;
}

Bureaucrat::grade_t Form::getReqExecGrade() const
{
    return this->reqExecGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->reqSignGrade)
    {
        throw Form::GradeTooLowException(true);
    }
    this->signatured = true;
}

void Form::execute(const Bureaucrat& bureaucrat) const
{
    if (!this->signatured)
    {
        throw std::bad_exception();
    }
    if (bureaucrat.getGrade() > this->reqExecGrade)
    {
        throw Form::GradeTooLowException(false);
    }
    this->executeInternal();
}

void Form::executeInternal() const {} // = empty

Form::GradeTooHighException::GradeTooHighException(bool signOrExec) throw()
    : signOrExec(signOrExec) {}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Form::GradeTooHighException::what() const throw()
{
    if (this->signOrExec)
    {
        return "grade too high to signature form";
    }
    else
    {
        return "grade too high to execute form";
    }
}

Form::GradeTooLowException::GradeTooLowException(bool signOrExec) throw()
    : signOrExec(signOrExec) {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Form::GradeTooLowException::what() const throw()
{
    if (this->signOrExec)
    {
        return "grade too low to signature form";
    }
    else
    {
        return "grade too low to execute form";
    }
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    return os << form.getName() << ", " << (form.isSignatured() ? "signed" : "unsigned") << ", grade for signing " << form.getReqSignGrade() << ", grade for executing " << form.getReqExecGrade() << ".";
}
