#include "BoundingBox3D.h"

BoundingBox3D::BoundingBox3D(ObjMesh &input){
	float minX, minY, minZ;
	float maxX, maxY, maxZ;

	minX = minY = minZ = 10000000.0;
	maxX = maxY = maxZ = -10000000.0;

	for (int i = 0; i<input.getVertNum(); i++) {
		if (minX > input.getVert(i).x()) minX = input.getVert(i).x();
		if (minY > input.getVert(i).y()) minY = input.getVert(i).y();
		if (minZ > input.getVert(i).z()) minZ = input.getVert(i).z();

		if (maxX < input.getVert(i).x()) maxX = input.getVert(i).x();
		if (maxY < input.getVert(i).y()) maxY = input.getVert(i).y();
		if (maxZ < input.getVert(i).z()) maxZ = input.getVert(i).z();
	}

	this->minVertex = EigenVector3(minX, minY, minZ);
	this->maxVertex = EigenVector3(maxX, maxY, maxZ);

	std::cout << "Bounding Box" << std::endl;
	std::cout << "minVert: " << minVertex << std::endl;
	std::cout << "maxVert: " << maxVertex << std::endl;
}

BoundingBox3D::BoundingBox3D(string filename) {
	ObjMesh input;
	input.read_from_file(filename);
	float minX, minY, minZ;
	float maxX, maxY, maxZ;

	minX = minY = minZ = 10000000.0;
	maxX = maxY = maxZ = -10000000.0;

	for (int i = 0; i<input.getVertNum(); i++) {
		if (minX > input.getVert(i).x()) minX = input.getVert(i).x();
		if (minY > input.getVert(i).y()) minY = input.getVert(i).y();
		if (minZ > input.getVert(i).z()) minZ = input.getVert(i).z();

		if (maxX < input.getVert(i).x()) maxX = input.getVert(i).x();
		if (maxY < input.getVert(i).y()) maxY = input.getVert(i).y();
		if (maxZ < input.getVert(i).z()) maxZ = input.getVert(i).z();
	}

	this->minVertex = EigenVector3(minX, minY, minZ);
	this->maxVertex = EigenVector3(maxX, maxY, maxZ);
	std::cout << "Bounding Box" << std::endl;
	std::cout << "minVert: " << minVertex << std::endl;
	std::cout << "maxVert: " << maxVertex << std::endl;
}

BoundingBox3D::BoundingBox3D(EigenVector3 minV, EigenVector3 maxV) {
	this->minVertex = minV;
	this->maxVertex = maxV;
}

void BoundingBox3D::LoadObj(ObjMesh input) {
	float min;
	float max;

	min = 10000000.0;
	max = -10000000.0;

	for (int i = 0; i<input.getVertNum(); i++) {
		if (min > input.getVert(i).x()) min = input.getVert(i).x();
		if (min > input.getVert(i).y()) min = input.getVert(i).y();
		if (min > input.getVert(i).z()) min = input.getVert(i).z();

		if (max < input.getVert(i).x()) max = input.getVert(i).x();
		if (max < input.getVert(i).y()) max = input.getVert(i).y();
		if (max < input.getVert(i).z()) max = input.getVert(i).z();
	}

	this->minVertex = EigenVector3(min, min, min);
	this->maxVertex = EigenVector3(max, max, max);

}

void BoundingBox3D::Show() {
	std::cout << "Bounding Box" << std::endl;
	std::cout << "minVert: " << minVertex << std::endl;
	std::cout << "maxVert: " << maxVertex << std::endl;
}