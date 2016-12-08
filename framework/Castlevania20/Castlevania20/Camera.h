#ifndef _CAMERA_H_
#define _CAMERA_H_


//#include "Simon.h"
#include "Graphics.h"
#include "GameConfig.h"
#include "CRectangle.h"

class Camera
{
private:
	static Camera* _camera;
	D3DXMATRIX orthographicMatrix;
	D3DXMATRIX identityMatrix;
	D3DXMATRIX viewMatrix;
	int width;
	int height;
	//Simon* following;
	int CameraX;
	int CameraY;
public:
	Camera(int width, int height);


	//Game Functions
	void Update(int x, int y);
	void Follow();
	void Unfollow();
	bool IsFollowing() const;
	void SetTransform() const;
	float getViewPortX();
	float getViewPortY();
	CRectangle *getViewPort();
	static Camera* getCurrentCamera();
	Camera();
	~Camera();
};

#endif