#include "Printer.h"
#include "Simulator.h"

Printer::~Printer()
{
	delete m_parser;
}

void Printer::print(string txt)
{
	text = txt;

	// explanation for this 'if' is in the end of this file
	if (m_parser->cmdOutRed == "" && m_parser->cmdOutRedAppend == "") {
		if (!Simulator::Instance()->m_printer->inOutputRedirection && text != "" && !inOutputRedirection && m_parser->cmdName != "batch")
			printStdOutput();
	}
	else if (m_parser->cmdOutRedAppend == "") {
		printInFile();
	}
	else if (m_parser->cmdOutRed == "") {
		appendInFile();
	}
}

void Printer::printStdOutput()
{
	cout << text << endl;
}

void Printer::printInFile()
{
	ofstream outFile(m_parser->cmdOutRed, ios::trunc);
	if (outFile.is_open()) {
		if (text != "") {
			outFile << text;
		}
		outFile.close();
	}
}

void Printer::appendInFile()
{
	ofstream outFile(m_parser->cmdOutRedAppend, ios::app); 
	if (outFile.is_open()) {
		if (text != "") {
			outFile << text;
		}
		outFile.close();
	}
}

/*

postoji komplikacija sa batch komandom
batch komanda poziva simulator, batch komanda ima sama za sebe svoj poseban printer i parser za svaku liniju
ali ako dodje do redirekcije u izlaznom toku batch komande,
mora se posmatrati zapravo simulatorova izlazna redirekcija, koja u tom trenutku, prilikom batcha, nije ista kao ona redirekcija
koju ima trenutni printer, zato sto je to printer od batch komande, a ne od simulatora

*/