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
			string str = "더 살려두고 싶었지만 안타깝게 됬어 . . . 이만 죽어줘야 겠어 . . 자네들은";
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

			});
		});
	}
}