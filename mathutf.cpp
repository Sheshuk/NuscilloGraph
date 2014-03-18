#include "mathutf.h"

QChar utf::Sup(char c){
  switch(c){
      case '0': return sups::kC0;
      case '1': return sups::kC1;
      case '2': return sups::kC2;
      case '3': return sups::kC3;
      case '4': return sups::kC4;
      case '5': return sups::kC5;
      case '6': return sups::kC6;
      case '7': return sups::kC7;
      case '8': return sups::kC8;
      case '9': return sups::kC9;
      case 'i': return sups::kI;
      case '+': return sups::kPlus;
      case '-': return sups::kMinus;
      case '=': return sups::kEq;
      case '(': return sups::kParL;
      case ')': return sups::kParR;
    default: return '?';
    }
}

QChar utf::Sub(char c){
  switch(c){
      case '0': return subs::kC0;
      case '1': return subs::kC1;
      case '2': return subs::kC2;
      case '3': return subs::kC3;
      case '4': return subs::kC4;
      case '5': return subs::kC5;
      case '6': return subs::kC6;
      case '7': return subs::kC7;
      case '8': return subs::kC8;
      case '9': return subs::kC9;
      case '+': return subs::kPlus;
      case '-': return subs::kMinus;
      case '=': return subs::kEq;
      case '(': return subs::kParL;
      case ')': return subs::kParR;
      case 'a': return subs::kA;
      case 'u': return subs::kU;
      case 'v': return subs::kV;
      case 'e': return subs::kE;
      case 'x': return subs::kX;
      case 'h': return subs::kH;
      case 'i': return subs::kI;
      case 'j': return subs::kJ;
      case 'k': return subs::kK;
      case 'l': return subs::kL;
      case 'm': return subs::kM;
      case 'n': return subs::kN;
      case 'o': return subs::kO;
      case 'p': return subs::kP;
      case 'r': return subs::kR;
      case 's': return subs::kS;
      case 't': return subs::kT;
    default: return '?';
    }
}

QString utf::Sup(char* s){
  QString res="";
  for(unsigned n=0;n<strlen(s);++n){
    res+=Sup(s[n]);
  }
  return res;
}

QString utf::Sub(char* s){
  QString res="";
  for(unsigned n=0;n<strlen(s);++n){
    res+=Sub(s[n]);
  }
  return res;
}
