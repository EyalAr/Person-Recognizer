/* 
 * File:   frames_reader.h
 * Author: Eyal Arubas <EyalArubas at gmail>
 */

#ifndef FRAMES_READER_H
#define	FRAMES_READER_H

#include <string>
#include "cv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

class FramesReader
{
public:
    FramesReader(const string &vidPath, int startFrame = -1, int endFrame = -1, int delta = -1);
    virtual ~FramesReader();
    bool getNext(Mat &frame);
    Size getSize();
private:
    VideoCapture _vid;
    int _endFrame,
        _delta;
};

#endif	/* FRAMES_READER_H */

