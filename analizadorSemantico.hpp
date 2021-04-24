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
# define DECLARATIONLIBRARY "Gato include OpRel identifi OpRel" //D
# define DECLARATIONLIBRARY2 "Gato include Comilla identifi Comilla" //D
///Expreciones aritmeticas
# define EXPRESSION "NumInt OpArit NumInt" //D
# define EXPRESSION2 "NumFlot OpArit NumFlot" //D
# define EXPRESSION3 "NumFlot OpArit NumInt" //D
# define EXPRESSION4 "NumInt OpArit NumFlot" //D
# define EXPRESSION5 "ParenAbre NumInt OpArit NumInt ParenCerra" //D
# define EXPRESSION6 "ParenAbre NumFlot OpArit NumFlot ParenCerra" //D
# define EXPRESSION7 "ParenAbre NumFlot OpArit NumInt ParenCerra" //D
# define EXPRESSION8 "ParenAbre NumInt OpArit NumFlot ParenCerra" //D
# define EXPRESSION9 "NumInt OpArit ParenAbre NumInt OpArit NumInt ParenCerra" //D
# define EXPRESSION10 "NumInt OpArit ParenAbre NumFlot OpArit NumFlot ParenCerra" //D
# define EXPRESSION11 "NumInt OpArit ParenAbre NumFlot OpArit NumInt ParenCerra" //D
# define EXPRESSION12 "NumInt OpArit ParenAbre NumInt OpArit NumFlot ParenCerra" //D
# define EXPRESSION13 "NumFlot OpArit ParenAbre NumInt OpArit NumInt ParenCerra" //D
# define EXPRESSION14 "NumFlot OpArit ParenAbre NumFlot OpArit NumFlot ParenCerra" //D
# define EXPRESSION15 "NumFlot OpArit ParenAbre NumFlot OpArit NumInt ParenCerra" //D
# define EXPRESSION16 "NumFlot OpArit ParenAbre NumInt OpArit NumFlot ParenCerra" //D
# define EXPRESSION17 "ParenAbre NumInt OpArit NumInt ParenCerra OpArit NumInt" //D
# define EXPRESSION18 "ParenAbre NumFlot OpArit NumFlot ParenCerra OpArit NumInt" //D
# define EXPRESSION19 "ParenAbre NumFlot OpArit NumInt ParenCerra OpArit NumInt" //D
# define EXPRESSION20 "ParenAbre NumInt OpArit NumFlot ParenCerra OpArit NumInt" //D
# define EXPRESSION21 "ParenAbre NumInt OpArit NumInt ParenCerra OpArit NumFlot" //D
# define EXPRESSION22 "ParenAbre NumFlot OpArit NumFlot ParenCerra OpArit NumFlot" //D
# define EXPRESSION23 "ParenAbre NumFlot OpArit NumInt ParenCerra OpArit NumFlot" //D
# define EXPRESSION24 "ParenAbre NumInt OpArit NumFlot ParenCerra OpArit NumFlot" //D
///Expreciones relacionales
# define EXPRESSION25 "NumInt OpRel NumInt" //D
# define EXPRESSION26 "NumFlot OpRel NumFlot" //D
# define EXPRESSION27 "NumFlot OpRel NumInt" //D
# define EXPRESSION28 "NumInt OpRel NumFlot" //D
# define EXPRESSION29 "ParenAbre NumInt OpRel NumInt ParenCerra" //D
# define EXPRESSION30 "ParenAbre NumFlot OpRel NumFlot ParenCerra" //D
# define EXPRESSION31 "ParenAbre NumFlot OpRel NumInt ParenCerra" //D
# define EXPRESSION32 "ParenAbre NumInt OpRel NumFlot ParenCerra"  //D
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
    vector<string> rules = {DECLARATIONINT, DECLARATIONFLOAT, DECLARATIONSTRING, DECLARATIONSTRING2, DECLARATIONLIBRARY, DECLARATIONLIBRARY2, EXPRESSION, EXPRESSION2, EXPRESSION3, EXPRESSION4, EXPRESSION5, EXPRESSION6, EXPRESSION7, EXPRESSION8, EXPRESSION9, EXPRESSION10, EXPRESSION11, EXPRESSION12, EXPRESSION13, EXPRESSION14, EXPRESSION15, EXPRESSION16, EXPRESSION17, EXPRESSION18, EXPRESSION19, EXPRESSION20, EXPRESSION21, EXPRESSION22, EXPRESSION23, EXPRESSION24, EXPRESSION25, EXPRESSION26, EXPRESSION27, EXPRESSION28, EXPRESSION29, EXPRESSION30, EXPRESSION31, EXPRESSION32, CONDITIONAL, CONDITIONAL2, CONDITIONAL3, CONDITIONAL4, CONDITIONAL5, CONDITIONAL6, CONDITIONAL7, CONDITIONAL8, CONDITIONAL9, CICLOFOR, CICLOFOR2, CICLOWHILE, CICLOWHILE2, CICLOWHILE3};
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
