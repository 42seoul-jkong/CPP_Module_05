/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

#define ASCII_ART_TREE                        \
    "                     .o00o\n"            \
    "                   o000000oo\n"          \
    "                  00000000000o\n"        \
    "                 00000000000000\n"       \
    "              oooooo  00000000  o88o\n"  \
    "           ooOOOOOOOoo  ```''  888888\n" \
    "         OOOOOOOOOOOO'.qQQQQq. `8888'\n" \
    "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n"  \
    "        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n"    \
    "         OOOOOOOOO QQQQQQQQQQ/ /QQ\n"    \
    "           OOOOOOOOO `QQQQQQ/ /QQ'\n"    \
    "             OO:F_P:O `QQQ/  /Q'\n"      \
    "                \\\\. \\ |  // |\n"      \
    "                d\\ \\\\\\|_////\n"      \
    "                qP| \\ _' `|Ob\n"        \
    "                   \\  / \\  \\Op\n"     \
    "                   |  | O| |\n"          \
    "           _       /\\. \\_/ /\\\n"      \
    "            `---__/|_\\\\   //|  __\n"   \
    "                  `-'  `-'`-'-'\n"

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form(), target() {} // = delete

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : Form("Shrubbery Creation", 145, 137), target(target)
{
#ifdef VERBOSE
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
#endif
    // No-OP
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& that)
    : Form(that), target(that.target)
{
#ifdef VERBOSE
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
#endif
    // No-OP
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& that)
{
#ifdef VERBOSE
    std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
#endif
    if (this != &that)
    {
        this->ShrubberyCreationForm::operator=(that);
        const_cast<std::string&>(this->target) = that.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
#ifdef VERBOSE
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
#endif
    // No-OP
}

void ShrubberyCreationForm::executeInternal() const
{
    std::cout << " * A tree has been planted on " << this->target << ". * " << std::endl;
    std::string fn = this->target + "_shrubbery";
    std::ofstream ofs(fn.c_str(), std::ios::out | std::ios::app);
    ofs << ASCII_ART_TREE << std::endl;
}
