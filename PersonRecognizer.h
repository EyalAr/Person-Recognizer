/* 
 * File:   PersonRecognizer.h
 * Author: Eyal Arubas <EyalArubas at gmail>
 */

#ifndef PERSONRECOGNIZER_H
#define	PERSONRECOGNIZER_H

#define PERSON_LABEL_A 10
#define PERSON_LABEL_B 11

#include <string>
#include "cv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/contrib/contrib.hpp"

using namespace std;
using namespace cv;

class PersonRecognizer {
public:
    PersonRecognizer(const vector<Mat> &imgs);
    virtual ~PersonRecognizer();
    bool recognize(const Mat &face, double &confidence) const;
private:
    Ptr<FaceRecognizer> _model;
    Size _faceSize;
};

#endif	/* PERSONRECOGNIZER_H */

