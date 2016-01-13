#pragma once
#include <iostream>
#include "ofMain.h"
#include "Triangle3D.h"

class CornerOfBox
{
	public:
		CornerOfBox();
		CornerOfBox(int _x, int _y, int _z, float xd, float yd, float zd);
		~CornerOfBox() {};

	public:
		int x;
		int y;
		int z;
		EigenVector3 p;

	public:
		EigenVector3 CornerOfBox::getClosestPoint(Triangle3D triangle);
};