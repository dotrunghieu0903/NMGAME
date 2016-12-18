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
	this->CameraY =1423-32;

	D3DXMatrixOrthoLH(&orthographicMatrix, width, -height, 0.0f, 1.0f);
	D3DXMatrixIdentity(&identityMatrix);

	limitLeft = width/2;
	
}
Camera::Camera()
{
}

void Camera::Update(int x, int y)
{
	CameraX = x;
	if (x > 3825 && x < 3835 && y > 1195 && y < 1205) {
		change = true;
		direction = DIRECTION_UP;
	}

	if (change) {
		CameraY = 862 + 176 - 32;
		change = false;
	}
	if (x > 3825 && x < 3835 && y > 1195 && y < 1205) {
		change = true;
		direction = DIRECTION_UP;
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

CRectangle* Camera::getViewPort() {
	return new CRectangle((int)this->CameraX - this->height/2, (int)this->CameraY- this->width/2, this->width, this->height);
}

#endif