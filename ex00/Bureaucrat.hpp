/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
public:
    typedef int grade_t;
    static const grade_t higest_grade = 1;
    static const grade_t lowest_grade = 150;

private:
    const std::string name;
    grade_t grade;

public:
    Bureaucrat(const std::string& name, Bureaucrat::grade_t grade);
    Bureaucrat(const Bureaucrat& that);
    Bureaucrat& operator=(const Bureaucrat& that);
    ~Bureaucrat();
    const std::string& getName() const;
    Bureaucrat::grade_t getGrade() const;
    void promote();
    void demote();

private:
    Bureaucrat(); // = delete

public:
    class GradeTooHighException : public std::exception
    {
    public:
        GradeTooHighException() throw() {}
        virtual ~GradeTooHighException() throw();
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        GradeTooLowException() throw() {}
        virtual ~GradeTooLowException() throw();
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
