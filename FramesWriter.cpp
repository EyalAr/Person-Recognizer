/* 
 * File:   FramesWriter.cpp
 * Author: Eyal Arubas <EyalArubas at gmail>
 */

#include "FramesWriter.h"

FramesWriter::FramesWriter(const string vidPath, double fps, Size size, int fourcc): _f_size(size){
    _vid.open(
        vidPath,
        fourcc,
        fps,
        _f_size,
        true
    );
}

void FramesWriter::write(Mat& frame) {
    _vid << frame;
}

FramesWriter::~FramesWriter() {
    _vid.release();
}

