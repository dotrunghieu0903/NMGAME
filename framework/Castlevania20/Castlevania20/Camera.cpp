#ifndef _CAMERA_CPP_
#define _CAMERA_CPP_
#include "Camera.h"

Camera* Camera::_camera = 0;


Camera::~Camera() {

}
Camera::Camera(int width, int height)
{
	this->width = width;
	this->height = height;
	this->CameraX = width/2;
	this->CameraY = 1391;

	D3DXMatrixOrthoLH(&orthographicMatrix, width, -height, 0.0f, 1.0f);
	D3DXMatrixIdentity(&identityMatrix);

	limitLeft = width/2;
	
}
Camera::Camera()
{
}

void Camera::Update(int x, int y, int stage)
{
	if (thisStage < stage) {
		change = true;
		thisStage = stage;
	}

	if (change == true) {
		switch (stage)
		{
		case 1:
			change = false;
			break;
		case 2:
			change = false;
			break;
		default:
			break;
		}
	}


	CameraX = x; 

	switch (stage)
	{
	case 1:
		CameraY = 1391;
		limitLeft = 3584+width/2;
		limitRight = 4096+width/2;
		break;
	case 2: {
		//1006
		CameraY = 863 + height / 2 -32*3;
		limitLeft = 3071 + width / 2;
		limitRight = 4096 + width / 2;
		break;
	}
	case 3: {
		//1006
		CameraY = 863 + height / 2 - 32 * 3;
		limitLeft = 1536 + width / 2;
		limitRight = 3100 + width / 2;
		break;
	}
	case 4: {
		//1006
		CameraY = 480 + height / 2 - 32 * 3;
		limitLeft = 1536 + width / 2;
		limitRight = 3071 + width / 2;
		break;
	}
	case 5:{
		CameraY = 480 + height / 2 - 32 * 3;
		limitLeft = 0 + width / 2;
		limitRight = 1567 + width / 2;
		break;
	}
	case 6: {
		CameraY = 96 + height / 2 - 32 * 3;
		limitLeft = 0 + width / 2;
		limitRight = 1537 + width / 2;
		break;
	}
	default:
		break;
	}
	
	if (CameraX < limitLeft) {
		CameraX = limitLeft;
	}
	if (CameraX + width > limitRight) {
		CameraX = limitRight - width;
	}

	this->viewMatrix = D3DXMATRIX(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		-CameraX, -CameraY, 0, 1
	);
}

void Camera::Follow()
{
	//this->following = Simon::getCurrentSimon();
}

void Camera::Unfollow()
{
	//this->following = nullptr;
}

bool Camera::IsFollowing() const
{
	return nullptr;
}

void Camera::SetTransform() const
{
	Graphics::getCurGraphics()->_Direct3DDevice->SetTransform(D3DTS_PROJECTION, &orthographicMatrix);
	Graphics::getCurGraphics()->_Direct3DDevice->SetTransform(D3DTS_WORLD, &identityMatrix);
	Graphics::getCurGraphics()->_Direct3DDevice->SetTransform(D3DTS_VIEW, &viewMatrix);
}
Camera* Camera::getCurrentCamera() {
	if (!_camera)
		_camera = new Camera(CAMERA_WIDTH, CAMERA_HEIGHT);
	return _camera;
}

float Camera::getViewPortX() {
	return CameraX - width/2;
}

float Camera::getViewPortY() {
	return CameraY - height / 2;
}

CRectangle* Camera::getCenter() {
	return new CRectangle((int)this->CameraX, (int)this->CameraY, this->width, this->height);
}

#endif