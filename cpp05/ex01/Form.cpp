#include "Form.hpp"

#define PINK		"\e[38;5;13m"
#define RESET 		"\e[0m"

AForm::AForm() :  name("unnamed"), isSigned(false), signGrade(75), executeGrade(33){}

AForm::AForm(std::string name, unsigned int signGrade, unsigned int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	checkGrade();
}

AForm::AForm(const AForm& other) : name(other.getName()), isSigned(other.getSignStatus()), signGrade(other.getExecuteGrade()), executeGrade(other.getExecuteGrade()) {
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		AForm tmp(other);
		*this = tmp;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Destroying form " << getName() << std::endl;
}

AForm::GradeTooHighException::GradeTooHighException() : std::logic_error(std::string(PINK).append("Grade is too high").append(RESET)) {}

AForm::GradeTooLowException::GradeTooLowException() : std::logic_error(std::string(PINK).append("Grade is too low").append(RESET)) {}

AForm::SignedException::SignedException() : std::logic_error(std::string(PINK).append("The form is already signed").append(RESET)) {}


void AForm::checkGrade() {
	if (signGrade > LOWESTGRADE || executeGrade > LOWESTGRADE)
		throw GradeTooLowException();
	if (signGrade < HIGHESTGRADE || executeGrade < HIGHESTGRADE)
		throw GradeTooHighException();
}

void AForm::beSigned(Bureaucrat b) {
	if(b.getGrade() > signGrade)
		throw GradeTooLowException();
	if(isSigned == true)
		throw SignedException();
	isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &obj) {
	os << "Form: " << obj.getName() << "\nSign Grade:"<< obj.getSignGrade()<< "\nExecute Grade:"<<obj.getExecuteGrade()<<"\nStatus: "<< (obj.getSignStatus() ? "signed" : "unsigned")<<std::endl;
	return (os);
}

std::string AForm::getName() const {
	return (name);
}

bool AForm::getSignStatus() const {
	return (isSigned);
}

int AForm::getSignGrade() const {
	return (signGrade);
}

int AForm::getExecuteGrade() const {
	return (executeGrade);
}
