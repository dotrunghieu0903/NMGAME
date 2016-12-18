#ifndef _CAMERA_H_
#define _CAMERA_H_


//#include "Simon.h"
#include "Graphics.h"
#include "GameConfig.h"
#include "CRectangle.h"

#define DIRECTION_UP 1
#define DIRECTION_RIGHT 2
#define DIRECTION_LEFT 3

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
	//tâm của camera
	int CameraX; 
	int CameraY;

	int limitLeft;
	int limitRight;
		
	int direction;
	
public:
	bool change = false;
	Camera(int width, int height);


	//Game Functions
	void Update(int x, int y);
	void Follow();
	void Unfollow();
	bool IsFollowing() const;
	void SetTransform() const;
	float getViewPortX();
	float getViewPortY();
	CRectangle *getCenter();
	static Camera* getCurrentCamera();
	Camera();
	~Camera();
};

#endif