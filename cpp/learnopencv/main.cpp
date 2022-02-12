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
    
    if (image.type() != CV_8UC1 && image.type() != CV_8UC3)
    {
        cout<<"Please input a colorful or gray picture."<<endl;
        
        return 0;
    }
    
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    
    for (size_t j = 0; j < image.rows; ++j)
    {
        for (size_t i = 0; i < image.cols; ++i)
        {
            unsigned char *row_ptr = image.ptr<unsigned char>(j);
            unsigned char *data_ptr = &row_ptr[j*image.channels()];
            
            for (int c = 0; c != image.channels(); ++c)
            {
                unsigned char data = data_ptr[c];
            }
        }        
    }
    
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> t_used = chrono::duration_cast<chrono::duration<double>>(t2-t1);
    cout<<"Read image used: "<<t_used.count()<<" second."<<endl;
    
    cv::destroyAllWindows();
    
    return 0;
}
