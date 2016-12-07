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
	this->CameraX = 0;
	this->CameraY = 0;

	D3DXMatrixOrthoLH(&orthographicMatrix, width, -height, 0.0f, 1.0f);
	D3DXMatrixIdentity(&identityMatrix);
}
Camera::Camera()
{
}

void Camera::Update(int x, int y)
{
	this->CameraX = x;
	this->CameraY = y;
	//int cameraX = this->width / 2, cameraY = this->height / 2;


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
	return CameraX;
}

float Camera::getViewPortY() {
	return CAMERA_HEIGHT;
}

#endif