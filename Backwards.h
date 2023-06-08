/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Backwards.h
 * Author: sai pranav
 *
 * Created on 30 January, 2023, 10:37 PM
 */

#ifndef BACKWARDS_H
#define BACKWARDS_H
#include<iostream>
#include<stack>
#include<map>
#include<string>
#include<iterator>

using namespace std;

class backwardChain{
    
public:
    int indi;
    map<int,string> rulebase;
    map<string,string> varList;
    map<int,string> concList;
    map<int,string> clausevarList;
    map<int,string> clauseAnswers;
    map<int,string> conclusionAnswers;
    
    map<string,string> questions;
    map<int,int> conclusion1;
    map<string,string> conclusion2;
  
    map<string,string> concList2;
    
    stack<int> ruleNumber;
    stack<int> clauseNumber;

    backwardChain();
    string identifyAttack();
   void computeLPSArray(string pat,int M,int *lps);
    void findvarinrule(string pat,string txt,int *index);
    bool findyesno(string pat,string txt);
    void question2(int clauseNum,int ruleNum,int i,int hop);
    
    string rulematch();

};


#endif /* BACKWARDS_H */

