#include "Header.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

void hw1_2_b() {
	cv::Mat image = cv::Mat(512, 512, CV_8UC3, cv::Scalar(255, 255, 255));

	//圓
	cv::Point center(256, 220);
	int radius = 180;
	cv::Scalar color(0, 0, 0);
	int thickness = 2;
	cv::circle(image, center, radius, color, thickness + 3);

	//數字
	std::string text = "110310238";
	cv::Point org(160, 500);                       // 文字的左下角位置
	int fontFace = cv::FONT_HERSHEY_SIMPLEX;      // 字型
	double fontScale = 1.0;                       // 字型大小
	cv::putText(image, text, org, fontFace, fontScale, color, thickness);

	//線條
	cv::Point startPoint(156, 120);    // 起點座標
	cv::Point endPoint(356, 120);    // 終點座標
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

	//方形
	std::vector<cv::Point> points;
	points.push_back(cv::Point(246, 18));  // 左上角
	points.push_back(cv::Point(266, 18));   // 右上角（斜向右上）
	points.push_back(cv::Point(266, 38));  // 右下角
	points.push_back(cv::Point(246, 38));  // 左下角（斜向左下）
	std::vector<std::vector<cv::Point>> fillPoints;
	fillPoints.push_back(points);
	//cv::fillPoly(image, fillPoints, color);

	std::vector<cv::Point> points1;
	points1.push_back(cv::Point(438, 210));  // 左上角
	points1.push_back(cv::Point(458, 210));   // 右上角（斜向右上）
	points1.push_back(cv::Point(458, 230));  // 右下角
	points1.push_back(cv::Point(438, 230));  // 左下角（斜向左下）
	fillPoints.push_back(points1);

	std::vector<cv::Point> points2;
	points2.push_back(cv::Point(246, 402));  // 左上角
	points2.push_back(cv::Point(266, 402));   // 右上角（斜向右上）
	points2.push_back(cv::Point(266, 422));  // 右下角
	points2.push_back(cv::Point(246, 422));  // 左下角（斜向左下）
	fillPoints.push_back(points2);

	std::vector<cv::Point> points3;
	points3.push_back(cv::Point(53, 210));  // 左上角
	points3.push_back(cv::Point(73, 210));   // 右上角（斜向右上）
	points3.push_back(cv::Point(73, 230));  // 右下角
	points3.push_back(cv::Point(53, 230));  // 左下角（斜向左下）
	fillPoints.push_back(points3);

	std::vector<cv::Point> points4;
	points4.push_back(cv::Point(166, 34));  // 左上角
	points4.push_back(cv::Point(186, 26));   // 右上角（斜向右上）
	points4.push_back(cv::Point(197, 47));  // 右下角
	points4.push_back(cv::Point(175, 56));  // 左下角（斜向左下）
	fillPoints.push_back(points4);

	std::vector<cv::Point> points5;
	points5.push_back(cv::Point(86, 100));  // 左上角
	points5.push_back(cv::Point(100, 81));   // 右上角（斜向右上）
	points5.push_back(cv::Point(120, 100));  // 右下角
	points5.push_back(cv::Point(105, 115));  // 左下角（斜向左下）
	fillPoints.push_back(points5);

	std::vector<cv::Point> points6;
	points6.push_back(cv::Point(86, 340));  // 左上角
	points6.push_back(cv::Point(104, 324));   // 右上角（斜向右上）
	points6.push_back(cv::Point(120, 340));  // 右下角
	points6.push_back(cv::Point(100, 355));  // 左下角（斜向左下）
	fillPoints.push_back(points6);

	std::vector<cv::Point> points7;
	points7.push_back(cv::Point(146, 400));  // 左上角
	points7.push_back(cv::Point(162, 378));   // 右上角（斜向右上）
	points7.push_back(cv::Point(181, 388));  // 右下角
	points7.push_back(cv::Point(160, 410));  // 左下角（斜向左下）
	fillPoints.push_back(points7);

	std::vector<cv::Point> points8;
	points8.push_back(cv::Point(333, 387));  // 左上角
	points8.push_back(cv::Point(355, 375));   // 右上角（斜向右上）
	points8.push_back(cv::Point(376, 396));  // 右下角
	points8.push_back(cv::Point(354, 409));  // 左下角（斜向左下）
	fillPoints.push_back(points8);

	std::vector<cv::Point> points9;
	points9.push_back(cv::Point(396, 330));  // 左上角
	points9.push_back(cv::Point(414, 315));   // 右上角（斜向右上）
	points9.push_back(cv::Point(436, 336));  // 右下角
	points9.push_back(cv::Point(422, 352));  // 左下角（斜向左下）
	fillPoints.push_back(points9);

	std::vector<cv::Point> points10;
	points10.push_back(cv::Point(423, 155));  // 左上角
	points10.push_back(cv::Point(444, 142));   // 右上角（斜向右上）
	points10.push_back(cv::Point(456, 166));  // 右下角
	points10.push_back(cv::Point(435, 177));  // 左下角（斜向左下）
	fillPoints.push_back(points10);

	std::vector<cv::Point> points11;
	points11.push_back(cv::Point(370, 81));  // 左上角
	points11.push_back(cv::Point(394, 62));   // 右上角（斜向右上）
	points11.push_back(cv::Point(412, 80));  // 右下角
	points11.push_back(cv::Point(388, 100));  // 左下角（斜向左下）
	fillPoints.push_back(points11);

	cv::fillPoly(image, fillPoints, color);
	cv::imshow("Taipei Tech", image);
	cv::imwrite("2_b.jpg", image);
	cv::waitKey(0);
	//return 0;

}