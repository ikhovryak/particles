// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "confetti.h"

using namespace std;
using namespace agl;
using namespace glm;

void Confetti::createParticles(int size) 
{
	mTexture = theRenderer.loadTexture("../textures/particle.png");

	for (int i = 0; i < size; i++) {
		Particle p;
		p.pos = random_unit_cube();
		p.size = 0.25f;
		p.vel = random_unit_cube();
		//p.vel = vec3(random_float(-1, 1), random_float(-1, 1), random_float(-1, 1));
		p.color = vec4(random_float(0, 1), random_float(0, 1), random_float(0, 1), 1);
		mParticles.push_back(p); // add to particles
	}
}

void Confetti::update(float dt)
{
	for (int i = 0; i < mParticles.size(); i++) {
		Particle p = mParticles[i];
		if (p.pos.x < -1 || p.pos.x>1)
			p.vel.x = -1 * p.vel.x;
		if (p.pos.y < -1 || p.pos.y>1)
			p.vel.y = -1 * p.vel.y;
		if (p.pos.z < -1 || p.pos.z>1)
			p.vel.z = -1 * p.vel.z;

		p.pos += p.vel * dt; // update particle properties
		mParticles[i] = p;
	}

	//for (int k = 0; k < 30; k++) {
		for (int i = 1; i < mParticles.size(); i++) {

			Particle p2 = mParticles[i];
			Particle p1 = mParticles[i - 1];

			float d2 = length(theRenderer.cameraPosition() - p2.pos);
			float d1 = length(theRenderer.cameraPosition() - p1.pos);

			if (d2 > d1) {
				swap(mParticles[i], mParticles[i-1]);
			}
		}	
}

