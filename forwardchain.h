/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   forwardchain.h
 * Author: sai pranav
 *
 * Created on 5 February, 2023, 5:20 AM
 */

#ifndef FORWARDCHAIN_H
#define FORWARDCHAIN_H
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include <iterator>

using namespace std;

class forwardChain{
public:
    forwardChain();
    int indi;
    map<int,string> rules;
    map<string,string> varList;
    map<int,string> clauseVarLis;
    map<string,string> question;
    queue<string> Conque;
    void questions();
    void PrevOFMA();
    void PrevOFBA();
    void PrevOFIDA();
    void PrevOFDOS(); 
    string edits(string res);
    int search(string ser,int i);
    void computeLPSArray(string pat,int M,int *lps);
    void findvarinrule(string pat,string txt,int *index);
    bool findyesno(string pat,string txt);   
    void prevention(string s,int jump);    
};


#endif /* FORWARDCHAIN_H */

