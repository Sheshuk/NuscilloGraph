#ifndef MCOMPLEX_H
#define MCOMPLEX_H

#include <QMatrix3x3>
typedef MReal QMatrix3x3;
class MComplex{
public:
  MComplex(MReal &a, MReal &b):A(a),B(b){}
  MComplex(MReal &a):A(a),B(0){}
public:
  MReal A, B;
};

MComplex operator+(MComplex &z1,MComplex &z2){return MComplex(z1.A+z2.A,z1.B+z2.B);}
MComplex operator-(MComplex &z1,MComplex &z2){return MComplex(z1.A-z2.A,z1.B-z2.B);}
MComplex operator*(MComplex &z1,MComplex &z2){return MComplex(z1.A*z2.A-z1.B*z2.B, z1.A*z2.B+z1.B*z2.A);}
MComplex operator*(MComplex &z1,MReal &a2)   {return MComplex(z1.A*a2, z1.B*a2);}
MComplex operator*(MReal &z1,MComplex &a2)   {return MComplex(z1.A*a2, z1.B*a2);}
MComplex operator*(double c,MComplex &z)     {return MComplex(z.A*f, z.B*f);}
MComplex operator!(MComplex &z)              {return MComplex(z.A,-z.B);} //complex conjugate


#endif // MCOMPLEX_H
