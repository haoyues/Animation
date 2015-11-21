#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <algorithm>
#include "particles.h"

const int MaxParticles = 100000;

// Finds a Particle in ParticlesContainer which isn't used yet.
// (i.e. life < 0);
int FindUnusedParticle(Particle *ParticlesContainer, int LastUsedParticle){

	for(int i=LastUsedParticle; i<MaxParticles; i++){
		if (ParticlesContainer[i].life < 0){
			LastUsedParticle = i;
			return i;
		}
	}

	for(int i=0; i<LastUsedParticle; i++){
		if (ParticlesContainer[i].life < 0){
			LastUsedParticle = i;
			return i;
		}
	}

	return 0; // All particles are taken, override the first one
}

void SortParticles(Particle *ParticlesContainer){
	std::sort(&ParticlesContainer[0], &ParticlesContainer[MaxParticles]);
}
