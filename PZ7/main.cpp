#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int threshold_value = 240;
int threshold_type = 0;
int const max_binary_value = 255;

int main() {
    VideoCapture cap("../video_output.mp4"); // open the video file for reading
    bool flag_p = false;
    Point p_old;
    

    if ( !cap.isOpened() ) return -1;

    Mat draw_frame, frame;
    cap.read(draw_frame);
    draw_frame.setTo(cv::Scalar(0, 0, 0));
    
    double fps = cap.get(CAP_PROP_FPS);     //get the FPS of the video
     std::cout << "Frame per seconds : " << fps << std::endl;
    namedWindow("MyVideo",WINDOW_AUTOSIZE); //create a window "MyVideo"
    
    while(cap.isOpened()) {
        Mat grey, frame_out, dr_frame;

        
        if(!cap.read(frame)) break;

        cvtColor(frame, grey, COLOR_RGB2GRAY);
        threshold(grey, frame_out, threshold_value, max_binary_value, threshold_type );

        Moments m = moments(frame_out,true);
        Point p(m.m10/m.m00, m.m01/m.m00);
        if(p.x > 0 && p.y > 0 && p_old.x > 0 && p_old.y > 0) line(draw_frame, p, p_old, Scalar(10,128,0), 2);
        p_old = p;

        
        frame_out = frame + draw_frame;
        imshow("MyVideo", frame_out); //show the frame in "MyVideo" window
        if(waitKey(30) == 27) {
            break; 
       }
    }
    imwrite("../result.png", draw_frame);
}