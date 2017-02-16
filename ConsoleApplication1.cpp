// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/*int main(int argc, char* argv[])
{
	VideoCapture cap("video.mp4"); // open the video file for reading
	VideoCapture capcam(0);

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video file" << endl;
		return -1;
	}

	//cap.set(CV_CAP_PROP_POS_MSEC, 300); //start the video at 300ms

	double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video
	double Width = capcam.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double Height = capcam.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Frame per seconds : " << fps << endl;

	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	while (1)
	{
		Mat frame, frame1;
		cap >> frame;
		capcam >> frame1;
		 //show the frame in "MyVideo" window
		for (int i = 0; i < Width; i++) {
			for (int j = 0; j < Height; j++) {
				frame.at<Vec3b>(j, i)[0] = frame1.at<Vec3b>(j, i)[0]; //B
				frame.at<Vec3b>(j, i)[1] = frame1.at<Vec3b>(j, i)[1];//G
				frame.at<Vec3b>(j, i)[2] = frame1.at<Vec3b>(j, i)[2];//R
			}
		}
		imshow("MyVideo", frame);

		if (waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}

	return 0;

}
*/
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	VideoCapture cap(0); // open the video camera no. 0

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video cam" << endl;
		return -1;
	}

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Frame size : " << dWidth << " x " << dHeight << endl;

	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	while (1)
	{
		Mat frame;

		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		imshow("MyVideo", frame); //show the frame in "MyVideo" window

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
	return 0;

}
/*
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	VideoCapture CapVideo("video .mp4");  // open the video file for reading
	if (!CapVideo.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video file" << endl;
		return -1;
	}
	VideoCapture CapCamera(0); 	        // open the video camera no. 0
	if (!CapCamera.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video cam" << endl;
		return -1;
	}

	//cap.set(CV_CAP_PROP_POS_MSEC, 300); //start the video at 300ms

	//double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

	//cout << "Frame per seconds : " << fps << endl;

	namedWindow("VideoWindow", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	while (1)
	{
		Mat frameVid,frameCam;

		bool bSuccess = CapVideo.read(frameVid); // read a new frame from video
		bool aSuccess = CapCamera.read(frameCam);

		if (!bSuccess || !aSuccess) 			 //if not success, break loop
		{
			cout << "Cannot read the frame from video file" << endl;
			break;
		}

		imshow("VideoWindow", frameVid); //show the frame in "MyVideo" window
		imshow("CameraWindow", frameCam);
	}

	return 0;

}*/

