#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "Common.h"
#include "Particle.h"
#include "Parameters.h"

class ParticleSystem {
public:
	ParticleSystem(std::vector<Particle>& particles, solverParams& params);
	~ParticleSystem();

	void updateWrapper(solverParams& params);
	void getPositionsWrapper(float3* positionsPtr);

private:
	Particle* particles;	// デバイスメモリのポインタ

	#define cudaCheck(x) { cudaError_t err = x; if (err != cudaSuccess) { printf("Cuda error: %d in %s at %s:%d\n", err, #x, __FILE__, __LINE__); assert(0); } }
};

#endif