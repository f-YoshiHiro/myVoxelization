#include "CornerOfBox.h"

CornerOfBox::CornerOfBox()
{
}

CornerOfBox::CornerOfBox(int _x, int _y, int _z, float xd, float yd, float zd)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
	p = EigenVector3(xd, yd, zd);
}

EigenVector3 CornerOfBox::getClosestPoint(Triangle3D triangle)
{
	EigenVector3 p;
	EigenVector3 vox[8];
	vox[0] = EigenVector3(this->x,				 this->y,               this->z);
	vox[1] = EigenVector3(this->x + this->p.x(), this->y,               this->z);
	vox[2] = EigenVector3(this->x,               this->y + this->p.y(), this->z);
	vox[3] = EigenVector3(this->x + this->p.x(), this->y + this->p.y(), this->z);
	vox[4] = EigenVector3(this->x,               this->y,               this->z + this->p.z());
	vox[5] = EigenVector3(this->x + this->p.x(), this->y,               this->z + this->p.z());
	vox[6] = EigenVector3(this->x,               this->y + this->p.y(), this->z + this->p.z());
	vox[7] = EigenVector3(this->x + this->p.x(), this->y + this->p.y(), this->z + this->p.z());

	float distance = 1000000;
	for (int i = 0; i<8; i++) {
		for (int j = 0; j<3; j++) {
			if (distance > (vox[i] - triangle.v[j]).norm() ) {
				distance = (vox[i] - triangle.v[j]).norm();
				p = triangle.v[j]; //vox[i];
			}
		}
	}

	return p;
}