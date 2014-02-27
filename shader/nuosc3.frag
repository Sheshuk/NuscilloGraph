#version 130
in float E,L;

const vec4 c0=vec4(0,0,0,1);
const vec4 c1=vec4(0,1,0,1);
//input variables
uniform vec3 dm2=vec3(7.59e-5, 2.4e-3, 2.4e-3); //dm21, dm31, dm32, eV^2
//uniform int nu_alpha=0; //nu_e,nu_mu,nu_tau
flat in mat3 w;  //vector (V_ai*V_bi) as vetor in i space.
flat in mat3 mm;  //mass difference matrix
flat in int alpha;

out vec4 FragColor;
vec3 CalcProb(float l, float e){
    vec3 SinF=sin((1.267*dm2*L)/E);
    SinF=SinF*SinF;
    mat3 F=mat3(0.0);
    F[1][0]=SinF[0];
    F[2][0]=SinF[1];
    F[2][1]=SinF[2];

    vec3 Prob=vec3(0.0);

    for(int beta=0;beta<3;++beta)
        for(int j=0;j<3;++j)
            for(int i=0;i<3;++i)
                Prob[beta]+=-4*w[beta][i]*F[i][j]*w[beta][j];

    return Prob;
//    return SinF;
//    return F[alpha];
//    return w[alpha];
}

void main(void)
{
    vec3 prob=CalcProb(L,E);
    float dl=0.5*dFdx(L);
    float de=0.5*dFdy(E);
    //    const int N=1000;
//    for(int n=0;n<N;++n){
//        Prob=Prob+CalcProb(L,E);
//    }
//    Prob=Prob/N;
//    prob=prob+CalcProb(L+dl,E  );
//    prob=prob+CalcProb(L-dl,E  );
//    prob=prob+CalcProb(L   ,E+de);
//    prob=prob+CalcProb(L   ,E-de);
//    prob=prob/5.0;
    prob[alpha]+=1.0;
    FragColor =vec4(prob,1);
}
