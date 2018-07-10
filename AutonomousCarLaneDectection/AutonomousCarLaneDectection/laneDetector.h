#pragma once

#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"
#include "opencv/cv.hpp"

// sub ROI에 대한 정보
#define ROI_LEVEL1 0
#define ROI_LEVEL2 1
#define ROI_LEVEL3 2
#define ROI_LEVEL4 3
//#define ROI_LEVEL_F 4
#define ROI_NUM 4

// 영상의 sub ROI 설정에 관한 좌표: 위쪽에서 아래쪽으로 ROI1 ~4 
#define UPPER_LEFT_1  cv::Point(upperLeft.x, upperLeft.y)
#define LOWER_RIGHT_1  cv::Point(lowerRight.x, upperLeft.y + height * 1/6) // blue
#define UPPER_LEFT_2  cv::Point(upperLeft.x, upperLeft.y + height * 1/6)
#define LOWER_RIGHT_2  cv::Point(lowerRight.x, upperLeft.y + height * 2/6) // green
#define UPPER_LEFT_3 cv::Point(upperLeft.x,  upperLeft.y + height * 2/6)
#define LOWER_RIGHT_3  cv::Point(lowerRight.x, upperLeft.y + height * 3/6) // red
#define UPPER_LEFT_4 cv::Point(upperLeft.x, upperLeft.y + height * 3/6)
#define LOWER_RIGHT_4  cv::Point(lowerRight.x, lowerRight.y) // red

//cv::Point upperLeft; // ROI 왼쪽 위 Point
//cv::Point lowerRight; // ROI 오른쪽 아래 Point

#ifndef _LANE_DETECTOR__
#define _LANE_DETECTOR__
using namespace std;

class LaneDetector {
public:
	cv::Mat originalFrame;
	/*
	Mat 구조체 사용을 줄여 메모리 공간을 절약하기 위해
	중간에 영상처리를 위해 사용되는 프레임을 processFrame이라는
	하나의 구조체 공간만을 사용한다.
	*/
	cv::Mat processFrame;
	cv::Mat roiFrame[ROI_NUM];

public:
	LaneDetector(cv::Mat &frame) {
		originalFrame = frame;
		// subRoi frame 초기화
		cv::Point upperLeft = cv::Point(0, frame.rows * 3 / 5);
		cv::Point  lowerRight = cv::Point(frame.cols, frame.rows * 9 / 10);
		int height = abs(lowerRight.y - upperLeft.y);
		roiFrame[ROI_LEVEL1] = frame(cv::Rect(UPPER_LEFT_1, LOWER_RIGHT_1));
		roiFrame[ROI_LEVEL2] = frame(cv::Rect(UPPER_LEFT_2, LOWER_RIGHT_2));
		roiFrame[ROI_LEVEL3] = frame(cv::Rect(UPPER_LEFT_3, LOWER_RIGHT_3));
		roiFrame[ROI_LEVEL4] = frame(cv::Rect(UPPER_LEFT_4, LOWER_RIGHT_4));

	}

	void preprocess(); // grayscale로 변환 & subRoi로 frame 분할
	void ransac(); // 선검출을 위한 RANSAC 알고리즘
	void otsu();
};

#endif
