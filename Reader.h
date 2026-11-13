#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Reader {
public:

	Reader();

	virtual ~Reader();

	virtual string readLine(string line="") = 0;

	virtual bool endOfRead() = 0;

};

class FileReader : public Reader {  
public:

	FileReader(string filepath);

	~FileReader();

	virtual string readLine(string line="");

	virtual bool endOfRead();

private:

	ifstream* m_file;
};


class ConsoleReader : public Reader {
public:

	ConsoleReader();

	~ConsoleReader();

	virtual string readLine(string line="");

	virtual bool endOfRead();

private:

	bool m_endLine;
	static const int MAX_LINE_SIZE = 512;
};


// this class was needed to return a string that already exists as a reader, so we can call it from parser

class LineReader : public Reader {
public:

	LineReader() : m_endLine(true) {};

	~LineReader();

	string readLine(string line="");

	virtual bool endOfRead();

private:

	bool m_endLine;
	static const int MAX_LINE_SIZE = 512;
};

#endif
