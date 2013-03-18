/* 
 * File:   PersonRecognizer.cpp
 * Author: Eyal Arubas <EyalArubas at gmail>
 */

#include "PersonRecognizer.h"

PersonRecognizer::PersonRecognizer(const vector<Mat> &imgs) {
    //all images are faces of the same person, so the same label for all.
    vector<int> labels(imgs.size());
    for (vector<int>::iterator it = labels.begin() ; it != labels.end() ; *(it++) = PERSON_LABEL_A);
    //labels[0] = PERSON_LABEL_B;
    //create and train the model:
    //_model = createFisherFaceRecognizer(0,5.0);
    //_model = createEigenFaceRecognizer(0,4900.0);
    _model = createLBPHFaceRecognizer(3,8,8,8,180);
    _model->train(imgs, labels);
    _faceSize = Size(imgs[0].size().width, imgs[0].size().height);
}

PersonRecognizer::~PersonRecognizer() {}

bool PersonRecognizer::recognize(const Mat &face, double &confidence) const {
    Mat gray;
    int label;
    cvtColor(face, gray, CV_BGR2GRAY);
    resize(gray, gray, _faceSize);
    _model->predict(gray, label, confidence);
    //return label == PERSON_LABEL ? confidence : 0;
    return label == PERSON_LABEL_A || label == PERSON_LABEL_B ? true : false;
}