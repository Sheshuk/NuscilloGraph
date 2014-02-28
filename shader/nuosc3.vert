#version 130
in vec4 qt_Vertex;

uniform vec2 Elim=vec2(0,0.1); //energy in GeV
uniform vec2 Llim=vec2(500,5000); //L in KM
uniform mat4 V; //PMNS matrix
uniform int nu_alpha=0; //nu_e,nu_mu,nu_tau

out float L, E;
flat out mat3 w;  //vectors (V_ai*V_bi) as vector in i space.
flat out int alpha;

void Set_Osc(){
    alpha=nu_alpha;
    for(int nu_beta=0; nu_beta<3; nu_beta++)
       for(int i=0;i<3; i++)
        w[nu_beta][i]=(V[nu_alpha][i])*(V[nu_beta][i]);

}

void main(void)
{
    Set_Osc();
    vec2 TexCoord=(qt_Vertex.xy-vec2(-1,-1));
    E=TexCoord.y*(Elim[1]-Elim[0])+Elim[0];
    L=TexCoord.x*(Llim[1]-Llim[0])+Llim[0];
    gl_Position = qt_Vertex;
}
