#pragma once
class IPrinter
{
public:
	virtual void print(Season) = 0;
	IPrinter(){}
};
class ConsolePrinter: public IPrinter
{
public:
	ConsolePrinter() {}
	void print(Season);

};
class FilePrinter : public IPrinter
{
	std::string name;
public:
	FilePrinter(std::string);
	void print(Season);
};
