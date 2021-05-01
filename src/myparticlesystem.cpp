// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "myparticlesystem.h"

using namespace std;
using namespace agl;
using namespace glm;

void MyParticleSystem::createParticles(int size) 
{
   mTexture = theRenderer.loadTexture("../textures/particle.png");
   // TODO: Create particles

   //for (int i = 0; i < 10; i++) {
	  // Particle p;
	  // p.pos = random_unit_cube(); // set starting values for properties
	  // mParticles.push_back(p); // add to particles
   //}

   Particle p;
   p.pos = vec3(0);
   p.size = 0.25;
   //p.vel = random_unit_cube();
   p.color = vec4(1);
   mParticles.push_back(p); // add to particles
   
}

void MyParticleSystem::update(float dt)
{
	Particle p = mParticles[0];
	p.pos += vec3(1); // update particle properties
	mParticles[0] = p;
}

