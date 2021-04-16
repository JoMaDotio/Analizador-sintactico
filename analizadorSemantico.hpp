# include <iostream>
# include <string>
# include <vector>
# include "analizadorLexico.hpp"

using namespace std;

///declaraciones
# define DECLARATIONINT "DataType identifi Equal NumInt PuntCom" //DONE
# define DECLARATIONFLOAT "DataType identifi Equal NumFlot PuntCom" //D
# define DECLARATIONSTRING "DataType identifi Equal Comilla identifi Comilla PuntCom" //D
# define DECLARATIONSTRING2 "DataType identifi Equal Comilla Comilla PuntCom" //D
# define DECLARATIONLIBRARY "Gato include OpRel indentifi OpRel" //D
# define DECLARATIONLIBRARY2 "Gato include Comilla indentifi Comilla" //D
///Expreciones aritmeticas
# define EXPRESSION "NumInt OpArit NumInt" //D
# define EXPRESSION2 "NumFlot OpArit NumFlot" //D
# define EXPRESSION3 "NumFlot OpArit NumInt" //D
# define EXPRESSION4 "NumInt OpArit NumFlot" //D
# define EXPRESSION5 "ParenAbre NumInt OpArit NumInt ParenCerra" //D
# define EXPRESSION6 "ParenAbre NumFlot OpArit NumFlot ParenCerra" //D
# define EXPRESSION7 "ParenAbre NumFlot OpArit NumInt ParenCerra" //D
# define EXPRESSION8 "ParenAbre NumInt OpArit NumFlot ParenCerra" //D
///Expreciones relacionales
# define EXPRESSION9 "NumInt OpRel NumInt" //D
# define EXPRESSION10 "NumFlot OpRel NumFlot" //D
# define EXPRESSION11 "NumFlot OpRel NumInt" //D
# define EXPRESSION12 "NumInt OpRel NumFlot" //D
# define EXPRESSION13 "ParenAbre NumInt OpRel NumInt ParenCerra" //D
# define EXPRESSION14 "ParenAbre NumFlot OpRel NumFlot ParenCerra" //D
# define EXPRESSION15 "ParenAbre NumFlot OpRel NumInt ParenCerra" //D
# define EXPRESSION16 "ParenAbre NumInt OpRel NumFlot ParenCerra"  //D
//condicionales if 
# define CONDITIONAL "if ParenAbre NumInt OpRel NumInt ParenCerra" //D
# define CONDITIONAL2 "if ParenAbre NumInt OpRel NumFlot ParenCerra" //D
# define CONDITIONAL3 "if ParenAbre NumFlot OpRel NumInt ParenCerra" //D
# define CONDITIONAL4 "if ParenAbre NumFlot OpRel NumFlot ParenCerra" //D
# define CONDITIONAL5 "if ParenAbre NumInt OpRel NumInt ParenCerra LlaveAbier LlaveCerra" //D
# define CONDITIONAL6 "if ParenAbre NumInt OpRel NumFlot ParenCerra LlaveAbier LlaveCerra" //D
# define CONDITIONAL7 "if ParenAbre NumFlot OpRel NumInt ParenCerra LlaveAbier LlaveCerra" //D
# define CONDITIONAL8 "if ParenAbre NumFlot OpRel NumFlot ParenCerra LlaveAbier LlaveCerra" //D
//condicionales else
# define CONDITIONAL9 "else LlaveAbier LlaveCerra" //D
//ciclos
# define CICLOFOR "for ParenAbre DataType identifi Equal NumInt PuntCom identifi OpRel NumInt PuntCom identifi OpArit Equal NumInt ParenCerra LlaveAbier LlaveCerra" //D
# define CICLOFOR2 "for ParenAbre DataType identifi Equal NumInt PuntCom identifi OpRel identifi PuntCom identifi OpArit Equal NumInt ParenCerra LlaveAbier LlaveCerra" //D
# define CICLOWHILE "while ParenAbre identifi OpRel NumInt ParenCerra LlaveAbier LlaveCerra" //D
# define CICLOWHILE2 "while ParenAbre identifi OpRel identifi ParenCerra LlaveAbier LlaveCerra" //D
# define CICLOWHILE3 "while ParenAbre NumInt OpRel NumInt ParenCerra LlaveAbier LlaveCerra" //D



void parser(string e, vector<string> &v){
    string temp = "";
    for (int i=0; i < e.length(); i++){
        if (e[i] == ' '){
            v.push_back(temp);
            temp = "";
        }
        else {
            temp.push_back(e[i]);
        }
    }
    v.push_back(temp);
}

void showVector(vector<string> v){
    cout << "[ ";
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << ", ";
    }
    cout << "]" << endl;
}

void stringTokens(string &e, vector<string> v){
    for (int i = 0; i < v.size(); i++){
        if (i == v.size() - 1){
            e += lexico2(v[i]);    
        }
        else{
            e += lexico2(v[i]) + " ";
        }
    }
}

bool semantico(string line){
    vector<string> rules = {DECLARATIONINT, DECLARATIONFLOAT, DECLARATIONSTRING, DECLARATIONSTRING2, DECLARATIONLIBRARY, DECLARATIONLIBRARY2, EXPRESSION, EXPRESSION2, EXPRESSION3, EXPRESSION4, EXPRESSION5, EXPRESSION6, EXPRESSION7, EXPRESSION8, EXPRESSION9, EXPRESSION10, EXPRESSION11, EXPRESSION12, EXPRESSION13, EXPRESSION14, EXPRESSION15, EXPRESSION16, CONDITIONAL, CONDITIONAL2, CONDITIONAL3, CONDITIONAL4, CONDITIONAL5, CONDITIONAL6, CONDITIONAL7, CONDITIONAL8, CONDITIONAL9, CICLOFOR, CICLOFOR2, CICLOWHILE, CICLOWHILE2, CICLOWHILE3};
    bool correct = false;
    string tokensStr = "";
    vector<string> dataParsed;
    parser(line, dataParsed);
    stringTokens(tokensStr, dataParsed);
    cout << tokensStr << endl;
    for (int i = 0; i < rules.size(); i++){
        if (rules[i] == tokensStr){
            correct = true;
            break;
        }
    }
    return correct;
    
}
