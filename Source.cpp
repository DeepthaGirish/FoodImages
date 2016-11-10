// FoodImages
//Counts amount/ area occupied by a particular ingredient in a bowl

#include "opencv2/opencv.hpp"
#include <fstream>
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace cv;
using namespace std;

const int maxarea = 1000;


void colorspace(Mat img)
{
	Mat imgHSV, imgHLS, imgLAB, imgLUV, imgYcb, imgHLSF;
	cvtColor(img, imgHSV, CV_BGR2HSV);
	cvtColor(img, imgHLS, CV_BGR2HLS);
	cvtColor(img, imgLAB, CV_BGR2Lab);
	cvtColor(img, imgLUV, CV_BGR2Luv);
	cvtColor(img, imgHLSF, CV_BGR2HLS_FULL);
	cvtColor(img, imgYcb,CV_BGR2YUV);
	imwrite("Z_HSV.png", imgHSV);
	imwrite("Z_HLS.png", imgHLS);
	imwrite("Z_Lab.png", imgLAB);
	imwrite("Z_Luv.png", imgLUV);
	imwrite("Z_HLSF.png", imgHLSF);
	imwrite("Z_Ycb.png", imgYcb);
}





void countSausages(Mat &disp,Mat img)
{
	int sausagecount = 0;
	vector<vector<Point>> scontours;
	vector<Vec4i> shierarchy;
	Mat thresh;
	cv::inRange(img, cv::Scalar(140,20,50), cv::Scalar(250, 85, 250), thresh);//Sausages
	erode(thresh, thresh, Mat());
	dilate(thresh, thresh, Mat());
	dilate(thresh, thresh, Mat());
	findContours(thresh, scontours, shierarchy, CV_RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < scontours.size(); i++)
	{
		std::ostringstream str;
		if (fabs(contourArea(scontours[i])) > maxarea)
		{
			str.clear();
			sausagecount++;
			//drawContours(disp, scontours, i, Scalar(0,0,0), 2, cv::LINE_8, vector<Vec4i>(), 0, Point());
			str << "" << sausagecount;
			putText(disp, str.str(), scontours[i][70], FONT_HERSHEY_PLAIN, 2.0, CV_RGB(0, 0,0), 2.0);
		}
	}
	cout << "Number of Sausages : " << sausagecount<< endl;	
	imshow("ïmg", disp);

}



void AreaGreenPepper(Mat img)
{
	vector<vector<Point>> gcontours;
	vector<Vec4i> ghierarchy;
	Mat thresh;
	cv::inRange(img, cv::Scalar(5,50,50), cv::Scalar(110, 150, 120), thresh);//Green Pepper
	std::ostringstream str;
	findContours(thresh, gcontours, ghierarchy, CV_RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < gcontours.size(); i++)
	{
		if (fabs(contourArea(gcontours[i])) > maxarea)
		{
			str << "" << (fabs(contourArea(gcontours[i]))*100)/(img.rows*img.cols);
			putText(img, str.str(), gcontours[i][1], FONT_HERSHEY_PLAIN, 2.0, CV_RGB(0, 0, 0), 2.0);
			//drawContours(img, gcontours, i, Scalar(128, 0, 255), cv::FILLED, cv::LINE_8, vector<Vec4i>(), 0, Point());
			drawContours(img, gcontours, i, Scalar(0,0,0), 2, cv::LINE_8, vector<Vec4i>(), 0, Point());
		}
	}
		
	imwrite("FoodImages/1_result.jpg", img);
	imshow("ïmg",img);
	
}



void counteggplant(Mat disp, Mat img)
{
	int eggplantcount = 0;
	vector<vector<Point>> econtours;
	vector<Vec4i> ehierarchy;
	Mat thresh;
	cv::inRange(img, cv::Scalar(20, 130, 110), cv::Scalar(40, 145, 135), thresh);//Egg Plant
	findContours(thresh, econtours,ehierarchy, CV_RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < econtours.size(); i++)
	{
		std::ostringstream str;
		if (fabs(contourArea(econtours[i])) >300)
		{
			str.clear();
			eggplantcount++;
			//drawContours(disp, econtours, i, Scalar(0,0,0), 2, cv::LINE_8, vector<Vec4i>(), 0, Point());
			str << "" << eggplantcount;
			putText(disp, str.str(), econtours[i][90], FONT_HERSHEY_PLAIN, 2.0, CV_RGB(255, 0, 125), 2.0);
		}
	}
	imwrite("FoodImages/2_result.jpg", disp);
	imshow("img", disp);
}

void countbacon(Mat disp,Mat img)
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
		if (fabs(contourArea(econtours[i])) >maxarea)
		{
			str.clear();
			baconcount++;
			drawContours(disp, econtours, i, Scalar(0,0,0), 2, cv::LINE_8, vector<Vec4i>(), 0, Point());
			str << "" << baconcount;
			putText(disp, str.str(), econtours[i][80], FONT_HERSHEY_PLAIN, 2.0, CV_RGB(0,0,0), 2.0);
		}
	}
	imshow("img", disp);
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
			str << "" << (fabs(contourArea(gcontours[i])) * 100) / (img.rows*img.cols);
			putText(img, str.str(), gcontours[i][1], FONT_HERSHEY_PLAIN, 2.0, CV_RGB(0, 0, 0), 2.0);
			//drawContours(img, gcontours, i, Scalar(128, 0, 255), cv::FILLED, cv::LINE_8, vector<Vec4i>(), 0, Point());
			drawContours(img, gcontours, i, Scalar(0, 0, 0), 2, cv::LINE_8, vector<Vec4i>(), 0, Point());
		}
	}
	imwrite("FoodImages/3_result.jpg", img);
	imshow("ïmg", img);

}
void main()
{

	Mat img = imread("FoodImages/4.jpg");
	//colorspace(img);
	Mat imgYUV, imgHSV;
	//cvtColor(img, imgYUV, CV_BGR2YUV);
	//counteggplant(img, imgYUV);
	cvtColor(img, imgHSV, CV_BGR2HSV);
	/*countSausages(img, imgHSV);
	AreaGreenPepper(img);*/
	countbacon(img,imgHSV);
	//areaspinach(img);
	waitKey(0);
}
