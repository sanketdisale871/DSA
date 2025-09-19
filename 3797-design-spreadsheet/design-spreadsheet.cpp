class Spreadsheet {
    /*
    Spreadsheet has 26 columns, 'A' to 'Z'.

    ==> All cells are intially set to 0.

    */
private:
bool isNumber(const string &s) {
    if(s.empty()) return false;
    for(char c : s) {
        if(!isdigit(c) && c != '-') return false; 
    }
    return true;
}

public:
unordered_map<string,int>cellVal;
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        cellVal[cell]=value;
    }
    
    // resetCell -> Reset the cell to 0
    void resetCell(string cell) {
         cellVal[cell]=0;
    }
    // return the computed sum
    int getValue(string formula) {
        
        string x="";
        string y="";
        bool isPlus = false;

        for(int i=1;i<formula.size();i++){
            if(formula[i]=='+'){
                isPlus = true;
                continue;
            }

            if(!isPlus){
                x.push_back(formula[i]);
            }
            else{
                y.push_back(formula[i]);
            }
                    }
            int res = 0;

            if(cellVal.find(x) != cellVal.end()) {
                res += cellVal[x];
            } else if(isNumber(x)) {
                res += stoi(x);
            } else {
                cout << "Invalid input for x: " << x << endl;
            }

            if(cellVal.find(y) != cellVal.end()) {
                res += cellVal[y];
            } else if(isNumber(y)) {
                res += stoi(y);
            } else {
                cout << "Invalid input for y: " << y << endl;
            }
            return res;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */