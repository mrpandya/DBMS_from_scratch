using namespace std;

class TableChildList{

    public:
        TableRecord list[MAX_LENGTH] = { TableRecord() };

};

class TableList{

    private:
        vector<TableChildList> _ParentNode;
        int _index;

    public:

        TableList(){ 
            this->_index = 0;
        }

        int getIndex(){ return this->_index; }

        static int* hashFunction(int value) {
            // param value : index to get the hash values
            // return : an array where 1st element is the parent hash and the 2nd element is the child hash
            static int hash[2];
            hash[0] = ceil(value/MAX_LENGTH);
            hash[1] = value%MAX_LENGTH;
            return hash;
        }

        // void insert(TableRecord record){
        void insert(int id, string username, string email, string password){
            TableRecord record = TableRecord(id, username, email, password);
            cout<<"hello"<<endl;
            int *hash = hashFunction(this->_index++);
            if(hash[0] < this->_ParentNode.size()){
                this->_ParentNode[hash[0]].list[hash[1]] = record;
                return;
            }
            TableChildList child = TableChildList();
            child.list[hash[1]] = record;
            this->_ParentNode.push_back(child);
            return;
        }

};