#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <fstream>
#include <iostream>


using namespace std;
using namespace cv;

// Initialize parameters
int histSizeGray = 256;    // bin size
float range[] = { 0, 255 };
const float *rangesGray[] = { range };

int main(int argc, const char** argv)
{
	Mat src, dst;
	src = imread("C:\\mel01.jpg", CV_LOAD_IMAGE_COLOR); //open and read the image

	if (src.empty())
	{
		cout << "Image cannot be loaded..!!" << endl;
		return -1;
	}

	namedWindow("COLOR", CV_WINDOW_AUTOSIZE);
	imshow("COLOR", src);

	Mat img = imread("C:\\mel01.jpg", 0);
	namedWindow("GRAY", 1);    imshow("GRAY", img);

	/// Separate the image in 3 places ( B, G and R )
	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	/// Establish the number of bins
	int histSize = 256;

	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 };
	const float* ranges = { range };

	bool uniform = true; bool accumulate = false;

	Mat b_hist, g_hist, r_hist, hist;

	/// Compute the histograms:
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &ranges, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &ranges, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &ranges, uniform, accumulate);
	//compute the histograma gray:
	calcHist(&img, 1, 0, Mat(), hist, 1, &histSizeGray, rangesGray, true, false);

	// Show the calculated histogram (GRAY) in txt file
	ofstream outputFile;
	outputFile.open("mel01.txt");
	double total;
	total = img.rows * img.cols;
	for (int h = 0; h < histSize; h++)
	{
		float binVal = hist.at<float>(h);
		outputFile << "\n" << binVal;
	}

	// Show the calculated histogram(blue) in txt file
	ofstream outputBlue;
	outputBlue.open("b_mel01.txt");
	double b_total;
	b_total = src.rows * src.cols;
	for (int h = 0; h < histSize; h++)
	{
		float binVal = b_hist.at<float>(h);
		outputBlue << "\n" << binVal;
	}

	// Show the calculated histogram(green) in txt file
	ofstream outputGreen;
	outputGreen.open("g_mel01.txt");
	double g_total;
	g_total = src.rows * src.cols;
	for (int h = 0; h < histSize; h++)
	{
		float binVal = g_hist.at<float>(h);
		outputGreen << "\n" << binVal;
	}

	// Show the calculated histogram(red) in txt file
	ofstream outputRed;
	outputRed.open("r_mel01.txt");
	double r_total;
	r_total = src.rows * src.cols;
	for (int h = 0; h < histSize; h++)
	{
		float binVal = r_hist.at<float>(h);
		outputRed << "\n" << binVal;
	}

	// Plot the histogram GRAY input
	int hist_gray = 512; int hist_hG = 400;
	int bin_gray = cvRound((double)hist_gray / histSize);

	Mat histImageGray(hist_hG, hist_gray, CV_8UC1, Scalar(0, 0, 0));
	normalize(hist, hist, 0, histImageGray.rows, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < histSize; i++)
	{
		line(histImageGray, Point(bin_gray*(i - 1), hist_hG - cvRound(hist.at<float>(i - 1))),
			Point(bin_gray*(i), hist_hG - cvRound(hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
	}

	namedWindow("Result GRAY input", 1);    imshow("Result GRAY input", histImageGray);

	// Draw the histograms for B, G and R
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

	/// Normalize the result to [ 0, histImage.rows ]
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	/// Draw for each channel
	for (int i = 1; i < histSize; i++)
	{
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);
	}

	/// Display
	namedWindow("BGR planes", CV_WINDOW_AUTOSIZE);
	imshow("BGR planes", histImage);

	waitKey(0);

	return 0;
}