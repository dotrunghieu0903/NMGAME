#ifndef _CAMERA_H_
#define _CAMERA_H_


#include "Simon.h"
#include "Graphics.h"

class Camera
{
private:
	static Camera* _camera;
	D3DXMATRIX orthographicMatrix;
	D3DXMATRIX identityMatrix;
	D3DXMATRIX viewMatrix;
	int width;
	int height;
	Simon* following;
public:
	Camera(int width, int height);


	//Game Functions
	void Update();
	void Follow();
	void Unfollow();
	bool IsFollowing() const;
	void SetTransform() const;
	static Camera* getCurrentCamera();
	Camera();
	~Camera();
};

#endif