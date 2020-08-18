#include "color.h"
#include "opencv2/core.hpp"
#include <iostream>

using namespace cv;
using namespace std;
using namespace cv::ccm;

void test_cs(void) {
	Color color(ColorChecker2005_LAB_D50_2, Lab_D50_2);
	cout << "sRGB.M_to: " << sRGB.M_to << endl;
	cout << "AdobeRGB.M_to: " << AdobeRGB.M_to << endl;
	cout << "WideGamutRGB.M_to: " << WideGamutRGB.M_to << endl;
	cout << "ProPhotoRGB.M_to: " << ProPhotoRGB.M_to << endl;
	cout << "XYZ::_cam(D50_2, D65_2): " << XYZ_D65_2._cam(D50_2, D65_2) << endl;
	cout << "XYZ::_cam(D55_2, D50_2, VON_KRIS): " << XYZ_D65_2._cam(D55_2, D50_2, VON_KRIS) << endl;
	cout << "XYZ::_cam(D65_2, D65_2): " << XYZ_D65_2._cam(D65_2, D65_2) << endl;
	cout << "XYZ::_cam(D65_2, D50_2, IDENTITY): " << XYZ_D65_2._cam(D65_2, D50_2, IDENTITY) << endl;
}

void test_color(void) {
	Mat colors = (Mat_<Vec3d>(1, 1) <<
		Vec3d(0.3, 0.2, 0.5));

	Color color(colors, sRGB);
	Color color_rgb = color.to(sRGB);
	print(color_rgb.colors, "color_rgb");
	Color color_rgbl = color.to(sRGBL);
	print(color_rgbl.colors, "color_rgbl");
	Color color_xyz = color.to(XYZ_D65_2);
	print(color_xyz.colors, "color_xyz");
	Color color_lab = color.to(Lab_D65_2);
	print(color_lab.colors, "color_lab");
	Color color_xyz_d50 = color.to(XYZ_D50_2); 
	print(color_xyz_d50.colors, "color_xyz_d50");
	Color color_lab_d50 = color.to(Lab_D50_2);
	print(color_lab_d50.colors, "color_lab_d50");
}

int main() {
	test_color();
	return 1;
}