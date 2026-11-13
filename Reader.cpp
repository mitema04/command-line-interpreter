#include "Reader.h"
#include "Errors.h"

using namespace std;

Reader::Reader() {}

Reader::~Reader() {}

FileReader::FileReader(string filepath) {
	m_file = new ifstream (filepath);
    if (!m_file->is_open())
        throw EFileNotFound();
}

FileReader::~FileReader() {
	m_file->close();
	delete m_file;
}

string FileReader::readLine(string line1) {
	string line;
	getline(*m_file, line);
	return line;
}

bool FileReader::endOfRead(){
	return m_file->eof();
}

ConsoleReader::ConsoleReader() : m_endLine(false) {}

ConsoleReader::~ConsoleReader() {}

string ConsoleReader::readLine(string line1) {
    string line;
    m_endLine = false;
    if (!m_endLine) {
        getline(cin, line); 
        if (line.length() > MAX_LINE_SIZE) {
            line = line.substr(0, MAX_LINE_SIZE);
        }
        m_endLine = true; 
    }
    return line; 
}

bool ConsoleReader::endOfRead()
{
	return m_endLine;
}

LineReader::~LineReader(){}

string LineReader::readLine(string line)
{
    return line;
}

bool LineReader::endOfRead()
{
    return m_endLine;
}
