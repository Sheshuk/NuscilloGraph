#ifndef MATHUTF_H
#define MATHUTF_H

#include <QChar>
#include <QString>

namespace utf{
  QChar Sup(char c);
  QString Sup(char* s);
  QChar Sub(char c);
  QString Sub(char* s);

namespace math{
  enum {
        kTimes = 0x00D7
      };
  }

namespace greek{
  enum {
        kGAMMA = 0x0393,
        kDELTA,
        kTHETA =  0x0398,
        kLAMBDA = 0x039B,
        kXI =     0x039E,
        kSIGMA =  0x03A3,
        kPHI =    0x03A6,
        kPSI =    0x03A8,
        kOMEGA =  0x03A9,
        
        kAlpha =  0x03B1,
        kBeta,
        kGamma,
        kDelta,
        kEpsilon,
        kDzeta,
        kEta,
        kTheta,
        kIota,
        kKappa,
        kLambda,
        kMu,
        kNu,
        kXi,
        kOmicron,
        kPi,
        kRho,
        kSigma = 0x03C3,
        kTau,
        kUpsilon,
        kPhi,
        kChi,
        kPsi,
        kOmega,
        kVarPhi = 0x03D5,


      };
  }

namespace sups{
enum {
      kC0 = 0x2070,
      kC1 = 0x00B9,
      kC2 = 0x00B2,
      kC3 = 0x00B3,
      kC4 = 0x2074,
      kC5 = 0x2075,
      kC6 = 0x2076,
      kC7 = 0x2077,
      kC8 = 0x2078,
      kC9 = 0x2079,
      kI =  0x2071, //i
      kPlus = 0x207A, //+
      kMinus= 0x207B, //-
      kEq  =  0x207C, //=
      kParL=  0x207D, //(
      kParR=  0x207E  //)
    };
}
namespace subs{
enum {
      kC0 = 0x2080,
      kC1 = 0x2081,
      kC2 = 0x2082,
      kC3 = 0x2083,
      kC4 = 0x2084,
      kC5 = 0x2085,
      kC6 = 0x2086,
      kC7 = 0x2087,
      kC8 = 0x2088,
      kC9 = 0x2089,
      kPlus = 0x208A, //+
      kMinus= 0x208B, //-
      kEq  =  0x208C, //=
      kParL=  0x208D, //(
      kParR=  0x208E, //)
      kA = 0x2090, //a
      kU = 0x1D64, //u
      kV = 0x1D65, //v
      kE = 0x2091, //e
      kX = 0x2093, //x
      kH = 0x2095, //h
      kI = 0x1D62, //i
      kJ = 0x2C7C, //j
      kK = 0x2096, //k
      kL = 0x2097, //l
      kM = 0x2098, //m
      kN = 0x2099, //n
      kO = 0x2092, //o
      kP = 0x209A, //p
      kR = 0x1D63, //r
      kS = 0x209B, //s
      kT = 0x209C  //t
    };
  }
}
#endif // MATHUTF_H
