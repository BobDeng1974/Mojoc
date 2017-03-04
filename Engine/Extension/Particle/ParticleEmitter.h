/*
 *
 *
 *  Created on: 2013-1-27
 *  Author: scott.cgi
 */

#ifndef particle_emitter_h
#define particle_emitter_h


#include "Mojoc/Graphics/OpenGL/Mesh.h"
#include "Mojoc/Extension/Particle/ParticleEmitterData.h"
#include "Mojoc/Extension/Particle/Particle.h"
#include "Mojoc/Graphics/OpenGL/Texture.h"
#include "Mojoc/Toolkit/Utils/Array.h"


typedef struct
{
    /** Emitter emission position x */
    float                emissionX;
    /** Emitter emission position y */
    float                emissionY;
    /** Emitter emission angle */
    float                emissionAngle;

    Mesh                 mesh[1];

	int                  emission;
	int                  emissionDiff;
	float                emissionDelta;

	float                lifeOffset;
	float                lifeOffsetDiff;

	float                life;
	float                lifeDiff;

	float                duration;
	float                durationTimer;

	float                delay;
	float                delayTimer;

	int                  activeCount;
	Array(Particle)*     particleArr;
	ParticleEmitterData* emitterData;
}
ParticleEmitter;


struct AParticleEmitter
{
	/**
	 * Create new ParticleEmitter that allocate memory and need to free it manually
	 */
	ParticleEmitter* (*Create)   (ParticleEmitterData* emitterData, Texture* texture);

	/**
	 * Initialize ParticleEmitter that memory has already allocated
	 */
	void             (*Init)     (ParticleEmitterData* emitterData, Texture* texture, ParticleEmitter* outParticleEmitter);

	/**
	 * Free members memory that allocate by malloc and reset some property values
	 */
	void             (*Release)  (ParticleEmitter*     emitter);

	/**
	 * Called per frame
	 */
	void             (*Update)   (ParticleEmitter*     emitter,     float    deltaTime);

	/**
	 * Restart ParticleEmitter to the initial state
	 */
	void             (*Restart)  (ParticleEmitter*     emitter);
};

extern struct AParticleEmitter AParticleEmitter[1];


static inline Drawable* AParticleEmitterGetDrawable(ParticleEmitter* emitter)
{
	return emitter->mesh->drawable;
}

static inline void AParticleEmitterDraw(ParticleEmitter* emitter)
{
	AMeshDraw(emitter->mesh);
}

#endif