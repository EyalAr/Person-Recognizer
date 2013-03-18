/* 
 * File:   PersonRecognizer.cpp
 * Author: Eyal Arubas <EyalArubas at gmail>
 */

#include "PersonRecognizer.h"

PersonRecognizer::PersonRecognizer(const vector<Mat> &imgs, int radius, int neighbors,
        int grid_x, int grid_y, double threshold) {
    //all images are faces of the same person, so initialize the same label for all.
    vector<int> labels(imgs.size());
    for (vector<int>::iterator it = labels.begin() ; it != labels.end() ; *(it++) = PERSON_LABEL);
    _faceSize = Size(imgs[0].size().width, imgs[0].size().height);
    
    //build recognizer model:
    _model = createLBPHFaceRecognizer(radius, neighbors, grid_x, grid_y, threshold);
    _model->train(imgs, labels);
}

PersonRecognizer::~PersonRecognizer() {}

bool PersonRecognizer::recognize(const Mat &face, double &confidence) const {
    Mat gray;
    int label;
    cvtColor(face, gray, CV_BGR2GRAY);
    resize(gray, gray, _faceSize);
    _model->predict(gray, label, confidence);
    return label == PERSON_LABEL ? true : false;
}