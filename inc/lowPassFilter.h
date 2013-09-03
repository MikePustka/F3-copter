/*
* F3-copter - STM32-F3 Discovery based tricopter
* Copyright (c) 2013 Ivan Sevcik - ivan-sevcik@hotmail.com
*
* This software is provided 'as-is', without any express or
* implied warranty. In no event will the authors be held
* liable for any damages arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute
* it freely, subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented;
*    you must not claim that you wrote the original software.
*    If you use this software in a product, an acknowledgment
*    in the product documentation would be appreciated but
*    is not required.
*
* 2. Altered source versions must be plainly marked as such,
*    and must not be misrepresented as being the original software.
*
* 3. This notice may not be removed or altered from any
*    source distribution.
*/

#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H

#include "recursiveFilterBase.h"

class LowPassFilter : public RecursiveFilterBase
{
public:
	// Higher time constant results in slower changes of system state (more inertia), attenuating high frequencies more.
	// Lower time constant results in faster changes of system state (less inertia), attenuating high frequencies less.
	LowPassFilter(float deltaT, float timeConstant);
protected:
	virtual math3d::Vector3<float> process(math3d::Vector3<float> sample);
private:
	float _factor;
};

#endif