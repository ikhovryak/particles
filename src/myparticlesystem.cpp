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
   mTexture = theRenderer.loadTexture("../textures/ParticleFirecloud.png");
   
   for (int i = 0; i < size; i++) {
	   Particle p;
	   p.pos = vec3(0 + random_float(0, 0.8f),0+random_float(0, 0.8f), random_float(0, 0.8f));
	   p.size = 0.0f;
	   p.vel = vec3(0);
	   p.color = vec4(0.8f + abs(random_float(0, 0.2f)), 0.25f + abs(random_float(0, 0.2f)), 0.1f, 1);;
	   mParticles.push_back(p); // add to particles
   }

}

void MyParticleSystem::start_smoke() {

	mTexture = theRenderer.loadTexture("../textures/ParticleCloudWhite.png");
	for (int i = 0; i < 15; i++) {
		Particle p;
		p.pos = vec3(0 + random_float(0, 0.5f), 0 + random_float(0, 0.5f), random_float(0, 0.5f));
		p.size = 0.7f;
		p.vel = vec3(0);
		p.color = vec4(0.5, 0.5, 0.5, 1 - abs(random_float(0,0.5f)));
		mParticles.push_back(p); // add to particles
	}
}

void MyParticleSystem::update(float dt)
{
	for (int i = 0; i < mParticles.size(); i++) {
		Particle p = mParticles[i];
		if (startSmoke) {
			mTexture = theRenderer.loadTexture("../textures/ParticleCloudWhite.png");

			//cout << "start smoke"<<endl;
			p.size -= 0.5 * dt; // update particle properties
			p.pos += vec3(0.2, 0.2, 0) * dt;

			p.color = vec4(0.47f, 0.47f, 0.47f, p.color[3] - 0.01f);
		}
		else{
			p.size += 0.8 * dt; // update particle properties
			p.pos -= vec3(0.5, 0.5, 0) * dt;
		}
		
		mParticles[i] = p;
	}

	//for (int k = 0; k < 30; k++) {
	for (int i = 1; i < mParticles.size(); i++) {

		Particle p2 = mParticles[i];
		Particle p1 = mParticles[i - 1];

		float d2 = length(theRenderer.cameraPosition() - p2.pos);
		float d1 = length(theRenderer.cameraPosition() - p1.pos);

		if (d2 > d1) {
			swap(mParticles[i], mParticles[i - 1]);
		}
	}
}

