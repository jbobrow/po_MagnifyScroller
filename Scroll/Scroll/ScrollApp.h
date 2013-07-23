/*	Created by Jonathan Bobrow on 7/2/13.
 *	Copyright 2013 __MyCompanyName__. All rights reserved.
 */

#include "poObject.h"
#include "Scroller.h"
#include "poControlPanel.h"

class ScrollApp : public poObject {
public:
	ScrollApp();
	virtual ~ScrollApp();
	
    virtual void update();
    
    virtual void draw();
	
    virtual void eventHandler(poEvent *event);
	
    virtual void messageHandler(const std::string &msg, const poDictionary& dict=poDictionary());
	
	Scroller	*scroller;
	
	poControlPanel* control;
};

