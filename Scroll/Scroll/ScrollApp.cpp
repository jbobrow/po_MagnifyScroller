/*	Created by Jonathan Bobrow on 7/2/13.
 *	Copyright 2013 __MyCompanyName__. All rights reserved.
 */

#include "ScrollApp.h"
#include "poApplication.h"
#include "poCamera.h"


// APP CONSTRUCTOR. Create all objects here.
ScrollApp::ScrollApp() {
	addModifier(new poCamera2D(poColor::black));
	
	poLineShape *l = new poLineShape(poPoint(0,225), poPoint(800,225));
	l->generateStroke(2).strokeColor = poColor::cyan;
	l->alpha = .8;
	addChild(l);
	
	scroller = new Scroller();
	scroller->position.set(350,0,0);
	addChild(scroller);
	
	control = new poControlPanel( "controlPanel", poColor(0,0.3,0.3,0.6) );
	
	control->addSliderF( "height",20.f, 100.f, this );
	control->addSliderF( "location",0.f, 600.f, this );
	control->addSliderF( "magnification",1.f, 5.f, this );
	control->addSliderF( "period",50, 400, this );
		
	addChild(control);
	control->autoResize();
}

// APP DESTRUCTOR. Delete all objects here.
ScrollApp::~ScrollApp() {
}

// UPDATE. Called once per frame. Animate objects here.
void ScrollApp::update() {
	
}

// DRAW. Called once per frame. Draw objects here.
void ScrollApp::draw() {
	
}

// EVENT HANDLER. Called when events happen. Respond to events here.
void ScrollApp::eventHandler(poEvent *event) {
	
}

// MESSAGE HANDLER. Called from within the app. Use for message passing.
void ScrollApp::messageHandler(const std::string &msg, const poDictionary& dict) {

	if ( msg == "height" ) {
        scroller->setHeight(control->getFloat("height"));
    }
	
	if ( msg == "location" ) {
        scroller->setLocation(control->getFloat("location"));
    }
	
	if ( msg == "magnification" ) {
        scroller->setMagnification(control->getFloat("magnification"));
    }
		
	if ( msg == "period" ) {
        scroller->setPeriod(control->getFloat("period"));
    }
	
}
