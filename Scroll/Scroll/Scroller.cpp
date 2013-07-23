#include "Scroller.h"

Scroller::Scroller()
{
	location = 200.f;
	max = 2.f;
	min = 1.f;
	period = 50.f; // 200
	
	height = 50.f;
	bScrolling = false;

	for(int i=0; i<10; i++){
		poRectShape *r = new poRectShape(200,height);
		r->position.set(0,height*i,0);
		r->fillColor = poColor::random();
		r->alpha = .5;
		r->drawBounds = true;
		r->setAlignment(PO_ALIGN_CENTER_LEFT);
		contents.push_back(r);
		addChild(contents.back());

		poTextBox *t = new poTextBox(200,height);
		t->setText("shift");
		t->setTextSize(height/4);
		t->textColor = poColor::white;
		t->doLayout();
		labels.push_back(t);
		r->addChild(labels.back());
	}
	
	debugTB = new poTextBox(400,height);
	debugTB->position.set(300,0,0);
	debugTB->setText("height");
	debugTB->setTextSize(20);
	debugTB->textColor = poColor::white;
	debugTB->doLayout();
	addChild(debugTB);
		
	addEvent(PO_MOUSE_DOWN_EVENT, this);
	addEvent(PO_MOUSE_DRAG_EVENT, this);
	addEvent(PO_MOUSE_UP_EVENT, this);
}


Scroller::~Scroller() 
{
}


void Scroller::update()
{
	float totalHeight = 0;
	
	// update position of contents
	for(int i=0; i<10; i++){
		poRectShape *r = contents[i];
		r->position.set(0,height*i + scroll_offset,0);
		
		bool above = r->position.y - location < 0;
		float dist = r->position.y - location;
		float scale;
		float shift;
		float theta;
		
		if(  dist > -period && dist <= period ){
			
			theta = poMapf(0, period, dist, M_PI, 0);
			
			scale = min + (max - min) * (1 - cos(theta))/2.f;
						
			if(theta > M_PI)
				shift = poMapf( 1, -1, cos(theta), 0, period/2.f);
			else
				shift = poMapf( -1, 1, cos(theta), period/2.f, period);
			
			// TODO: or calculate the shift as equal to half of the current items size + half of the above items size from the previous midpoint
		}
		else{
			
			scale = 1.f;
			
			if( !above )
				shift = period;
			else
				shift = 0;
		}
		
		r->scale = poPoint(scale, scale, 1.f);
		r->position += poPoint(0,shift);
		
		
		poTextBox *t = labels[i];
		char buffer[256];
		sprintf(buffer, "shift: %i, y: %i", (int)shift, (int)(height * scale));
		t->setText(buffer);
		t->doLayout();
		
		totalHeight += height * scale;
	}
	
	char buffer[256];
	sprintf(buffer, "height: %i", (int)totalHeight);
	debugTB->setText(buffer);
	debugTB->doLayout();
}


void Scroller::setHeight(float f)
{
	height = f;

	for(int i=0; i<10; i++){
		poRectShape *r = contents[i];
		r->reshape(200, height);
	}
}


void Scroller::setLocation(float f)
{
	location = f;
}


void Scroller::setMagnification(float f)
{
	max = f;
}


void Scroller::setPeriod(float f)
{
	period = f;
}


void Scroller::eventHandler(poEvent *event)
{
	switch (event->type) {
		
		case PO_MOUSE_DOWN_EVENT:
			bScrolling = true;
			touchStart = event->localPosition;
			break;
			
		case PO_MOUSE_DRAG_EVENT:
			if(bScrolling){
				scroll_offset = event->localPosition.y - touchStart.y;
			}
			break;
			
		case PO_MOUSE_UP_EVENT:
			bScrolling = false;
			break;
			
		default:
			break;
	}
}


void Scroller::messageHandler(const std::string &msg, const poDictionary& dict) 
{
}
