# Any copyright is dedicated to the Public Domain.
# https://creativecommons.org/publicdomain/zero/1.0/

TARGET = gov.out
SRCS = main.cpp Bureaucrat.cpp Form.cpp

include ../template.mk

Bureaucrat.cpp: Bureaucrat.hpp
Form.cpp: Form.hpp Bureaucrat.hpp
main.cpp: Bureaucrat.hpp Form.hpp
