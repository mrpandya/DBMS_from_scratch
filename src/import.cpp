#include "../utils/IndexList.cpp"
#include "../utils/TableRecord.cpp"
#include "../utils/TableList.cpp"
#include "../constants/checkQuery.cpp"
#include "../constants/tokenizeQuery.cpp"

void handleImportQuery(string query){
    vector<string> queryTokens;
    string data;
    fstream file;
    query = checkSemiColon(query);
    if (!checkImportQuery(query)){
        cout << "Something wrong with your query. Please check the syntax and try again." << endl;
        return;
    }
    queryTokens = tokenizeString(query);
    for(int i = 0; i < queryTokens.size(); i++){
        cout << queryTokens[i] << endl;
    }
    // TODO : make tablerecord
    if(queryTokens.size()==1){
        cout << "Incomplete command. Try again." << endl;
        return;
    }
    if(queryTokens[1].find(".csv", 0) == string::npos){
        cout << "Please enter a .csv file." << endl;
        return;
    }
    file.open(queryTokens[1], ios::in);
    if(!file){
        cout << "File not found. Try again." << endl;
        return;
    }
    // extra call for the column names in the csv file
    getline(file, data);

    string filename = (queryTokens[1].substr(0, queryTokens[1].length() - 3)).append("db");
    int offset = 0;

    TableList table = TableList();
    IndexList id = IndexList(INT);
    IndexList username = IndexList(STRING);
    IndexList email = IndexList(STRING);
    IndexList password = IndexList(STRING);

    if(file.eof()){
        cout << "File is empty. Please import a file with data." << endl;
        return;
    }
    getline(file, data);
    while(!file.eof()){
        vector<string> row = tokenizeString(data,",");
        TableRecord record = TableRecord(stoi(row[0]), row[1], row[2], row[3]);
        cout<<stoi(row[0])<<" "<<row[1]<<" "<<row[2]<<" "<<row[3]<<endl;
        record.writeToFile(filename);

        table.insert(stoi(row[0]), row[1], row[2], row[3]);
        // table.insert(record);
        id.insert(row[0],offset);
        username.insert(row[1],offset);
        email.insert(row[2],offset);
        password.insert(row[3],offset);

        offset += record.getLength();
        getline(file, data);

    }
    id.writeToFile("../temp/id.ndx");
    username.writeToFile("../temp/username.ndx");
    email.writeToFile("../temp/email.ndx");
    password.writeToFile("../temp/password.ndx");
    file.close();

    cout << "Import Success !!!" << endl;
}