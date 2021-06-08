using namespace std;

class TableList{

    private:
        vector<array<TableRecord*, MAX_LENGTH> > _parentNode;
        int _index;

    public:

        TableList(){ 
            this->_index = 0;
        }

        int getIndex(){ return this->_index; }

        void insertRecord(TableRecord *record){
            int *hash = hashFunction(this->_index++);
            if(hash[0] < this->_parentNode.size()){
                this->_parentNode[hash[0]][hash[1]] = record;
                return;
            }
            array <TableRecord*, MAX_LENGTH>list;
            list[hash[1]] = record;
            this->_parentNode.push_back(list);
            return;
        }

        static int* hashFunction(int value){
            // param value : index to get the hash values
            // return : an array where 1st element is the parent hash and the 2nd element is the child hash
            static int hash[2];
            hash[0] = ceil(value/MAX_LENGTH);
            hash[1] = value%MAX_LENGTH;
            return hash;
        }

};