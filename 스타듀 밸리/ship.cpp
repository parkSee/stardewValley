#include "stdafx.h"
#include "ship.h"


ship::ship()
{
}


ship::~ship()
{

}

HRESULT ship::init(const char* imageName, int x, int y)
{
	_image = IMAGEMANAGER->findImage(imageName);

	_x = x;
	_y = y;

	_angle = 0.0f;

	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	_speed = 0.0f;
	_radius = _image->getFrameWidth() / 2;

	_bullet = new bullet;
	_bullet->init("bullet", 10, 300);

	return S_OK;
}

void ship::release(void)
{

}

void ship::update(void)
{
//	keyControl();
	move();
	bulletMove();
}

void ship::render(void)
{
	draw();
	bulletDraw();
}


void ship::draw(void)
{
	_image->frameRender(getMemDC(), _rc.left, _rc.top);

	char str[128];
	sprintf(str, "%d도, %3.2f", int(_angle * 180 / PI), _speed);
	TextOut(getMemDC(), _rc.left, _rc.top - 15, str, strlen(str));

}

void ship::keyControl(void)
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_angle += 0.11f;
		if (_angle >= PI2) _angle -= PI2;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_angle -= 0.11f;
		
		if (_angle <= 0) _angle += PI2;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP)) _speed += 0.02f;
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) _speed -= 0.02f;
}

void ship::move()
{
	int frame;
	float angle;

	angle = _angle + PI16;
	if (angle >= PI2) angle -= PI2;

	frame = int(angle / PI8);
	_image->setFrameX(frame);

	float elapsedTime = TIMEMANAGER->getElapsedTime();
	float moveSpeed = elapsedTime * 100;

	_x += cosf(_angle) * _speed * moveSpeed;
	_y += -sinf(_angle) * _speed * moveSpeed;

	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

}

void ship::bulletFire()
{
	float x = _x + cosf(_angle) * 50;
	float y = _y + -sinf(_angle) * 50;

	_bullet->fire(x, y, _angle, 10);
}

void ship::bulletMove()
{
	_bullet->update();
}

void ship::bulletDraw()
{
	_bullet->render();
}

void ship::focusDraw(void)
{
	char str[128];

	//위치
	sprintf(str, "좌표 X : %d, Y : %d", _rc.left, _rc.top);
	TextOut(getMemDC(), 400, 10, str, strlen(str));
	//각도
	sprintf(str, "각도 : %d", int(_angle * (180 / PI)));
	TextOut(getMemDC(), 400, 30, str, strlen(str));
	//스피드
	sprintf(str, "속도 : %3.2f", _speed);
	TextOut(getMemDC(), 400, 50, str, strlen(str));

	//이미지는 화면 가운데다 그린다
	_image->frameRender(getMemDC(), WINSIZEX / 2 - _image->getFrameWidth() / 2, WINSIZEY / 2 - _image->getFrameHeight() / 2);

}

void ship::defaultDraw(RECT rcFocus)
{
	RECT rcSour;
	RECT rcTemp;

	int x, y;

	rcSour.left = rcFocus.left - ((WINSIZEX / 2) - (rcFocus.right - rcFocus.left) / 2);
	rcSour.top = rcFocus.top - ((WINSIZEY / 2) - (rcFocus.bottom - rcFocus.top) / 2);
	rcSour.right = rcSour.left + WINSIZEX;
	rcSour.bottom = rcSour.top + WINSIZEY;

	x = _rc.left - rcSour.left;
	y = _rc.top - rcSour.top;

	_image->frameRender(getMemDC(), x, y);
}