#include "stdafx.h"
#include "tagMessage.h"


tagMessage::tagMessage()
{
	isActive = true;
	text = "";
	delayTime = 0.0f;
	data = 0;
	data2 = 0;
}


tagMessage::tagMessage(string txt, float time, int d, float d2, vector<gameObject*> target , string txting)
{
	isActive = true;
	text = txt;
	delayTime = time;
	data = d;
	data2 = d2;
	targetList = target;
	conversation = txting;
}
