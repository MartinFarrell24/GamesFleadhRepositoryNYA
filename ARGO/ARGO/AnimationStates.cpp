#include "AnimationStates.h"

void Idle::moving(Animation* a)
{
	a->setCurrent(new Moving());
	delete this;
}

void Moving::idle(Animation* a)
{
	a->setCurrent(new Idle());
	delete this;
}
void Moving::pushing(Animation* a)
{
	a->setCurrent(new Pushing());
	delete this;
}
void Moving::dying(Animation* a)
{
	a->setCurrent(new Dying());
	delete this;
}

void Pushing::idle(Animation* a)
{
	a->setCurrent(new Idle());
	delete this;
}

void Dying::idle(Animation* a)
{
	a->setCurrent(new Idle());
	delete this;
}