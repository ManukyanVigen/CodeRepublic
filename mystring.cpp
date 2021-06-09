#include "mystring.h"



int Mystring::get_length() const { //get_length
    return size;
}

Mystring::Mystring() 
    : str{nullptr},
    size{0}
{

}

Mystring::~Mystring(){
    delete[] str;
    str = nullptr;
}
void Mystring::pop_bk(){  //pop_back

    char* buff = new char[size];
    for(int i = 0; i < size - 1; ++i){
        buff[i] = str[i];
    }
    buff[size] = '\0';
    delete[] this->str;
    this->str = buff;
    --size;
    buff = nullptr;
}
void Mystring:: push_bk(char a){  //push_back
    char* buff = new char[size];
    for(int i = 0; i < size - 1; ++i){
        buff[i] = str[i];
    }
    buff[size] = a;
    buff[size+1] = '\0';
    ++size;
    delete[]  this->str;
    this->str = buff;
    buff = nullptr;
}


Mystring& Mystring::operator=(const Mystring& other){ //operator =
    if(this == &other){
        return *this;
    }
    if(this->str != nullptr){

        delete[] str;
    }
    int length = strlen(other.str);
    this->str = new char[length+1];
    for(int i = 0; i < length; ++i){
        this->str[i] =other.str[i];
    }
    this->str[length] = '\0';

    return *this;

}
Mystring& Mystring::operator=(const char* other){ //operator =

    if(this->str !=nullptr){
        delete[] str;
    }
    int length = strlen(other);
    this->str = new char[length];
    for(int i = 0; i < length; ++i){
        this->str[i] = other[i];
    }
    this->str[length] = '\0';
    return *this;

}


Mystring Mystring:: operator+(const Mystring& other){  //operator +
    Mystring newstr;
    int thislength = strlen(this->str);
    int otherlength = strlen(other.str);
    newstr.str = new char[thislength + otherlength + 1];
    int i = 0;
    for(;i < thislength;++i){
        newstr.str[i] = this->str[i];
    }
    for(int j = 0; j < otherlength;++j,++i){
        newstr.str[i] = other.str[j];
    }
    newstr.str[thislength + otherlength] = '\0';
    return newstr;
}
Mystring::Mystring(const Mystring& source){  //copy constructor
    if(this->str != nullptr){
        delete[] str;
    }
    int length = strlen(source.str);
    this->str = new char[length];
    for(int i = 0; i < length; ++i){
        this->str[i] = source.str[i];
    }
    this->str[length] = '\0';


}
void Mystring::swp(Mystring& value){  //swap
    Mystring tmp = value;
    value.str = this->str;
    this->str = tmp.str;
}
char Mystring::begin(){               //begin()

    return this->str[0];
}

Mystring Mystring::erase(int index_begin, int arg_count){ //erase 2arg
    int length = size - arg_count;
    Mystring newStr;
    newStr.str = new char[length];
    int i = 0;
    for(;i <= index_begin;++i){
        newStr[i] = this->str[i]; 
    }
    for(int j = i + arg_count;i < size;++j,++i)
    {
        newStr[i] = this->str[j];

    }
    newStr[length] = '\0';
    size = size - arg_count;
    return newStr;


}
char& Mystring:: operator[](int index){   //operator[]
    return str[index];
}
int Mystring::strlen(const char* instr){
    int i = 0;
    while(instr[i]!='\0'){
        ++i;
    }

    return i;
}
int Mystring::strlen(char* instr){  //strlen
    int i = 0;
    while(instr[i]!='\0'){
        ++i;
    }
    return i;
}






