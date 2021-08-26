#include <iostream>
#include<fstream>



bool valid_char(char ch){

    return(ch >= 'a' && ch <= 'z') || (ch >='A' && ch <= 'Z');

}

int Show_Menu(){

    std::cout << "1 : Encrypt" << std::endl; // codavorel
    std::cout << "2 : Decrypt" << std::endl; // apakodavorel

    int option;
    std::cin >> option;
    return option;

}
void encrypt(char* inputfile,char* outputfile,int key){
    std::ifstream input;
    std::ofstream output;

    input.open(inputfile,std::ios::in);
    output.open(outputfile,std::ios::out);
    key%=26;

    char ch;
    while(input.get(ch)){

        if(ch == ' '){ 
            output << ' ';
        }
        if(valid_char(ch)){
            ch = std::tolower(ch); // A -> a
            char result = 'a' + (ch - 'a' + key)%26;
            output << result;

        }
    }
    input.close();
    output.close();
}
void decrypt(char* inputfile, char* outputfile,int key){

    std::ifstream input;
    std::ofstream output;
    input.open(inputfile,std::ios::in);
    output.open(outputfile,std::ios::out);
    key%=26;
    char ch;
    while(input.get(ch)){
        if(ch == ' '){
            output << ' ';
        }
        if(valid_char(ch)){
            ch = std::tolower(ch);
            char result = 'a' + (ch - 'a' - key + 26*2)%26;
            output << result;

        }



    }//while

    input.close();
    output.close();

}// decrypt


int main(){

    while(1){
        int choice = Show_Menu();
        switch(choice){
            case 1:
                char source[50];
                char destinition[50];
                int key;
                std::cout << " Source File : ";
                std::cin >> source;
                std::cout << " Destinition File : ";
                std::cin >> destinition;
                std::cout << " Key : ";
                std::cin >> key;

                encrypt(source,destinition,key);

                break;
            case 2:

                std::cout << " Source File : ";
                std::cin >> source;
                std::cout << " Destinition File : ";
                std::cin >> destinition;
                std::cout << " Key : ";
                std::cin >> key;
                decrypt(source,destinition,key);

                break;

        }//switch

    }//while


}
