#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"
#include "opencv/cv.hpp"
#include <iostream>
#include "laneDetector.h"

using namespace std;

int main() {
	//
	// Variables 
	cv::Mat originalFrame; // ���󿡼� �޴� ���� ������
	char videoName[100] = "C:\\Users\\user\\source\\repos\\AutonomousCar\\AutonomousCarLaneDectection\\video\\test1.mpg"; // ���� ���� �̸�
	cv::VideoCapture capture(videoName); // object for capturing video

	while (true) {
		// ������ ����� ������ ���� ��� ����
		if (!capture.read(originalFrame)) {
			printf("File not read properly.....");
			return 0;
		}

		cv::Mat roiFrame[ROI_NUM];
		cv::Mat test;


		LaneDetector laneDetector = LaneDetector(originalFrame);
		laneDetector.preprocess();

		imshow("Original Frame", originalFrame);
		imshow("Gray scale Frame", laneDetector.processFrame);

		cv::waitKey(33);
	}


}