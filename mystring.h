class Mystring{
    char* str;
    int size;
public:
    Mystring();                 // constructor no arguments
    void pop_bk();              // pop_back
    void push_bk(char a);       // push_back
    void swp(Mystring& value);  // swap
    int get_length() const;     // str - length
    ~Mystring();                // desctructor
    Mystring(const Mystring& source); //copy constructor
    Mystring(Mystring&& source);      //move constructor
    Mystring& operator=(const Mystring& other); //operator=
    Mystring& operator=(const char* other);     //operator =
    Mystring operator+(const Mystring& other);  //operator+
    char& operator[](int index);            //operator []
    char begin();                               //begin()
    Mystring erase(int index_begin,int arg_count );//erase 2 argument
    Mystring erase(int erase_arg );              // erase 1 argument
    int strlen(char* instr);
    int strlen(const char* instr);
};
