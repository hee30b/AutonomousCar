#include "laneDetector.h"

void LaneDetector::ransac() {

}

void LaneDetector::preprocess() {
	// 영상의 관심 영역의 좌상단과 우하단 Point
	cv::Point upperLeft = cv::Point(0, originalFrame.rows * 3 / 5);
	cv::Point lowerRight = cv::Point(originalFrame.cols, originalFrame.rows * 9 / 10);

	// rgb => gray scale 영상으로 변환
	cv::cvtColor(originalFrame, processFrame, cv::COLOR_BGR2GRAY);

	/*
	저주파 필터링
	cv::blur(image, result, cv::Size(5,5)) => 각 화소의 값을 사각형 이웃의 평균값으로 대치하여 영상을 부드럽게 함
	cv::GaussianBlur(image, result, cv::Size(5,5), 1.5)
	- 가중 평균
	- Linear operation : does not preserve edges(sigma값에 따라 smooothing과 edge 보존도가 결정됨)
	cv::medianBlur(src, dst, int ksize)
	- non-linear filter: edge preserving
	cv::biateralFilter(src, dst, d, sigmaColor, sigmaSpace)

	*/

}

void otsu() {

}