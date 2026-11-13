#include "Parser.h"
#include "Errors.h"

using namespace std;

Parser::Parser(Reader* reader, LineChecker* lineChecker, int existsString) : m_reader(reader), m_lineChecker(lineChecker), existsString(existsString), cmdName(""), cmdOption(""), cmdArg(""), cmdWhat(""), cmdWith("") {}

Parser::~Parser() {
	delete m_reader;
    delete m_lineChecker;
}

vector <string> Parser::splitPipeLine(const string& line) {
    vector<string> pipeArgs;
    string currentCmd;
    bool insideQuotes = false;

    for (size_t i = 0; i < line.length(); i++) {
        char c = line[i];
        if (c == '"') {
            insideQuotes = !insideQuotes;
            currentCmd += c;
        }
        else if (c == '|' && !insideQuotes) {
            pipeArgs.push_back(currentCmd);
            currentCmd = "";
        }
        else
            currentCmd += c;
    }

    if (currentCmd != "")
        pipeArgs.push_back(currentCmd);

    return pipeArgs;

}

vector <string> Parser::parsePipeLine(string inputLine) {
    m_lineChecker->resetParametres();
    if (existsString == 0)
        m_lineChecker->inputLine = m_reader->readLine();
    else
        m_lineChecker->inputLine = m_reader->readLine(inputLine);
    m_lineChecker->calcCheckerLine();
    if (m_lineChecker->hasInvalidChars) {
        throw ELexicalError(m_lineChecker->inputLine, m_lineChecker->checkerLine);
    }
    vector <string> pipeLineArgs;
    pipeLineArgs = splitPipeLine(m_lineChecker->inputLine);
    return pipeLineArgs;
}


vector<string> Parser::splitLine(const string& line){
    vector<string> args;
    int start = 0, end = 0;
    while (start < line.length()) {
        while (start < line.length() && isspace(line[start])) {
            start++; 
        }
        if (start < line.length()) {
            if (line[start] == '"')
            {
                string w;
                // we need to add " at the start and at the end, \ is escape character 
                w += "\"";
                end = start+1;
                while (end < line.length() && line[end] != '"') {
                    w += line[end];
                    end++;
                }
                if (end!=line.length())
                    w += "\"";
                start = end + 1;
                end++;
                args.push_back(w);

            }
            else {
                end = start;
                if (line[end] == '<' || line[end] == '>')
                    end++;
                if (line[end] == '>')
                    end++;
                // we cant have 3 times > or 2 times <, thats why we need ifs and while
                while (end < line.length() && !isspace(line[end]) && line[end] != '<' && line[end] != '>') {
                    end++;
                }
                args.push_back(line.substr(start, end - start));
                start = end;
            }
        }
    }
    return args;
}

void Parser::getRedirectionArguments(vector<string>& args)
{
    if (args.size() <= 1)
        return;
    bool isThereRedirection = false;
    if (args[args.size() - 1][0] == '<' || args[args.size() - 1][0] == '>') {
        if (args[args.size() - 1][0] == '<') {               // if it starts with <
            if (args[args.size() - 1].length() >= 2) {
                cmdInRed = args[args.size() - 1].substr(1);
                args.pop_back();
                isThereRedirection = true;
            }
        }
        else if (args[args.size() - 1][0] == '>')           // if it starts with >
        {
            if (args[args.size() - 1].length() >= 2)
            {
                if (args[args.size() - 1][1] == '>')        // if it is >>
                {
                    if (args[args.size() - 1].length() >= 3)
                    {
                        cmdOutRedAppend = args[args.size() - 1].substr(2);
                        args.pop_back();
                        isThereRedirection = true;
                    }
                }
                else
                {
                    cmdOutRed = args[args.size() - 1].substr(1);
                    args.pop_back();
                    isThereRedirection = true;
                }
            }
        }
    }
    // but maybe the redireciton sign is separated from redirection argument
    else if (args.size()>=3)
    {
        if (args[args.size() - 2] == "<") {
            cmdInRed = args[args.size() - 1];
            args.pop_back();
            args.pop_back();
            isThereRedirection = true;
        }
        else if (args[args.size() - 2] == ">") {
            cmdOutRed = args[args.size() - 1];
            args.pop_back();
            args.pop_back();
            isThereRedirection = true;
        }
        else if (args[args.size() - 2] == ">>") {
            cmdOutRedAppend = args[args.size() - 1];
            args.pop_back();           
            args.pop_back();
            isThereRedirection = true;
        }
    }

    // if there was redirection, maybe there is one more, else there is no redirection 
    if (isThereRedirection && args.size() >= 2) {       
        if (args[args.size() - 1][0] == '<' || args[args.size() - 1][0] == '>') {
            if (args[args.size() - 1][0] == '<') {               // if it starts with <
                if (args[args.size() - 1].length() >= 2) {
                    if (cmdInRed == "") {
                        cmdInRed = args[args.size() - 1].substr(1);
                        args.pop_back();
                    }
                    else
                        throw EMultipleRedirection();
                }
            }
            else if (args[args.size() - 1][0] == '>')           // if it starts with >
            {
                if (args[args.size() - 1].length() >= 2)
                {
                    if (args[args.size() - 1][1] == '>')        // if it is  >>
                    {
                        if (args[args.size() - 1].length() >= 3)
                        {
                            if (cmdOutRedAppend == "" && cmdOutRed == "") {
                                cmdOutRedAppend = args[args.size() - 1].substr(2);
                                args.pop_back();
                            }
                            else
                                throw EMultipleRedirection();
                        }
                    }
                    else
                    {
                        if (cmdOutRed == "" && cmdOutRedAppend == "") {
                            cmdOutRed = args[args.size() - 1].substr(1);
                            args.pop_back();
                        }
                        else
                            throw EMultipleRedirection();
                    }
                }
            }
        }
        else if (args.size() >= 3)
        {
            if (args[args.size() - 2] == "<") {
                if (cmdInRed == "") {
                    cmdInRed = args[args.size() - 1];
                    args.pop_back();
                    args.pop_back();
                    isThereRedirection = true;
                }
                else
                    throw EMultipleRedirection();
            }
            else if (args[args.size() - 2] == ">") {
                if (cmdOutRed == "" && cmdOutRedAppend == "") {
                    cmdOutRed = args[args.size() - 1];
                    args.pop_back();
                    args.pop_back();
                    isThereRedirection = true;
                }
                else
                    throw EMultipleRedirection();
            }
            else if (args[args.size() - 2] == ">>") {
                if (cmdOutRed == "" && cmdOutRedAppend == "") {
                    cmdOutRedAppend = args[args.size() - 1];
                    args.pop_back();
                    args.pop_back();
                    isThereRedirection = true;
                }
                else
                    throw EMultipleRedirection();
               
            }
        }

    }
}


void Parser::parse(string line)
{
    cmdArg = "";
    cmdName = "";
    cmdWhat = "";
    cmdOption = "";
    cmdWith = "";
    cmdOutRed = "";
    cmdOutRedAppend = "";
    cmdInRed = "";
    vector<string> lineArguments = splitLine(line);
    getRedirectionArguments(lineArguments);
    if (lineArguments.size() >= 1)
        cmdName = lineArguments[0];
    if (cmdName == "date" || cmdName == "time") {
        if (lineArguments.size() > 1)
            throw EWrongArgumentNumber();
    }
    else if (cmdName == "tr") {
        if (lineArguments.size() == 2) {
            cmdWhat = lineArguments[1];
        }
        else if (lineArguments.size() == 3) {
            cmdWhat = lineArguments[1];
            cmdWith = lineArguments[2];
        }
        else if (lineArguments.size() == 4) {
            cmdArg = lineArguments[1];
            cmdWhat = lineArguments[2];
            cmdWith = lineArguments[3];
        }
        else {
            throw EWrongArgumentNumber();
        }
    }
    else if (cmdName == "wc" || cmdName == "head") {
        if (lineArguments.size() == 2) {
            cmdOption = lineArguments[1];
        }
        else if (lineArguments.size() == 3) {
            cmdOption = lineArguments[1];
            cmdArg = lineArguments[2];
        }
        else if (lineArguments.size()>3){
            throw EWrongArgumentNumber();
        }
    }
    else if (cmdName == "echo" || cmdName == "prompt" ||
        cmdName == "touch" || cmdName == "truncate" ||
        cmdName == "rm" || cmdName == "batch") {
        if (lineArguments.size() == 2) {
            cmdArg = lineArguments[1];
        }
        else if (lineArguments.size()>2){
            throw EWrongArgumentNumber();
        }
    }

    else {
        throw EUknownCommand(cmdName);
    }
    
}


