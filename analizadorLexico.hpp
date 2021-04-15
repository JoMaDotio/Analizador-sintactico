# include <iostream>
# include <string>
# include <regex>

using namespace std;


bool integerNumber(string e){
    std::regex intRegex("[0-9]+");
    return std::regex_match(e, intRegex);
}

bool floatNumber(string e){
    std::regex floatRegex("([0-9]+([.][0-9]*)?|[.][0-9]+)$");
    return std::regex_match(e, floatRegex);
}


bool realtionalOperator(string e){
    std::regex rellRegex("<|<=|>|>=|==|!=");
    return std::regex_match(e, rellRegex); 
}

bool arithmeticOperator(string e){
    std::regex aritRegex("\\+|\\-|\\*|\\/");
    return std::regex_match(e, aritRegex);
}


bool reservedWord(string e){
    std::regex reservedRegex("int|float|while|for|if|bool|class|else|switch|char|string|include|struct");
    return std::regex_match(e, reservedRegex);
}

bool simbols(string e){
    std::regex simRegex("\\{|\\}|\\;|\\#|\\(|\\)|\\\"\\\"|\\\"|=");
    return std::regex_match(e, simRegex);
}

bool variableName (string e){
    std::regex varRegex("[A-Za-z][\\w$]*(\\.[\\w$]+)?(\\[\\d+])?");
    return std::regex_match(e, varRegex);
}


void lexico(){
    string myStr;
    cout << "Ingrese la cadena a evaluar: ";
    getline(cin, myStr);
    if (integerNumber(myStr)){
        cout << "Numero entero: " << myStr << endl;
    }
    else if (floatNumber(myStr)){
        cout << "Numero real: " << myStr << endl;
    }
    else if (realtionalOperator(myStr)){
        cout << "Operador relacional: " << myStr << endl;
    }
    else if (arithmeticOperator(myStr)){
        cout << "Operador aritmetico: " << myStr << endl;
    }
    else if (reservedWord(myStr)){
        cout << "Palabra reservada: " << myStr << endl;
    }
    else if (simbols(myStr)){
        cout << "Simbolo de programa: " << myStr << endl;
    }
    else{
        cout << "Token no reconocido, favor de verificar la cadena: " << myStr << endl;
    }
}

string lexico2(string token){
    string temp;
    if (integerNumber(token)){
        temp = "NumInt";
    }
    else if (floatNumber(token)){
        temp = "NumFlot";
    }
    else if (realtionalOperator(token)){
        temp = "OpRel";
    }
    else if (arithmeticOperator(token)){
        temp = "OpArit";
    }
    else if (reservedWord(token)){
        if (token == "int" || token == "float" || token == "string" || token == "bool" || token == "struct" || token == "class" || token == "char"){
            temp = "DataType";
        }
        else if (token == "include"){
            temp = token;
        }
        else if (token == "while"){
            temp = token;
        }
        else if (token == "for"){
            temp = token;
        }
        else if (token == "if"){
            temp = token;
        }
        else if (token == "else"){
            temp = token;
        }
    }
    else if (simbols(token)){
        if (token == "{"){
            temp = "LlaveAbier";
        }
        else if (token == "}"){
            temp = "LlaveCerra";
        }
        else if (token == "("){
            temp = "ParenAbre";
        }
        else if (token == ")"){
            temp = "ParenCerra";
        }
        else if (token == "#"){
            temp = "Gato";
        }
        else if (token == ";"){
            temp = "PuntCom";
        }
        else if (token == "\"\""){
            temp = "DobleComilla";
        }
        else if (token == "\""){
            temp = "Comilla";
        }
        else if (token == "="){
            temp = "Equal";
        }
    }
    else if (variableName(token)){
        temp = "identifi";
    }
    else {
        temp = "INVALID";
    }
    if (temp == ""){
        temp == "NOTYPE";
    }
    return temp;
}