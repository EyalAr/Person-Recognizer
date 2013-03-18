/* 
 * File:   frames_reader.cpp
 * Author: Eyal Arubas <EyalArubas at gmail>
 */

#include "FramesReader.h"

FramesReader::FramesReader(const string &vidPath, int startFrame, int endFrame, int delta):
_endFrame(endFrame), _delta(delta) {
    _vid.open(vidPath);
    if (startFrame != -1) _vid.set(CV_CAP_PROP_POS_FRAMES, startFrame);
}

bool FramesReader::getNext(Mat &img) {
    if (_delta != -1)
        _vid.set(CV_CAP_PROP_POS_FRAMES, _vid.get(CV_CAP_PROP_POS_FRAMES) + _delta);
    if (_endFrame != -1 && _vid.get(CV_CAP_PROP_POS_FRAMES) > _endFrame)
        return false;
    return _vid.read(img);
}

FramesReader::~FramesReader() {
    _vid.release();
}

Size FramesReader::getSize() {
    return Size(
                _vid.get(CV_CAP_PROP_FRAME_WIDTH),
                _vid.get(CV_CAP_PROP_FRAME_HEIGHT)
            );
}
