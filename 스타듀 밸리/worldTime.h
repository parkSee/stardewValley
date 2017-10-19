#pragma once
#include "singletonBase.h"

namespace month
{
	enum Enum
	{
		JAN,FEB,MAR,APR,MAY,JUN,JUL,AGS,SEP,OCT,NOV,DEC,END
	};
}


namespace dayDirection
{
	enum Enum
	{
		BRIGHT,EARLY_NIGHT,MID_NIGHT,DEEP_NIGHT
	};
}

struct tagTime
{
	float	second;
	int		minute;
	int		hour;
	int		day;
	string	ap;
};

class worldTime : public singletonBase<worldTime>
{
private:
	int						_day;
	month::Enum				_month;
	int						_saveHour;


	float					_timeFast;
public:
	tagTime					_time;
	bool					_isTimeFlow;
	dayDirection::Enum		_dayDirection;

	HRESULT init();
	void release();
	void update();

	void story();

	string getMonth();


	worldTime() 
	{}
	~worldTime() {}
};

