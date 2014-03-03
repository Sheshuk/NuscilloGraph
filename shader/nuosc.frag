#version 130
varying float E,L;

const vec4 c0=vec4(0,0,0,1);
const vec4 c1=vec4(0,1,0,1);
//input variables
uniform vec3 dm2=vec3(7.59e-5, 2.4e-3, 2.4e-3); //dm21, dm32, dm32, eV^2
uniform float Sin2Th=1;  //mixing angle

vec3 CalcProb(float l, float e){
    float phase=(1.267*dm2*L)/(4*E);
    float osc=sin(phase);
    float prob1=Sin2Th*osc*osc;
    return vec3(prob1,0,1.-prob1);
}

void main(void)
{
    vec3 Prob=CalcProb(L,E);

    float dl=0.1;
    float de=0.1;
    //    const int N=1000;
//    for(int n=0;n<N;++n){
//        Prob=Prob+CalcProb(L,E);
//    }
//    Prob=Prob/N;
    // Prob=Prob+CalcProb(L+dl,E  );
    // Prob=Prob+CalcProb(L-dl,E  );
    // Prob=Prob+CalcProb(L   ,E+de);
    // Prob=Prob+CalcProb(L   ,E-de);
    // Prob=Prob/4.0;
    gl_FragColor = vec4(Prob.x,Prob.y,Prob.z,1);
}
