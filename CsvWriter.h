/* 
 * File:   CsvWriter.h
 * Author: Eyal Arubas <EyalArubas at gmail>
 */

#ifndef CSVWRITER_H
#define	CSVWRITER_H

#include <string>
#include <fstream>

using namespace std;

class CsvWriter {
public:
    CsvWriter(const string &csvPath);
    virtual ~CsvWriter();
    void nextLine();
    void addEntry(const string &s);
private:
    ofstream _fs;
    bool _isFirstEntry;
};

#endif	/* CSVWRITER_H */

