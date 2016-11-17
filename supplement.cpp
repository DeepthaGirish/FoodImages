// FoodImages
//Counts amount/ area occupied by a particular ingredient in a bowl

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <string>
#include<conio.h>
#include <opencv/cv.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"
#include <fstream>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <vector>
#include <time.h>




using namespace cv;
using namespace std;
void AreaGreenPepper(Mat img)
{
	vector<vector<Point>> gcontours;
	vector<Vec4i> ghierarchy;
	Mat thresh;
	cv::inRange(img, cv::Scalar(5, 50, 50), cv::Scalar(110, 150, 120), thresh);//Green Pepper
	std::ostringstream str;
	findContours(thresh, gcontours, ghierarchy, CV_RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < gcontours.size(); i++)
	{
		if (fabs(contourArea(gcontours[i])) > 1000)
		{
			str << "" << (fabs(contourArea(gcontours[i])) * 100) / (img.rows*img.cols) <<"%";
			putText(img, str.str(), gcontours[i][1], FONT_HERSHEY_PLAIN, 2.0, CV_RGB(0, 0, 0), 2.0);
			//drawContours(img, gcontours, i, Scalar(128, 0, 255), cv::FILLED, cv::LINE_8, vector<Vec4i>(), 0, Point());
			drawContours(img, gcontours, i, Scalar(0, 0, 0), 2, cv::LINE_8, vector<Vec4i>(), 0, Point());
		}
	}

	imwrite("FoodImages/1_result.jpg", img);
	imshow("ïmg", img);

}
void countSausages(Mat &disp, Mat img)
{
	int sausagecount = 0;
	vector<vector<Point>> scontours;
	vector<Vec4i> shierarchy;
	Mat thresh;
	cv::inRange(img, cv::Scalar(140, 20, 50), cv::Scalar(250, 85, 250), thresh);//Sausages
	erode(thresh, thresh, Mat());
	dilate(thresh, thresh, Mat());
	dilate(thresh, thresh, Mat());
	findContours(thresh, scontours, shierarchy, CV_RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < scontours.size(); i++)
	{
		std::ostringstream str;
		if (fabs(contourArea(scontours[i])) > 1000)
		{
			str.clear();
			sausagecount++;
			//drawContours(disp, scontours, i, Scalar(0,0,0), 2, cv::LINE_8, vector<Vec4i>(), 0, Point());
			str << "" << sausagecount;
			putText(disp, str.str(), scontours[i][70], FONT_HERSHEY_PLAIN, 2.0, CV_RGB(0, 0, 0), 2.0);
		}
	}
	cout << "Number of Sausages : " << sausagecount << endl;
	imshow("ïmg", disp);

}

void areaspinach(Mat img)
{
	vector<vector<Point>> gcontours;
	vector<Vec4i> ghierarchy;
	Mat thresh;
	cv::inRange(img, cv::Scalar(25, 30, 50), cv::Scalar(110, 150, 180), thresh);//Green Pepper
	std::ostringstream str;
	findContours(thresh, gcontours, ghierarchy, CV_RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < gcontours.size(); i++)
	{
		if (fabs(contourArea(gcontours[i])) > 5000)
		{
			str << "" << (fabs(contourArea(gcontours[i])) * 100) / (img.rows*img.cols)<<"%";
			putText(img, str.str(), gcontours[i][1], FONT_HERSHEY_PLAIN, 2.0, CV_RGB(0, 0, 0), 2.0);
			//drawContours(img, gcontours, i, Scalar(128, 0, 255), cv::FILLED, cv::LINE_8, vector<Vec4i>(), 0, Point());
			drawContours(img, gcontours, i, Scalar(0, 0, 0), 2, cv::LINE_8, vector<Vec4i>(), 0, Point());
		}
	}
	imwrite("FoodImages/3_paresult.jpg", img);
	imshow("ïmg", img);

}


void countbacon(Mat &disp, Mat img)
{
	int baconcount = 0;
	vector<vector<Point>> econtours;
	vector<Vec4i> ehierarchy;
	Mat thresh;
	//cv::inRange(img, cv::Scalar(140, 40, 30), cv::Scalar(250, 120, 255), thresh);//Sausages
	cv::inRange(img, cv::Scalar(140, 40, 1), cv::Scalar(250, 250, 255), thresh);//Sausages
	findContours(thresh, econtours, ehierarchy, CV_RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < econtours.size(); i++)
	{
		std::ostringstream str;
		if (fabs(contourArea(econtours[i])) >1000)
		{
			str.clear();
			baconcount++;
			//drawContours(disp, econtours, i, Scalar(0, 0, 0), 2, cv::LINE_8, vector<Vec4i>(), 0, Point());
			str << "" << baconcount;
			putText(disp, str.str(), econtours[i][30], FONT_HERSHEY_PLAIN, 2.0, CV_RGB(0, 0, 0), 2.0);
		}
	}
	imshow("img", disp);
}

/*void countbacon(Mat org,Mat disp, Mat img)
{
	int baconcount = 0;
	vector<vector<Point>> econtours;
	vector<Vec4i> ehierarchy;
	Mat thresh;
	//cv::inRange(img, cv::Scalar(140, 40, 30), cv::Scalar(250, 120, 255), thresh);//Sausages
	cv::inRange(img, cv::Scalar(140, 40, 1), cv::Scalar(200, 150, 255), thresh);//Sausages
	findContours(thresh, econtours, ehierarchy, CV_RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < econtours.size(); i++)
	{
		std::ostringstream str;
		if (fabs(contourArea(econtours[i])) >1400)
		{
			str.clear();
			baconcount++;
			//drawContours(org, econtours, i, Scalar(0, 0, 0), 2, cv::LINE_8, vector<Vec4i>(), 0, Point());
			str << "" << baconcount;
			putText(org, str.str(), econtours[i][50], FONT_HERSHEY_PLAIN, 2.0, CV_RGB(0, 0, 0), 2.0);
		}
	}
	imwrite("foodImages/4_result.jpg", org);
}*/

void countbrocolli(Mat &img)
{
	int brocollicount = 0;
	vector<vector<Point>> econtours;
	vector<Vec4i> ehierarchy;
	Mat thresh;
	//cv::inRange(img, cv::Scalar(140, 40, 30), cv::Scalar(250, 120, 255), thresh);//Sausages
	cv::inRange(img, cv::Scalar(20, 80, 70), cv::Scalar(50, 150, 170), thresh);
	dilate(thresh, thresh, Mat());
	erode(thresh, thresh, Mat());
	findContours(thresh, econtours, ehierarchy, CV_RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < econtours.size(); i++)
	{
		std::ostringstream str;
		if (fabs(contourArea(econtours[i])) >400)
		{
			str.clear();
			brocollicount++;
			drawContours(img, econtours, i, Scalar(0, 0, 0), 2, cv::LINE_8, vector<Vec4i>(), 0, Point());
			str << "" << brocollicount;
			putText(img, str.str(), econtours[i][100], FONT_HERSHEY_PLAIN, 2.0, CV_RGB(255, 0, 0), 2.0);
		}
	}
	//imshow("img", img);
}


void main()
{
	clock_t tStart = clock();
	Mat img = imread("FoodImages/3.jpg");
	Mat imged = imread("FoodImages/3_ed.jpg");
	Mat imgHSV, thresh;
	cvtColor(imged, imgHSV, CV_BGR2HSV);
	
	//cv::inRange(imgHSV, cv::Scalar(140, 40, 1), cv::Scalar(250, 150, 255), thresh);
	//imwrite("imgmat.jpg", thresh);
	
	countbacon(img, imgHSV);
	areaspinach(img);

	//countbacon(img, imged, imgHSV);
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	waitKey(0);
	
}
