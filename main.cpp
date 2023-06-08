/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sai pranav
 *
 * Created on 30 January, 2023, 10:18 PM
 */

#include "Backwards.h"
#include<fstream>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

/*
 * 
 */


backwardChain::backwardChain(){
    ifstream inp;
    string line;
    inp.open("folder/rules.txt");

    int i=10;
    while(!inp.eof()){
        getline(inp,line);
        string stp;
        int j=1;
        for(j=1;j<line.length();j++){
            int ch=(int)line[j];
            if(ch==32 && ((65<=line[j-1] && 97>=line[j-1])|| (97<=line[j-1] && 122>=line[j-1])) &&((65<=line[j+1] && 97>=line[j+1])||(97<=line[j+1] && 122>=line[j+1]))){
                continue;
            }
            else if(((65<=line[j-1] && 97>=line[j-1])||(97<=line[j-1] && 122>=line[j-1])) && ((65<=line[j] && 97>=line[j])||(97<=line[j] && 122>=line[j])) && (((65<=line[j+1] && 97>=line[j+1])||(97<=line[j+1] && 122>=line[j+1]) || (line[j+1]==' ')||(line[j+1]=='=')))){
                continue;
            }
            else if((line[j]=='=')&&((65<=line[j-1] && 97>=line[j-1])||(97<=line[j-1] && 122>=line[j-1])) && (((65<=line[j+1] && 97>=line[j+1])||(97<=line[j+1] && 122>=line[j+1]) || (line[j+1]==' ')||(line[j+1]=='=')))){
                continue;
            }
            else if((((65<=line[j+1] && 97>=line[j+1])|| (97<=line[j+1] && 122>=line[j+1])) && ((65<=line[j] && 97>=line[j])||(97<=line[j] && 122>=line[j]) ) && (((65<=line[j-1] && 97>=line[j+1])||(97<=line[j-1] && 122>=line[j-1]) || (line[j-1]==' ')||(line[j-1]=='=')))))
           {
                continue;
            }
            else
                break;
        }
        stp=line.substr(0,j+1);
        rulebase.insert(pair<int,string>(i,stp));
        i=i+10;
    }
    inp.close();
    
    inp.open("folder/VariableLists.txt");
    while(!inp.eof()){
        getline(inp,line);
        //cout<<line<<"\n";
        string ch="NI"; 
        string stp;
        int j=1;
        for(j=1;j<line.length();j++){
            int ch=(int)line[j];
            if(ch==32 && ((65<=line[j-1] && 97>=line[j-1])|| (97<=line[j-1] && 122>=line[j-1])) &&((65<=line[j+1] && 97>=line[j+1])||(97<=line[j+1] && 122>=line[j+1]))){
                continue;
            }
            else if(((65<=line[j-1] && 97>=line[j-1])||(97<=line[j-1] && 122>=line[j-1])) && ((65<=line[j] && 97>=line[j])||(97<=line[j] && 122>=line[j])) && (((65<=line[j+1] && 97>=line[j+1])||(97<=line[j+1] && 122>=line[j+1]) || (line[j+1]==' ')||(line[j+1]=='=')))){
                continue;
            }
            else if((line[j]=='=')&&((65<=line[j-1] && 97>=line[j-1])||(97<=line[j-1] && 122>=line[j-1])) && (((65<=line[j+1] && 97>=line[j+1])||(97<=line[j+1] && 122>=line[j+1]) || (line[j+1]==' ')||(line[j+1]=='=')))){
                continue;
            }
            else if((((65<=line[j+1] && 97>=line[j+1])|| (97<=line[j+1] && 122>=line[j+1])) && ((65<=line[j] && 97>=line[j])||(97<=line[j] && 122>=line[j]) ) && (((65<=line[j-1] && 97>=line[j+1])||(97<=line[j-1] && 122>=line[j-1]) || (line[j-1]==' ')||(line[j-1]=='=')))))
           {
                continue;
            }
            else
                break;
        }
      
        stp=line.substr(0,j+1);
        varList.insert({stp,ch});
    }
    inp.close();

    /*inp.open("folder/ConclusionList.txt");
    i=10;
    while(!inp.eof()){
        getline(inp,line);
        concList.insert(pair<int,string>(i,line));
        i=i+10;
    }
    inp.close();*/

    inp.open("folder/ClauseVariablelist.txt");
    i=1;
    while(!inp.eof()){
        getline(inp,line);
        string stp;
        int j=1;
        for(j=1;j<line.length();j++){
            int ch=(int)line[j];
            if(ch==32 && ((65<=line[j-1] && 97>=line[j-1])|| (97<=line[j-1] && 122>=line[j-1])) &&((65<=line[j+1] && 97>=line[j+1])||(97<=line[j+1] && 122>=line[j+1]))){
                continue;
            }
            else if(((65<=line[j-1] && 97>=line[j-1])||(97<=line[j-1] && 122>=line[j-1])) && ((65<=line[j] && 97>=line[j])||(97<=line[j] && 122>=line[j])) && (((65<=line[j+1] && 97>=line[j+1])||(97<=line[j+1] && 122>=line[j+1]) || (line[j+1]==' ')||(line[j+1]=='=')))){
                continue;
            }
            else if((line[j]=='=')&&((65<=line[j-1] && 97>=line[j-1])||(97<=line[j-1] && 122>=line[j-1])) && (((65<=line[j+1] && 97>=line[j+1])||(97<=line[j+1] && 122>=line[j+1]) || (line[j+1]==' ')||(line[j+1]=='=')))){
                continue;
            }
            else if((((65<=line[j+1] && 97>=line[j+1])|| (97<=line[j+1] && 122>=line[j+1])) && ((65<=line[j] && 97>=line[j])||(97<=line[j] && 122>=line[j]) ) && (((65<=line[j-1] && 97>=line[j+1])||(97<=line[j-1] && 122>=line[j-1]) || (line[j-1]==' ')||(line[j-1]=='=')))))
           {
                continue;
            }
            else
                break;
        }      
        
        stp=line.substr(0,j+1);
        clausevarList.insert(pair<int,string>(i,stp));
        i++;
    }
    inp.close();

    /*inp.open("folder/clauseVariablesAnswers.text");
    i=1;
    while(!inp.eof()){
        getline(inp,line);
        clauseAnswers.insert(pair<int,string>(i,line));
        i++;
    }
    inp.close();

    inp.open("folder/conclusionAnswers.text");
    i=10;
    while(!inp.eof()){
        getline(inp,line);
        conclusionAnswers.insert(pair<int,string>(i,line));
        i=i+10;
    }
    inp.close();*/
    int k=10;
    for(int i=0;i<41;i++){       
        concList.insert(pair<int,string>(k,"Attack")); k=k+10;
    }
    
    questions.insert(pair<string,string>("UserFeeling","Does user feel that his/her system is attacked?"));
    questions.insert(pair<string,string>("RansomeReq","Did you receive any suspicious email from an unknown email id?"));
    questions.insert(pair<string,string>("DelayedRes","Did it take more than 30 seconds to open any URL?"));
    questions.insert(pair<string,string>("RansomeEmail","Did user get an email with encrypted attachment?"));
    questions.insert(pair<string,string>("NetworkStable","Is your network stable?"));
    questions.insert(pair<string,string>("UnusualMsgs","Did you receive messages unusual to you?"));
    questions.insert(pair<string,string>("FilesDownloaded","Are their any files on system which you have not downloaded?"));
    questions.insert(pair<string,string>("SystemSlow","Did you observe your system becoming slow ?"));
    questions.insert(pair<string,string>("FilesCreated","Did you see any new files being created under your account?"));
    questions.insert(pair<string,string>("CredsNotif","Did you get any notification of using your credentials in your absence?"));
    questions.insert(pair<string,string>("Msgsout","Did you observe messages going out ?"));
    questions.insert(pair<string,string>("UnauthPurchases","Did you find any unauthorized purchases using your credentials?"));
    questions.insert(pair<string,string>("PurchasedAntivirus","Did you purchase antivirus?"));
    questions.insert(pair<string,string>("UsedCreds","Did you use your credentials?"));
    questions.insert(pair<string,string>("URLRedirected","Did you click any URL’s that redirected to unusual pages?"));
    questions.insert(pair<string,string>("InstalledSW","Did you install any software on the system recently?"));
    questions.insert(pair<string,string>("VM","Did you connect to a virtual machine?"));
    questions.insert(pair<string,string>("FilesDeleted","Did you observe your files being deleted?"));
    questions.insert(pair<string,string>("SharedIP","Did you share the IP Address and MAC address to the site ?"));
    questions.insert(pair<string,string>("UploadFiles","Did you upload any files from Virtual Machine?"));
    questions.insert(pair<string,string>("PublicNetworks","Have you recently been connected to any of the public networks?"));
    questions.insert(pair<string,string>("HistoryUpdated","Did your internet history got updated without your involvement?"));
    questions.insert(pair<string,string>("OnlineDB","Did you connect to any online database?"));
    questions.insert(pair<string,string>("EncDataFiles","Does the files contain any programming codes of encrypted data?"));
    questions.insert(pair<string,string>("HistoryUpdated","Did your internet history got updated without your involvement?"));
    questions.insert(pair<string,string>("DelaysInDB","Have you faced any delays in updating the database?"));
    questions.insert(pair<string,string>("UnnauthApps","Have you installed any unauthorized apps?"));
    questions.insert(pair<string,string>("InvasivePopups","Did you get any invasive pop ups?"));
    questions.insert(pair<string,string>("VPN","Did you use any VPN?"));
    questions.insert(pair<string,string>("UnauthWebsites","Have you accessed any unauthorized websites?"));
    questions.insert(pair<string,string>("ClickedURLs","Did you click any URL’s in the website?"));
    questions.insert(pair<string,string>("LandedOnPage","Have you landed on the page that you have desired?"));
    
}

string backwardChain::identifyAttack(){
    int i = 10;
    int count=0;
    string answer = "cc";
    while(i<=400){
        string st="Attack";
        if(concList.at(i)==st){
            ruleNumber.push(i);
            clauseNumber.push((((i/10)-1)*32)+1);  
           // cout<<st<<" ";
            question2(clauseNumber.top(),ruleNumber.top(),clauseNumber.top(),0);   
            answer=rulematch();
            if(varList[clausevarList.at(1)]=="NO"){
                return answer;
            }
            if(answer=="RF"|| answer=="NO "||answer=="NO")
            {i=i+10;ruleNumber.pop();clauseNumber.pop();}
            else
            {return answer;}
         }
    }
      return answer;
}
void backwardChain::question2(int clauseNum,int ruleNum,int i,int hop){
    
    string response;
    if(varList[clausevarList.at(clauseNum)]=="n")
        return;
        if(clauseNum-i==32){
            return;
        }
        else if(ruleNumber.empty()==true){return;}
       
        else{
            if(varList.find(clausevarList.at(clauseNum))!=varList.end()){
                if(varList[clausevarList.at(clauseNum)]=="NI"){
                    cout<<questions[clausevarList.at(clauseNum)]<<"Please enter YES/NO"<<endl;
                    cin>>response;
                    transform(response.begin(),response.end(),response.begin(),::toupper);
                    if(response=="YES" || response=="NO")
                            varList[clausevarList.at(clauseNum)] = response;
                        else{
                            cout << "Wrong input: " << endl;
                            cout << "Please enter only YES or NO" << endl;
                            cout <<questions[clausevarList.at(clauseNum)]<<"(YES/NO): "<<endl;
                            cin >> response;
                            transform(response.begin(),response.end(), response.begin(), ::toupper);
                            varList[clausevarList.at(clauseNum)] = response;
                        }
                }
                //wrong line
                /*else if(hop>0){
                    question2(clauseNum+1,ruleNum,i,hop);
                } */               
            } 
            else if(clausevarList.at(clauseNum)!="n"){
                hop=hop+1;
                map<int,string>::iterator it;
                for(it=concList.begin();it!=concList.end();it++){
                    if(it->second==clausevarList.at(clauseNum)){                        
                        ruleNumber.push(it->first);
                        clauseNumber.push((((it->first/10)-1)*32)+1);
                        break;
                    }
                }
                question2(clauseNumber.top(),ruleNumber.top(),clauseNumber.top(),hop);
                if(clauseNumber.top()==clauseNum){
                string result=rulematch();
                string key=clausevarList.at(clauseNum);
                concList2.insert({key,result});
                clauseNumber.pop();
                ruleNumber.pop();
                return;
                }
                else
                    return;
            }
            question2(clauseNum+1,ruleNum,i,hop);
        }
 
}
string backwardChain::rulematch(){
     string rule=rulebase.at(ruleNumber.top());
     int clauseNum=clauseNumber.top();   //clause number from stack
    for(int i=clauseNum;i<clauseNum+32;i++){     
          bool t=false;
        if(clausevarList.at(i)!="n"){
        findvarinrule(clausevarList.at(i),rule,&indi);
        string ch=rule.substr(indi+clausevarList.at(i).length(),4);      
      
        if(varList.find(clausevarList.at(i))!=varList.end()){
            t=findyesno(varList[clausevarList.at(i)],ch);
        }
        else{
            t=findyesno(concList2[clausevarList.at(i)],ch);
        }}
        if(t==true)
          continue;
        else
           return "RF"; 
        
    }
     findvarinrule(concList.at(ruleNumber.top()),rule,&indi);
    
     string ans=rule.substr(indi+concList.at(ruleNumber.top()).length()+1,rule.length());
     
     return ans;
}

void backwardChain::findvarinrule(string pat,string txt,int *index)
{
    int M = pat.length();//strlen(pat);
    int N = txt.length();//strlen(txt);
   
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i = 0; 
    int j = 0; 
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
            
        }
        if (j == M) {
           // printf("Found pattern at index %d ", i - j);
            *index=(i-j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
bool backwardChain::findyesno(string pat,string txt)
{
    int M = pat.length();//strlen(pat);
    int N = txt.length();//strlen(txt);
    //cout<<M<<" "<<N;
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i = 0; 
    int j = 0; 
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
            
        }
        if (j == M) {
           // printf("Found pattern at index %d ", i - j);// store result
            //cout<<(*index)<<" ";
            return true;
            //*index=(i-j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return false;
}
void backwardChain::computeLPSArray(string pat, int M, int* lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
              if (len != 0) {
                len = lps[len - 1];
           }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main(int argc, char** argv) {
    backwardChain b;
    map<string,string>::iterator it=b.varList.begin();
    cout<<b.identifyAttack();
    return 0;
}

