#version 130
in vec4 qt_Vertex;
//in vec2 TexCoord;

uniform vec2 Elim=vec2(0,1); //energy in GeV
uniform vec2 Llim=vec2(0,1000); //L in KM

//out vec4 gl_Position;
out float L, E;

void main(void)
{
    vec2 TexCoord=(qt_Vertex.xy-vec2(-1,-1));
    E=TexCoord.y*(Elim[1]-Elim[0])+Elim[0];
    L=TexCoord.x*(Llim[1]-Llim[0])+Llim[0];
    gl_Position = qt_Vertex;
}
