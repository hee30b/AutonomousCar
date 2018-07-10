#include "laneDetector.h"

void LaneDetector::ransac() {

}

void LaneDetector::preprocess() {
	// ������ ���� ������ �»�ܰ� ���ϴ� Point
	cv::Point upperLeft = cv::Point(0, originalFrame.rows * 3 / 5);
	cv::Point lowerRight = cv::Point(originalFrame.cols, originalFrame.rows * 9 / 10);

	// rgb => gray scale �������� ��ȯ
	cv::cvtColor(originalFrame, processFrame, cv::COLOR_BGR2GRAY);

	/*
	������ ���͸�
	cv::blur(image, result, cv::Size(5,5)) => �� ȭ���� ���� �簢�� �̿��� ��հ����� ��ġ�Ͽ� ������ �ε巴�� ��
	cv::GaussianBlur(image, result, cv::Size(5,5), 1.5)
	- ���� ���
	- Linear operation : does not preserve edges(sigma���� ���� smooothing�� edge �������� ������)
	cv::medianBlur(src, dst, int ksize)
	- non-linear filter: edge preserving
	cv::biateralFilter(src, dst, d, sigmaColor, sigmaSpace)

	*/

}

void otsu() {

}