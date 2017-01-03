//#include "SubWeapon.h"
//
//SubWeapon::SubWeapon()
//{
//	_cross = new Sprite(new Texture(L"resource\\sprite\\XCross.png", 3, 1, 3), 40);
//	used = false;
//}
//
//SubWeapon::~SubWeapon()
//{
//}
//
//
//void SubWeapon::Trigger(int simon_x, int simon_y, WEAPONNAME _subWeapon, bool isleft = true) {
//	_x = simon_x;
//	_y = simon_y;
//	switch (_subWeapon)
//	{
//	case Cross: {
//		face_left = isleft;
//		this->_SubWeapon = _SubWeapon;
//		if (isleft) {
//			_vx = -0.4f;
//		}
//		else {
//			_vx = 0.4f;
//		}
//
//		used = true;
//	}
//	default:
//		break;
//	}
//	
//}
//
//void SubWeapon::Update(int Delta) {
//	if (used) {
//		switch (this->_SubWeapon)
//		{
//		case Cross: {
//			_x += _vx*Delta;
//			if (face_left) {
//				_vx += 0,02f;
//			}
//			else {
//				_vx -= 0, 02f;
//			}
//			_cross->Update(Delta);
//		}
//		default:
//			break;
//		}
//	}
//}
//
//void SubWeapon::Draw() {
//	if (used) {
//		switch (_sub)
//		{
//		case Cross: {
//			this->_cross->Draw(_x, _y);
//		}
//		default:
//			break;
//		}
//	}
//}