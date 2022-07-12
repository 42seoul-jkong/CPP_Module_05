/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class Form
{
private:
    const std::string name;
    bool signatured;
    const Bureaucrat::grade_t reqSignGrade;
    const Bureaucrat::grade_t reqExecGrade;

public:
    Form(const std::string& name, Bureaucrat::grade_t reqSignGrade, Bureaucrat::grade_t reqExecGrade);
    Form(const Form& that);
    Form& operator=(const Form& that);
    virtual ~Form();
    const std::string& getName() const;
    bool isSignatured() const;
    Bureaucrat::grade_t getReqSignGrade() const;
    Bureaucrat::grade_t getReqExecGrade() const;
    void beSigned(const Bureaucrat& bureaucrat);
    void execute(const Bureaucrat& bureaucrat) const;

protected:
    virtual void executeInternal() const;

protected:
    Form(); // = delete

public:
    class GradeTooHighException : public std::exception
    {
    private:
        const bool signOrExec;

    public:
        GradeTooHighException(bool signOrExec) throw();
        virtual ~GradeTooHighException() throw();
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    private:
        const bool signOrExec;

    public:
        GradeTooLowException(bool signOrExec) throw();
        virtual ~GradeTooLowException() throw();
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& form);
