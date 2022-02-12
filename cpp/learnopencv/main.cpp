#include <iostream>
#include <chrono>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv)
{
    cv::Mat image = cv::imread(argv[1]);
    
    if (!image.data)
    {
        cerr<<"File "<<argv[1]<<" is not existed."<<endl;
        return 0;
    }
    
    cout<<"Image's Width is "<<image.cols<<", height is "<<image.rows<<", channel is "<<image.channels()<<endl;
    
    cv::imshow("image", image);
    
    cv::waitKey(0);
    
    cv::destroyAllWindows();
    
    return 0;
}
