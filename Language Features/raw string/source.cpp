#include <cstring>
#include <iomanip>
#include <iostream>
 
using namespace std;

string vertx_shader = R"(
		#version 330 core
		layout (location = 0) in vec3 vVertex;
		layout (location = 1) in vec2 vTexCrd;
		uniform mat4 transform;
		out vec2 FragTexCrd; 
		void main()
		{
			gl_Position = transform * vec4(vVertex, 1.0);
			FragTexCrd=vTexCrd;
		};
		)";

string frag_shader_func = R"func(
    string fragmentShaderSource()
	{
		return R"(
		#version 330 core
		in vec2 FragTexCrd;
		out vec4 FragColor;
		uniform sampler2D tex;
		void main()
		{
			vec4 texColor = texture(tex, FragTexCrd);
			if(texColor.a < 0.1)
				discard;
			FragColor = texColor;
		};
		)";
	}
)func";
int main()
{
    cout << "Without delimiter" << endl << endl;
    cout << vertx_shader << endl;
    cout << endl;
    cout << "With delimiter" << endl << endl;
    cout << frag_shader_func << endl;
    
}