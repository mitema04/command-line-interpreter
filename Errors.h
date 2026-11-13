#ifndef ERRORS_H
#define ERRORS_H
#include <exception>
using namespace std;

class EFileNotFound : public exception
{
public:
	EFileNotFound() : exception("Error: File not found") {}
};

class EFileAlreadyExists : public exception
{
public:
	EFileAlreadyExists() : exception("Error: File already exists") {}
};

class EUknownCommand : public exception {
	string message;
public:
	EUknownCommand(const string& cmdName) : message("Error: Unknown command: " + cmdName) {}
	const char* what() const noexcept override {
		return message.c_str();
	}
};

class EWrongArgumentNumber : public exception
{
public:
	EWrongArgumentNumber() : exception("Error: Wrong number of arguments") {}
};

class ERedirectionImpossible : public exception
{
public:
	ERedirectionImpossible() : exception("Error: Redirection impossible") {}
};

class EUknownOption : public exception
{
public:
	EUknownOption() : exception("Error: Uknown option") {}
};

class EExistsWrongValue : public exception
{
public:
	EExistsWrongValue() : exception("Error: Wrong value") {}
};

class EWrongArgType : public exception
{
public:
	EWrongArgType() : exception("Error: Wrong argument type") {}
};

class EPipeArgError : public exception
{
public:
	EPipeArgError() : exception("Error: Error in pipe arguments") {}
};

class EMultipleRedirection : public exception
{
public:
	EMultipleRedirection() : exception("Error: Multiple redirection arguments") {}
};

class ELexicalError : public exception {
	string message;
public:
	ELexicalError(const string& inputLine, const string& checkerLine) : message("Error - unexpected characters:\n" + inputLine + "\n" + checkerLine) {}
	const char* what() const noexcept override {
		return message.c_str();
	}
};

#endif