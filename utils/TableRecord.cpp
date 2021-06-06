using namespace std;

class TableRecord{
    private:
        int _id;
        int _username_length;
        string _username;
        int _email_length;
        string _email;
        int _password_length;
        string _password;
        bool _deleted;

    public:
        void printRecord(){
            cout << _id
                 << " "
                 << _username 
                 << " " 
                 << _username_length 
                 << " " << _password 
                 << " " 
                 << _password_length 
                 << " " 
                 << _email 
                 << " " 
                 << _email_length 
                 << " " 
                 << _deleted 
                 << endl;
        }

        int readInt(ifstream *file){
            char temp_int[sizeof(int)];
            int int_value;
            file->read(
                temp_int, 
                sizeof(int)
            );
            memcpy(
                &int_value, 
                temp_int, 
                sizeof(int)
            );
            return int_value;
        }

        bool readBool(ifstream *file){
            char temp_bool[sizeof(bool)];
            bool bool_value;
            file->read(
                temp_bool, 
                sizeof(bool)
            );
            memcpy(
                &bool_value, 
                temp_bool, 
                sizeof(bool)
            );
            return bool_value;
        }

        string readString(ifstream *file, int len){
            char temp_string[len];
            file->read(
                temp_string, 
                sizeof(temp_string)
            );
            return (string)temp_string;
        }

        void writeInt(ofstream *file, int int_value){
            file->write(
                reinterpret_cast<char*>(&int_value), 
                sizeof(int)
            );
        }

        void writeString(ofstream *file, string string_value){
            file->write(
                &string_value[0], 
                sizeof(string_value)
            );
        }

        void writeBool(ofstream *file, bool bool_value){
            file->write(
                reinterpret_cast<char*>(&bool_value), 
                sizeof(bool)
            );
        }

        TableRecord(){
            this->_id = 0;
            this->_username = "";
            this->_password = "";
            this->_email = "";
            this->_username_length = 0;
            this->_password_length = 0;
            this->_email_length = 0;
            this->_deleted = false;
        }

        TableRecord(int id, string username, string email, string password, bool deleted = false){
            this->_id = id;
            this->_username = username;
            this->_email = email;
            this->_password = password;
            this->_deleted = deleted;
            this->_username_length = username.length();
            this->_password_length = password.length();
            this->_email_length = email.length();
        }

        TableRecord(string filename, int offset){
            ifstream file(filename, ios::binary);
            try{
                if (!file){
                    throw "File not found. Please try again." ;
                }
                file.seekg(offset, ios::beg);
                this->_id = readInt(&file);
                this->_username_length = readInt(&file);
                this->_username = readString(&file, this->_username_length);
                this->_email_length = readInt(&file);
                this->_email = readString(&file, this->_email_length);
                this->_password_length = readInt(&file);
                this->_password = readString(&file, this->_password_length);
                this->_deleted = readBool(&file);

            }catch(string exception){
                cout << exception << endl;
            }
        }

        int getId(){ return this->_id; }

        string getUsername(){ return this->_username; }

        string getPassword(){ return this->_password; }

        string getEmail(){ return this->_email; }

        bool isDeleted(){ return this->_deleted; }

        void setId(int id){ this->_id = id; }

        void setUsername(string username){ 
            this->_username = username;
            this->_username_length = username.length();
        }

        void setPassword(string password){ 
            this->_password = password; 
            this->_password_length = password.length();
        }

        void setEmail(string email){ 
            this->_email = email;
            this->_email_length = email.length();
        }

        void setDelete(bool isDeleted){
            this->_deleted = isDeleted;
        }

        void writeToFile(string filename, int offset = -1){
            ofstream file(filename, ios::binary | ios::app);
            if(offset != -1){
                file.seekp(offset, ios::beg);
            }
            writeInt(&file, this->_id);
            writeInt(&file, this->_username_length);
            writeString(&file, this->_username);
            writeInt(&file, this->_email_length);
            writeString(&file, this->_email);
            writeInt(&file, this->_password_length);
            writeString(&file, this->_password);
            writeBool(&file, this->_deleted);
            file.close();
        }

        int getLength(){
            return 
                  sizeof(this->_id)
                + sizeof(this->_username_length)
                + sizeof(this->_username)
                + sizeof(this->_email_length)
                + sizeof(this->_email)
                + sizeof(this->_password_length)
                + sizeof(this->_password)
                + sizeof(this->_deleted);
        }

};