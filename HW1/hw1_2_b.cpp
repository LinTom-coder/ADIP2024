#include "Header.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

void hw1_2_b() {
	cv::Mat image = cv::Mat(512, 512, CV_8UC3, cv::Scalar(255, 255, 255));

	//��
	cv::Point center(256, 220);
	int radius = 180;
	cv::Scalar color(0, 0, 0);
	int thickness = 2;
	cv::circle(image, center, radius, color, thickness + 3);

	//�Ʀr
	std::string text = "110310238";
	cv::Point org(160, 500);                       // ��r�����U����m
	int fontFace = cv::FONT_HERSHEY_SIMPLEX;      // �r��
	double fontScale = 1.0;                       // �r���j�p
	cv::putText(image, text, org, fontFace, fontScale, color, thickness);

	//�u��
	cv::Point startPoint(156, 120);    // �_�I�y��
	cv::Point endPoint(356, 120);    // ���I�y��
	cv::line(image, startPoint, endPoint, color, thickness + 1);
	cv::Point startPoint1(256, 120);
	cv::Point endPoint1(256, 320);
	cv::line(image, startPoint1, endPoint1, color, thickness + 1);
	cv::Point startPoint2(356, 320);
	cv::Point endPoint2(156, 320);
	cv::line(image, startPoint2, endPoint2, color, thickness + 1);

	cv::Point startPoint3(136, 140);
	cv::Point endPoint3(196, 140);
	cv::line(image, startPoint3, endPoint3, color, thickness + 1);
	cv::Point startPoint4(316, 140);
	cv::Point endPoint4(376, 140);
	cv::line(image, startPoint4, endPoint4, color, thickness + 1);
	cv::Point startPoint5(166, 140);
	cv::Point endPoint5(166, 300);
	cv::line(image, startPoint5, endPoint5, color, thickness + 1);
	cv::Point startPoint6(346, 140);
	cv::Point endPoint6(346, 300);
	cv::line(image, startPoint6, endPoint6, color, thickness + 1);

	//���
	std::vector<cv::Point> points;
	points.push_back(cv::Point(246, 18));  // ���W��
	points.push_back(cv::Point(266, 18));   // �k�W���]�צV�k�W�^
	points.push_back(cv::Point(266, 38));  // �k�U��
	points.push_back(cv::Point(246, 38));  // ���U���]�צV���U�^
	std::vector<std::vector<cv::Point>> fillPoints;
	fillPoints.push_back(points);
	//cv::fillPoly(image, fillPoints, color);

	std::vector<cv::Point> points1;
	points1.push_back(cv::Point(438, 210));  // ���W��
	points1.push_back(cv::Point(458, 210));   // �k�W���]�צV�k�W�^
	points1.push_back(cv::Point(458, 230));  // �k�U��
	points1.push_back(cv::Point(438, 230));  // ���U���]�צV���U�^
	fillPoints.push_back(points1);

	std::vector<cv::Point> points2;
	points2.push_back(cv::Point(246, 402));  // ���W��
	points2.push_back(cv::Point(266, 402));   // �k�W���]�צV�k�W�^
	points2.push_back(cv::Point(266, 422));  // �k�U��
	points2.push_back(cv::Point(246, 422));  // ���U���]�צV���U�^
	fillPoints.push_back(points2);

	std::vector<cv::Point> points3;
	points3.push_back(cv::Point(53, 210));  // ���W��
	points3.push_back(cv::Point(73, 210));   // �k�W���]�צV�k�W�^
	points3.push_back(cv::Point(73, 230));  // �k�U��
	points3.push_back(cv::Point(53, 230));  // ���U���]�צV���U�^
	fillPoints.push_back(points3);

	std::vector<cv::Point> points4;
	points4.push_back(cv::Point(166, 34));  // ���W��
	points4.push_back(cv::Point(186, 26));   // �k�W���]�צV�k�W�^
	points4.push_back(cv::Point(197, 47));  // �k�U��
	points4.push_back(cv::Point(175, 56));  // ���U���]�צV���U�^
	fillPoints.push_back(points4);

	std::vector<cv::Point> points5;
	points5.push_back(cv::Point(86, 100));  // ���W��
	points5.push_back(cv::Point(100, 81));   // �k�W���]�צV�k�W�^
	points5.push_back(cv::Point(120, 100));  // �k�U��
	points5.push_back(cv::Point(105, 115));  // ���U���]�צV���U�^
	fillPoints.push_back(points5);

	std::vector<cv::Point> points6;
	points6.push_back(cv::Point(86, 340));  // ���W��
	points6.push_back(cv::Point(104, 324));   // �k�W���]�צV�k�W�^
	points6.push_back(cv::Point(120, 340));  // �k�U��
	points6.push_back(cv::Point(100, 355));  // ���U���]�צV���U�^
	fillPoints.push_back(points6);

	std::vector<cv::Point> points7;
	points7.push_back(cv::Point(146, 400));  // ���W��
	points7.push_back(cv::Point(162, 378));   // �k�W���]�צV�k�W�^
	points7.push_back(cv::Point(181, 388));  // �k�U��
	points7.push_back(cv::Point(160, 410));  // ���U���]�צV���U�^
	fillPoints.push_back(points7);

	std::vector<cv::Point> points8;
	points8.push_back(cv::Point(333, 387));  // ���W��
	points8.push_back(cv::Point(355, 375));   // �k�W���]�צV�k�W�^
	points8.push_back(cv::Point(376, 396));  // �k�U��
	points8.push_back(cv::Point(354, 409));  // ���U���]�צV���U�^
	fillPoints.push_back(points8);

	std::vector<cv::Point> points9;
	points9.push_back(cv::Point(396, 330));  // ���W��
	points9.push_back(cv::Point(414, 315));   // �k�W���]�צV�k�W�^
	points9.push_back(cv::Point(436, 336));  // �k�U��
	points9.push_back(cv::Point(422, 352));  // ���U���]�צV���U�^
	fillPoints.push_back(points9);

	std::vector<cv::Point> points10;
	points10.push_back(cv::Point(423, 155));  // ���W��
	points10.push_back(cv::Point(444, 142));   // �k�W���]�צV�k�W�^
	points10.push_back(cv::Point(456, 166));  // �k�U��
	points10.push_back(cv::Point(435, 177));  // ���U���]�צV���U�^
	fillPoints.push_back(points10);

	std::vector<cv::Point> points11;
	points11.push_back(cv::Point(370, 81));  // ���W��
	points11.push_back(cv::Point(394, 62));   // �k�W���]�צV�k�W�^
	points11.push_back(cv::Point(412, 80));  // �k�U��
	points11.push_back(cv::Point(388, 100));  // ���U���]�צV���U�^
	fillPoints.push_back(points11);

	cv::fillPoly(image, fillPoints, color);
	cv::imshow("Taipei Tech", image);
	cv::imwrite("2_b.jpg", image);
	cv::waitKey(0);
	//return 0;

}