#include "stdafx.h"
#include "worldTime.h"
#include "gameObject.h"

using namespace month;

HRESULT worldTime::init()
{
	_month = month::JUN;

	ZeroMemory(&_time, sizeof(tagTime));
	
	_time.second = 0.0f;
	_time.minute = 0.0f;
	_time.hour = 6;
	_time.ap = "am";
	_time.day = 1;
	_isTimeFlow = true;
	_saveHour = 6;

	return S_OK;
}

void worldTime::release()
{

}

void worldTime::update()
{
	//시간을 지배한다~!
	if (_isTimeFlow == true)							//시간 불값이 활성화가 되있다면 시간계산을 해라 
	{
		_time.second += TIMEMANAGER->getElapsedTime();	//초는 ElapsedTime으로 현실시간반영 
		if (_time.second >= 10.0f)
		{
			_time.second = 0.0f;
			_time.minute += 10;

			if (_time.minute >= 60)
			{
				_time.hour += 1;
				_time.minute = 0;
				
				if (abs(_saveHour - _time.hour) == 0)
				{
					_saveHour = _time.hour;

					gameObject* ui = TOWNWORLD->findObject(objectType::INTERFACE, "UI");
					ui->sendMessage(tagMessage("changePointer"));
				}

				if (_time.ap == "pm" && _time.hour >= 13)
				{
					_time.hour = 0;
					_time.day += 1;
					_time.ap = "am";

					if (_time.day >= 31)
					{
						_month = (month::Enum)(_month + 1);

						if (_month == month::END)
						{
							_month = month::JAN;
						}
					}
				}
				else if (_time.ap == "am" && _time.hour >= 13)
				{
					_time.hour = 0;
					_time.ap = "pm";
				}
			}
		}
	}
}

string worldTime::getMonth()
{
	if (_month == JAN)
	{
		return "Jan";
	}
	if (_month == FEB)return "Feb";
	if (_month == MAR)return "Mar";
	if (_month == APR)return "Apr";
	if (_month == MAY)return "May";
	if (_month == JUN)return "Jun";
	if (_month == JUL)return "JULL";
	if (_month == AGS)return "Ags";
	if (_month == SEP)return "Sep";
	if (_month == NOV)return "Nov";
	if (_month == OCT)return "Oct";
	if (_month == DEC)return "Dec";

}