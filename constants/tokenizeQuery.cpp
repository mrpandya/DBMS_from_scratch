using namespace std;

vector<string> tokenizeString(string query, string del = " ")
{
    int start = 0;
    int end = query.find(del);
    vector<string> tokens;
    while (end != -1) {
        tokens.push_back(query.substr(start, end - start));
        start = end + del.size();
        end = query.find(del, start);
    }
    tokens.push_back(query.substr(start, end - start));
    return tokens;
}

string stripParanthesis(string query){
    return query.substr(1,query.length()-2);
}