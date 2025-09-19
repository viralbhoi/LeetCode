class Spreadsheet {
    map<string,int> mp;
public:
    Spreadsheet(int rows) {
    }
    
    void setCell(string cell, int value) {
        mp[cell] = value;
    }
    
    void resetCell(string cell) {
        mp[cell] = 0;
    }
    
    int getValue(string formula) {
        int plus = 0;
        string s1 = "";
        string s2 = "";

        for(int i=1;i<formula.size();i++){
            if(formula[i] != '+'){
                s1 += formula[i];
            }else{
                plus = i;
                break;
            }
        }

        for(int i= plus + 1; i<formula.size();i++){
            s2 += formula[i];
        }

        int ss1 = 0,ss2=0;
        if(s1[0] >='0' && s1[0] <='9'){
            ss1 = stoi(s1);
        }else{
            ss1 = mp[s1];
        }

        if(s2[0] >='0' && s2[0] <='9'){
            ss2 = stoi(s2);
        }else{
            ss2 = mp[s2];
        }

        return ss1 + ss2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */