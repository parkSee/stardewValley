#pragma once
#include "singletonBase.h"

namespace month
{
	enum Enum
	{
		JAN,FEB,MAR,APR,MAY,JUN,JULL,AGS,SEP,OCT,NOV,DEC,END
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
	int				_day;
	month::Enum		_month;
	int				_saveHour;
public:
	tagTime			_time;
	bool			_isTimeFlow;

	HRESULT init();
	void release();
	void update();

	string getMonth();


	worldTime() {}
	~worldTime() {}
};

