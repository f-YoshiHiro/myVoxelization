#pragma once

#include <iostream>
#include <vector>
#include "mesh.h"
#include "ofMain.h"
#include "math_headers.h"

class BoundingBox3D {

	private:
		EigenVector3 minVertex;
		EigenVector3 maxVertex;

	public:
		BoundingBox3D() {};
		BoundingBox3D(ObjMesh &input);
		BoundingBox3D(string filename);
		BoundingBox3D(EigenVector3 minV, EigenVector3 maxV);
		~BoundingBox3D() {};

		void LoadObj(ObjMesh input);
		void Show();

	public:
		// get methods
		EigenVector3 getMinVector() { return (this->maxVertex); }
		float getMinX() { return minVertex.x(); }
		float getMinY() { return minVertex.y(); }
		float getMinZ() { return minVertex.z(); }

		EigenVector3 getMaxVector() { return (this->minVertex); }
		float getMaxX() { return maxVertex.x(); }
		float getMaxY() { return maxVertex.y(); }
		float getMaxZ() { return maxVertex.z(); }
};