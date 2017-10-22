#include "stdafx.h"
#include "worldTime.h"

#include "UI.h"
#include "mouse.h"
#include "publicUI.h"
#include "inventory.h"
#include "dropItem.h"
#include "eProgressBar.h"
#include "pierre.h"
#include "weather.h"
#include "player.h"
#include "caroline.h"

using namespace month;
using namespace dayDirection;

void worldTime::story()
{
	if (KEYMANAGER->isOnceKeyDown('M'))
	{
		this->_isTimeFlow = false;
		SOUNDMANAGER->stop("bgm1");
		SOUNDMANAGER->play("bgm3", 1.0f);

		pierre* pirre = (pierre*)TOWNWORLD->findObject(objectType::HUMAN, "pierre");
		player* target = (player*)TOWNWORLD->findObject(objectType::HUMAN, "player");
		vector<gameObject*>	sendList;
		vector<mapToolTile*> vList = TOWNWORLD->getMap()->getShortestAStar(pirre->getIndexX(), pirre->getIndexY()
			, target->getIndexX(), target->getIndexY(), false);

		for (int i = 0; i < vList.size(); ++i)
		{
			sendList.push_back((gameObject*)vList[i]);
		}

		pirre->sendMessage(tagMessage("setMoveRoute", 0.0f, 0, 0, sendList));
		pirre->setCallback([]()
		{
			UI* ui = (UI*)TOWNWORLD->findObject(objectType::INTERFACE, "UI");
			string str = "내가 밤에 돌아다니지 말랬지!!! 이번에는 봐주지만 다음엔 가차 없을 줄 알아";
			ui->sendMessage(tagMessage(CONVERSATIONUI, 0.1f, PIERRE, 0, vector<gameObject*>(), str));

			ui->setCallback([]()
			{
				pierre* pirre = (pierre*)TOWNWORLD->findObject(objectType::HUMAN, "pierre");
				caroline* calorne = (caroline*)TOWNWORLD->findObject(objectType::HUMAN, "caroline");
				vector<gameObject*>	sendList;
				vector<mapToolTile*> vList = TOWNWORLD->getMap()->getShortestAStar(pirre->getIndexX(), pirre->getIndexY()
					, calorne->getIndexX(), calorne->getIndexY(), false);

				for (int i = 0; i < vList.size(); ++i)
				{
					sendList.push_back((gameObject*)vList[i]);
				}

				pirre->sendMessage(tagMessage("setMoveRoute", 0.0f, 0, 0, sendList));
				SOUNDMANAGER->stop("bgm3");
				SOUNDMANAGER->play("bgm1");

			});
		});
	}


	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		pierre* pirre = (pierre*)TOWNWORLD->findObject(objectType::HUMAN, "pierre");
		RECT rc = CAMERAMANAGER->getRenderRc();
		if (PtInRect(&pirre->getRect(), PointMake(_ptMouse.x + rc.left, _ptMouse.y + rc.top)))
		{
			UI* ui = (UI*)TOWNWORLD->findObject(objectType::INTERFACE, "UI");
			string str = "날씨가 참 좋은 것 같아. 그렇게 생각하니 너도?? 그리고 밤에는 절대 밖에 나오지 말게 . . . 그랬다가는 무서운  일이 생길 걸세.";
			ui->sendMessage(tagMessage(CONVERSATIONUI, 0, PIERRE, 0, vector<gameObject*>(), str));
		}
	}
	
}