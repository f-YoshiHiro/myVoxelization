#include "Triangle3D.h"

BoundingBox3D Triangle3D::getBoundingBox()
{
	float minX, minY, minZ;
	float maxX, maxY, maxZ;

	minX = minY = minZ = 10000000.0;
	maxX = maxY = maxZ = -10000000.0;

	for (int i = 0; i<3; i++) {
		if (minX > this->v[i].x()) minX = this->v[i].x();
		if (minY > this->v[i].y()) minY = this->v[i].y();
		if (minZ > this->v[i].z()) minZ = this->v[i].z();

		if (maxX < this->v[i].x()) maxX = this->v[i].x();
		if (maxY < this->v[i].y()) maxY = this->v[i].y();
		if (maxZ < this->v[i].z()) maxZ = this->v[i].z();
	}

	EigenVector3 minV(minX, minY, minZ);
	EigenVector3 maxV(maxX, maxY, maxZ);
	return BoundingBox3D(minV, maxV);
}