/* 
 * File:   FramesWriter.h
 * Author: Eyal Arubas <EyalArubas at gmail>
 */

#ifndef FRAMESWRITER_H
#define	FRAMESWRITER_H

#include <string>
#include "cv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

class FramesWriter
{
public:
    FramesWriter(const string vidPath, double fps, Size size, int fourcc);
    virtual ~FramesWriter();
    void write(Mat &frame);
private:
    VideoWriter _vid;
    Size _f_size;
};

#endif	/* FRAMESWRITER_H */

