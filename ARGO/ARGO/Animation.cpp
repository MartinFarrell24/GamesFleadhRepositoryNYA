#include "Animation.h"

Animation::Animation()
{
	current = new Idle();
}

void Animation::idle()
{
	current->idle(this);
}

void Animation::moving()
{
	current->moving(this);
}

void Animation::pushing()
{
	current->pushing(this);
}

void Animation::dying()
{
	current->dying(this);
}
