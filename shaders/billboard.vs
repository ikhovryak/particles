#version 400

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNormal;

uniform vec3 uCameraPos;
uniform float uSize;
uniform vec3 uOffset;
uniform vec4 uColor;
uniform mat4 uVP;

uniform mat4 uMVP;
out vec4 color;


out vec2 uv;

void main()
{

   float distance = sqrt(pow(uCameraPos.x - uOffset.x, 2) + pow(uCameraPos.y - uOffset.y, 2) + pow(uCameraPos.z - uOffset.z, 2));

   vec3 z = vec3((uCameraPos.x - uOffset.x)/distance, (uCameraPos.y - uOffset.y)/distance, (uCameraPos.z - uOffset.z)/distance);
   vec3 y = vec3(0,1,0);
   vec3 x = vec3(z.y*y.z - z.z*y.y, z.z*y.x - z.x*y.z, z.x*y.y - z.y*y.x);
   y = vec3(z.y*x.z - z.z*x.y, z.z*x.x - z.x*x.z, z.x*x.y - z.y*x.x);
   color = uColor;
  
   mat3 rotation = mat3(x,y,z); 

   uv = vPos.xy;
   gl_Position =  uVP * vec4(rotation*uSize*(vPos - vec3(0.5f, 0.5f, 0)), 1.0f); 

}
