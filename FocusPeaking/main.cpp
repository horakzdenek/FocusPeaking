#include <iostream>
#include <thread>
#include <opencv2/opencv.hpp>
#include "../MojeCV.hpp"

using namespace std;
using namespace cv;


int main(int argc, char *argv[])
{
    if(!(argc >= 2)) return EXIT_FAILURE;
    string filename = argv[1];

    Mat frame = imread(filename);
    imshow("zdroj",frame);

    Mat edges;
    Canny(frame,edges,90,110,3);
    imshow("edges",edges);

    cvtColor(edges,edges,CV_GRAY2BGR);

    Mat dst;
    dst = MOJECV::lighten(frame,edges);
    imshow("dst",dst);
    waitKey(0);
    return 0;



}
