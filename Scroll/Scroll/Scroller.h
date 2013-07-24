#pragma once

/*	Created by Jonathan Bobrow on 7/2/13.
 *	Copyright 2013 __MyCompanyName__. All rights reserved.
 */

#include "poObject.h"
#include "poShapeBasics2D.h"
#include "poTextBox.h"

enum{
	SCROLL_MAGNIFICATION_LINEAR = 0,
	SCROLL_MAGNIFICATION_COSINE = 1
};

class Scroller : public poObject
{
public:
	Scroller();
	virtual ~Scroller();
	
	virtual void update();
	virtual void eventHandler(poEvent *event);
	virtual void messageHandler(const std::string &msg, const poDictionary& dict=poDictionary());
	
	void setHeight(float f);
	void setLocation(float f);
	void setMagnification(float f);
	void setPeriod(float f);

	
private:
	float	height;
	float	location;
	float	max;
	float	min;
	float	period;
	
	float	scroll_offset;
	
	bool	bScrolling;
	poPoint	touchStart;
	
	poTextBox*	debugTB;
	
	std::vector<poRectShape*>	contents;
	std::vector<poTextBox*>	labels;
};