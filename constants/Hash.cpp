int* hashFunction(int value){
    // param value : index to get the hash values
    // return : an array where 1st element is the parent hash and the 2nd element is the child hash
    static int hash[2];
    hash[0] = ceil(value/MAX_LENGTH);
    hash[1] = value%MAX_LENGTH;
    return hash;
}