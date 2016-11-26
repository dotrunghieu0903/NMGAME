#ifndef _CAMERA_H_
#define _CAMERA_H_
#include "Globals.h"
#include <fstream>

using namespace std;
class Camera
{
public:
	Camera();

	void UpdateCamera(D3DXVECTOR3* cameraLocation);
	~Camera();
private:
	static Camera* objCamera; //khai báo biến tĩnh khởi tạo 1 lần dùng cả chương trình.
	D3DXVECTOR2 m_previousPosition;
};


#endif