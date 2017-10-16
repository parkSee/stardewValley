#pragma once

class gameObject;

struct tagMessage
{
	string text;
	float delayTime;
	int data;
	float data2;
	bool isActive;
	vector<gameObject*> targetList;
	string str;
	string conversation;

	tagMessage();
	tagMessage(string txt, float time = 0.0f, int d = 0, float d2 = 0.0f, vector<gameObject*> target = vector<gameObject*>() 
				, string txting = "",string STRING="");
};