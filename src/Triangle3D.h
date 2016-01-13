#pragma once

#include <iostream>
#include <vector>
#include "Mesh.h"
#include "BoundingBox3D.h"
#include "ofMain.h"

class Triangle3D
{
public:
	int resolution;
	EigenVector3  v[3];
	EigenVector3  normal;
	BoundingBox3D getBoundingBox();
};