#include <opencv2/opencv.hpp>
#include <iostream>
#include <raspicam/raspicam_cv.h>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

void load_cascade(CascadeClassifier& cascade, string fname)
{
	String path = "/home/pi/opencv/opencv-3.2.0/data/haarcascades/";
	String full_name = path + fname;

	CV_Assert(cascade.load(full_name));
}

Mat preprocessing(Mat image)
{
	Mat gray;
	cvtColor(image, gray, CV_BGR2GRAY);
	equalizeHist(gray, gray);

	return gray;
}

Point2d calc_center(Rect obj)
{
	Point2d c = (Point2d)obj.size()/2.0;
	Point2d center = (Point2d)obj.tl() +c;
	return center;

}

int main(int argc, char**argv)
{
	raspicam::RaspiCam_Cv Camera;
	Mat image;

	Camera.set( CV_CAP_PROP_FORMAT, CV_8UC3);
	Camera.set( CV_CAP_PROP_FRAME_WIDTH, 640);
	Camera.set( CV_CAP_PROP_FRAME_HEIGHT, 480);

	CascadeClassifier face_cascade;
	load_cascade(face_cascade, "haarcascade_frontalface_alt2.xml");

	if(!Camera.open())
	{
		cerr<<"Error opening the camera"<<endl;
			return -1;
	}

	while(1)
	{
		Camera.grab();
		Camera.retrieve(image);
		Mat gray = preprocessing(image);
		CV_Assert(image.data);

		vector<Rect> faces;
		face_cascade.detectMultiScale(gray, faces, 1.1, 2, 0, Size(100,100));
		
		if(&faces[0] != 0)
		{
			rectangle(image, facses[0], Scalar(255,0,0), 2);
			imshow("picamera test", image);
			if(waitKey(20) == 27)
				break;
		}
	}
	Camera.release();
	return 0;
}
