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

namespace playerPos
{
	enum Enum
	{
		HOUSE,OUTSIDE
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

	bool					_isUse;
public:
	tagTime					_time;
	bool					_isTimeFlow;
	dayDirection::Enum		_dayDirection;
	playerPos::Enum			_playerPos;

	HRESULT init();
	void release();
	void update();

	void story();

	string getMonth();

	void dayGone();


	worldTime() 
	{}
	~worldTime() {}
};

