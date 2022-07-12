# Any copyright is dedicated to the Public Domain.
# https://creativecommons.org/publicdomain/zero/1.0/

TARGET = gov.out
SRCS = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

include ../template.mk

Bureaucrat.cpp: Bureaucrat.hpp
Form.cpp: Form.hpp Bureaucrat.hpp
ShrubberyCreationForm.cpp: ShrubberyCreationForm.hpp Form.hpp Bureaucrat.hpp
RobotomyRequestForm.cpp: RobotomyRequestForm.hpp Form.hpp Bureaucrat.hpp
PresidentialPardonForm.cpp: PresidentialPardonForm.hpp Form.hpp Bureaucrat.hpp
Intern.cpp: Intern.hpp Form.hpp
main.cpp: Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
