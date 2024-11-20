#ifndef PROJECT4_DOCUPAR_H
#define PROJECT4_DOCUPAR_H

#include "IndexHandler.h"
#include "porter2_stemmer.h"
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"

#include <unordered_set>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <regex>
#include <iostream>

using namespace std;
using namespace rapidjson;
using namespace Porter2Stemmer;

struct ParsedDocument {
    string title;
    string publication;
    string date;
    string text;
};

class DocumentParser {
private:
    IndexHandler* indexHandler;
    unordered_set<string> stopwords;

public:
    DocumentParser();

    void setIndexHandler(IndexHandler* handler);
    void loadStopWords();
    void processDirectory(const string& folderPath);
    void parseJsonFile(const string& jsonFilePath);
    ParsedDocument fetchDocumentData(const string& fileName);
};

#endif // PROJECT4_DOCUPAR_H


//test