/* 
 * File:   FaceDetector.h
 * Author: Eyal Arubas <EyalArubas at gmail>
 */

#ifndef FACEDETECTOR_H
#define	FACEDETECTOR_H

#include <string>
#include "cv.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

class FaceDetector {
public:
    FaceDetector(
            const string &cascadePath,
            double scaleFactor,
            int    minNeighbors,
            double minSizeRatio,
            double maxSizeRatio);
    virtual ~FaceDetector();
    void findFacesInImage(const Mat &img, vector<Rect> &res);
private:
    CascadeClassifier _cascade;
    double _scaleFactor;
    int    _minNeighbors;
    double _minSizeRatio;
    double _maxSizeRatio;
};

#endif	/* FACEDETECTOR_H */

