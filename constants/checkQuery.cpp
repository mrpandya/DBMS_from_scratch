#include <regex>
#include <iostream>

regex _importRegexString{"^((I|i)(M|m)(P|p)(O|o)(R|r)(T|t)\\s\\S+\\.\\S+)$"};
regex _selectRegexString{"^((S|s)(E|e)(L|l)(E|e)(C|c)(T|t)\\s(\\*|((\\S+,)*(\\S+)))\\s(F|f)(R|r)(O|o)(M|m)\\s\\S+(\\s(W|w)(H|h)(E|e)(R|r)(E|e)\\s(\\S+)(\\s(N|n)(O|o)(T|t)){0,1}\\s(=|>=|<=|>|<|!=)\\s.+){0,1})$"};
regex _insertRegexString{"^((I|i)(N|n)(S|s)(E|e)(R|r)(T|t)\\s(I|i)(N|n)(T|t)(O|o)\\s\\S+\\s(V|v)(A|a)(L|l)(U|u)(E|e)(S|s)\\s\\(.+\\))$"};
regex _deleteRegexString{"^((D|d)(E|e)(L|l)(E|e)(T|t)(E|e)\\s(F|f)(R|r)(O|o)(M|m)\\s\\S+(\\s(W|w)(H|h)(E|e)(R|r)(E|e)\\s(\\S+)(\\s(N|n)(O|o)(T|t)){0,1}\\s(=|>=|<=|>|<|!=)\\s.+){0,1})$"};

bool checkImportQuery(string query){
    if (regex_match(query, _importRegexString)) return true;
    return false;
}

bool checkSelectQuery(string query){
    if(regex_match(query, _selectRegexString)) return true;
    return false;
}

bool checkInsertQuery(string query){
    if(regex_match(query, _insertRegexString)) return true;
    return false;
}

bool checkDeleteQuery(string query){
    if(regex_match(query, _deleteRegexString)) return true;
    return false;
}