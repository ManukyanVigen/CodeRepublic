#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<sstream>
class inter{
    public:
        static std::vector <std::string> variable;
        static std::vector <std::vector<std::string>> cykl_var;
        template <typename T>
        static T& get_nth(std::vector<T>& vec, int n) {
            if (vec.size() < n + 1) {
                vec.resize(n + 1);
            }
            return vec[n];
        }
};
std::vector < std::string > inter::variable;
std::vector < std::vector < std::string >> inter::cykl_var;
std::multimap < std::string, std::string >  mymap;
std::string type_of_value = "";
bool key = true;
bool cykl_key = false;
bool key_in_cykl = true;
bool foo_true_false(std::string lhs, std::string oper, std::string rhs){
    double lhs_new;
    double rhs_new;
    std::stringstream ssj;
    ssj << lhs;
    ssj >> lhs_new;
    std::stringstream ssi;
    ssi << rhs;
    ssi >> rhs_new;
    if(oper == "<") {return (lhs_new < rhs_new);}
    else if (oper == ">") { return (lhs_new > rhs_new);}
    else if (oper == "==") { return (lhs_new == rhs_new);}
    else if (oper == "&&") {return (lhs_new && rhs_new);}
    else if (oper == "!=") {return (lhs_new != rhs_new);}
    else if (oper == "||") {return (lhs_new || rhs_new);}
    else if (oper == "<") {return (lhs_new < rhs_new);}
    else if (oper == "<=") {return (lhs_new <= rhs_new);}
    else if (oper == ">=") {return (lhs_new >= rhs_new);}
    return false;
}
int h = 0;
void bizimdir(std::vector < std::string > &variable){
    if(variable[0]=="}") {key = true;}
    if(((cykl_key) || (variable[0]=="while")) && key_in_cykl){
        for(int i = 0; i < inter::variable.size(); ++i){
            inter::get_nth(inter::cykl_var, h).push_back(variable[i]);
        }
        ++h; 
    }
    if(key){
        for(int i = 0 ; i < variable.size(); ++i){
            if( variable[i] == "=" && variable[3]!="+" && variable[3]!="-" && variable[3]!= "/" && variable[3]!="*" ){
                mymap.insert (std::pair<std::string,std::string>( variable[i-1], variable[i+1]));
            }
            if(variable[i] =="console.log"){
                for(std::multimap<std::string,std::string>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it){
                    if(it->first == variable[i+1]){
                        std::cout << it->second<<std::endl;
                        break;
                    }
                
                } 
            }
            if(variable[i] == "typename"){
                std::string str1;
                for(std::multimap<std::string,std::string>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it){
                    if(it->first == variable[i+1]){
                        str1 = it->second;
                        break;
                    }           
                }
                bool typ = false;
                for(int j = 0; j < str1.size(); ++j){
                    if((int)str1[j] < '0'  || (int)str1[j] > '9'){
                        typ = true;
                    }
                    else{
                        typ = false;
                        break;
                    }
                }
                if(typ){
                    std::cout<<"String"<<std::endl;
                    type_of_value = "String";
                }
                else{
                    std::cout << "Number"<< std::endl;
                    type_of_value = "Number";
                }
            }
            if(variable[i] == "--" ){
                for(std::multimap<std::string,std::string>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it){
                    if(it->first == variable[i-1]){
                        int minusminusint;
                        std::string minusminus = it->second;
                        std::stringstream ssmin;
                        ssmin << minusminus;
                        ssmin >> minusminusint;
                        --minusminusint;
                        std::stringstream ssminus;
                        ssminus << minusminusint;
                        std::string ssminstr = ssminus.str();
                        mymap.insert (std::pair<std::string,std::string>( variable[i-1], ssminstr));
                        break;
                    }
                }
            }
            if(variable[i]=="+" && variable[i-2]=="="){
                if(type_of_value == "Number"){
                    double num1;
                    double num2;
                    std::string plusstr_l = variable[i-1];
                    std::string plusstr_r = variable[i+1];
                    for(std::multimap<std::string,std::string>::reverse_iterator it_p = mymap.rbegin(); it_p != mymap.rend(); ++it_p){
                            if(it_p->first == variable[i-1]){  plusstr_l = it_p -> second; break; }
                    }
                    for(std::multimap<std::string,std::string>::reverse_iterator it_r = mymap.rbegin(); it_r != mymap.rend(); ++it_r){
                        if(it_r -> first == variable[i+1]){ plusstr_r = it_r -> second; break; }
                    }
                    std::stringstream ss;
                    ss << plusstr_l;
                    ss >> num1;
                    std::stringstream ssc;
                    ssc << plusstr_r;
                    ssc >> num2;
                    double num = num1+num2;
                    std::stringstream str1;
                    str1 << num;
                    std::string newstr_num = str1.str();
                    mymap.insert(std::pair<std::string,std::string>( variable[i-3], newstr_num));
                }
                else{
                    std::string  NewSum = variable[i-1] + variable[i+1];
                    mymap.insert(std::pair<std::string,std::string>( variable[i-3], NewSum));
                }
            }
            if(variable[i] == "-" ){
                if(type_of_value == "Number"){
                    double num_m1;
                    double num_m2;
                    std::string minusstr_l = variable[i-1];
                    std::string minusstr_r = variable[i+1];
                    for(std::multimap<std::string,std::string>::reverse_iterator it_p = mymap.rbegin(); it_p != mymap.rend(); ++it_p){
                            if(it_p->first == variable[i-1]){  minusstr_l = it_p -> second; break; }
                    }
                    for(std::multimap<std::string,std::string>::reverse_iterator it_r = mymap.rbegin(); it_r != mymap.rend(); ++it_r){
                        if(it_r -> first == variable[i+1]){ minusstr_r = it_r -> second; break; }
                    }

                    std::stringstream sm;
                    sm << minusstr_l;
                    sm >> num_m1;
                    std::stringstream smt;
                    smt << minusstr_r;
                    smt >> num_m2;
                    double num_m = num_m1 - num_m2;
                    std::stringstream strm;
                    strm << num_m;
                    std::string NewStr_m = strm.str();
                    mymap.insert(std::pair<std::string,std::string>(variable[i-3],NewStr_m));
                }
                else{
                    std::cout << "!No string removal operation can take place " << std::endl;
                }
            }
            if(variable[i]== "/"){
                if(type_of_value == "Number"){
                    double num_m1;
                    double num_m2;
                    std::stringstream sm;
                    sm << variable[i-1];
                    sm >> num_m1;
                    std::stringstream smt;
                    smt << variable[i+1];
                    smt >> num_m2;
                    double num_m = num_m1 / num_m2;
                    std::stringstream strm;
                    strm << num_m;
                    std::string NewStr_m = strm.str();
                    mymap.insert(std::pair<std::string,std::string>(variable[i-3],NewStr_m));
    
                }
                else{
                    std::cout << "!There can be no string splitting operation " << std::endl;
                }
            }
            if(variable[i]=="*"){
                if(type_of_value == "Number"){
                    double num_m1;
                    double num_m2;
                    std::stringstream sm;
                    sm << variable[i-1];
                    sm >> num_m1;
                    std::stringstream smt;
                    smt << variable[i+1];
                    smt >> num_m2;
                    double num_m = (num_m1 * num_m2);
                    std::stringstream strm;
                    strm << num_m;
                    std::string NewStr_m = strm.str();
                    mymap.insert(std::pair<std::string,std::string>(variable[i-3],NewStr_m));
                }
                else{
                    std::cout << "!No string  multiplication operation can take place " << std::endl;
                }
            }
            if(variable[i]=="if"){
                if(variable[i+1]=="(" && variable[inter::variable.size()-1]==")"){
                    std::string lstr;
                    std::string rstr;
                    for(std::multimap<std::string,std::string>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it){
                        if(it->first == variable[i+2]){
                            lstr = it->second;
                            break;
                        }
                    }
                    for(std::multimap<std::string,std::string>::reverse_iterator ite = mymap.rbegin(); ite != mymap.rend(); ++ite){
                        if(ite->first == variable[i+4]){
                            rstr = ite->second;
                            break;
                        }
                    }
                    if(lstr.size() && rstr.size()){
                        if (!foo_true_false(lstr,variable[i+3],rstr)){
                            key = false;

                        }
                        lstr = "";
                        rstr = "";
                    }
                    else if(lstr.size()){
                        if (!foo_true_false(lstr,variable[i+3],variable[i+4])){
                            key = false;

                        }
                        lstr = "";

                    }
                    else if(rstr.size()){
                        if (!foo_true_false(variable[i+2],variable[i+3],rstr)){
                            key = false;

                        }
                        rstr = "";

                    }
                    else if(lstr.size()==0 && lstr.size()==0){
                        if (!foo_true_false(variable[i+2],variable[i+3],variable[i+4])){
                            key = false;

                        }
                    } 
                }
            }

            if(variable[i]=="while"){
                if(variable[i+1]=="(" && variable[variable.size()-1]==")"){
                    std::string lstr;
                    std::string rstr;
                    for(std::multimap<std::string,std::string>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it){
                        if(it->first == variable[2]){
                            lstr = it->second;
                            break;
                        }

                    }
                    for(std::multimap<std::string,std::string>::reverse_iterator ite = mymap.rbegin(); ite != mymap.rend(); ++ite){
                        if(ite->first == variable[4]){
                            rstr = ite->second;
                            break;
                        }
                    }

                    if(lstr.size() && rstr.size()){
                        cykl_key =  (foo_true_false(lstr,variable[3],rstr));

                        lstr = "";
                        rstr = "";
                    }
                    else if(lstr.size()){
                        cykl_key = (foo_true_false(lstr,variable[3],variable[4]));
                        lstr = "";

                    }
                    else if(rstr.size()){
                        cykl_key = (foo_true_false(variable[2],variable[3],rstr));
                        rstr = "";

                    }


                    else if(lstr.size()==0 && lstr.size()==0){
                        cykl_key =  (foo_true_false(variable[2],variable[3],variable[4]));
                    }

                }               
            }

        }
    }
    if(cykl_key && (variable[0]=="}")){
        key_in_cykl = false;
        
      for(int c = 0; c < inter::cykl_var.size(); ++c){
           bizimdir(inter::cykl_var[c]);  
           
      }
    }    
    inter::variable.clear();
}
int main(){
    std::fstream fs;
    fs.open("inter.txt");
    std::string str;
    char symbol;
    while(!fs.eof()){
        fs.get(symbol);
        if(symbol != ' ' && symbol != '\n'){
            str.push_back(symbol);
        }
        else{

            inter::variable.push_back(str);
            str = "";
        }
        if(symbol == '\n'){ 
            bizimdir(inter::variable);
        }
    }
    return 0;
}
