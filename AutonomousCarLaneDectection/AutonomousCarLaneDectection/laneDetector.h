#pragma once

#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"
#include "opencv/cv.hpp"

// sub ROI�� ���� ����
#define ROI_LEVEL1 0
#define ROI_LEVEL2 1
#define ROI_LEVEL3 2
#define ROI_LEVEL4 3
//#define ROI_LEVEL_F 4
#define ROI_NUM 4

// ������ sub ROI ������ ���� ��ǥ: ���ʿ��� �Ʒ������� ROI1 ~4 
#define UPPER_LEFT_1  cv::Point(upperLeft.x, upperLeft.y)
#define LOWER_RIGHT_1  cv::Point(lowerRight.x, upperLeft.y + height * 1/6) // blue
#define UPPER_LEFT_2  cv::Point(upperLeft.x, upperLeft.y + height * 1/6)
#define LOWER_RIGHT_2  cv::Point(lowerRight.x, upperLeft.y + height * 2/6) // green
#define UPPER_LEFT_3 cv::Point(upperLeft.x,  upperLeft.y + height * 2/6)
#define LOWER_RIGHT_3  cv::Point(lowerRight.x, upperLeft.y + height * 3/6) // red
#define UPPER_LEFT_4 cv::Point(upperLeft.x, upperLeft.y + height * 3/6)
#define LOWER_RIGHT_4  cv::Point(lowerRight.x, lowerRight.y) // red

//cv::Point upperLeft; // ROI ���� �� Point
//cv::Point lowerRight; // ROI ������ �Ʒ� Point

#ifndef _LANE_DETECTOR__
#define _LANE_DETECTOR__
using namespace std;

class LaneDetector {
public:
	cv::Mat originalFrame;
	/*
	Mat ����ü ����� �ٿ� �޸� ������ �����ϱ� ����
	�߰��� ����ó���� ���� ���Ǵ� �������� processFrame�̶��
	�ϳ��� ����ü �������� ����Ѵ�.
	*/
	cv::Mat processFrame;
	cv::Mat roiFrame[ROI_NUM];

public:
	LaneDetector(cv::Mat &frame) {
		originalFrame = frame;
		// subRoi frame �ʱ�ȭ
		cv::Point upperLeft = cv::Point(0, frame.rows * 3 / 5);
		cv::Point  lowerRight = cv::Point(frame.cols, frame.rows * 9 / 10);
		int height = abs(lowerRight.y - upperLeft.y);
		roiFrame[ROI_LEVEL1] = frame(cv::Rect(UPPER_LEFT_1, LOWER_RIGHT_1));
		roiFrame[ROI_LEVEL2] = frame(cv::Rect(UPPER_LEFT_2, LOWER_RIGHT_2));
		roiFrame[ROI_LEVEL3] = frame(cv::Rect(UPPER_LEFT_3, LOWER_RIGHT_3));
		roiFrame[ROI_LEVEL4] = frame(cv::Rect(UPPER_LEFT_4, LOWER_RIGHT_4));

	}

	void preprocess(); // grayscale�� ��ȯ & subRoi�� frame ����
	void ransac(); // �������� ���� RANSAC �˰���
	void otsu();
};

#endif
