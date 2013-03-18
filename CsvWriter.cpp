/* 
 * File:   CsvWriter.cpp
 * Author: Eyal Arubas <EyalArubas at gmail>
 */

#include "CsvWriter.h"

CsvWriter::CsvWriter(const string &csvPath): _isFirstEntry(true) {
    _fs.open(csvPath.c_str());
}

CsvWriter::~CsvWriter() {
    _fs.flush();
    _fs.close();
}

void CsvWriter::nextLine() {
    _fs << endl;
    _isFirstEntry = true;
}

void CsvWriter::addEntry(const string &s) {
    _fs << (_isFirstEntry ? "" : ", ") << s;
    _isFirstEntry = false;
}
