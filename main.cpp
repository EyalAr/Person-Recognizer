/* 
 * File:   main.cpp
 * Author: Eyal Arubas <EyalArubas at gmail>
 */

/** Includes: **/
#include <cstdlib>
#include "defs.h"
#include "FramesReader.h"
#include "FramesWriter.h"
#include "CsvWriter.h"
#include "FaceDetector.h"
#include "PersonRecognizer.h"

using namespace std;

void read_training_set(const string &list_path, vector<Mat> &images) {
    ifstream file(list_path.c_str());
    string path;
    while (getline(file, path)) {
        images.push_back(imread(path, CV_LOAD_IMAGE_GRAYSCALE));
    }
}

int main(int argc, char** argv) {
    
    /** Initializations: **/
    
    FramesReader fr(string(IN_VID), START_FRAME, END_FRAME, FRAMES_DELTA);
    Size         frame_size(fr.getSize()); //frame size of the input video
    FaceDetector fd(string(CASCADE_PATH), DET_SCALE_FACTOR, DET_MIN_NEIGHBORS, DET_MIN_SIZE_RATIO, DET_MAX_SIZE_RATIO);
    vector<Mat>  training_set;
    vector<Rect> faces;
    Mat          m;
    int          c = START_FRAME == -1 ? 0 : START_FRAME - 1;
    
    #ifdef WRITE_OUTPUT
        FramesWriter fw(string(OUT_VID), OUT_FPS, frame_size, OUT_FOURCC);
    #endif
    #ifdef WRITE_CSV
        CsvWriter cw(string(CSV_FILE));
    #endif
    
    read_training_set(string(TRAINING_LIST), training_set);
    
    PersonRecognizer pr(training_set, LBPH_RADIUS, LBPH_NEIGHBORS, LBPH_GRID_X, LBPH_GRID_Y, LBPH_THRESHOLD);
    
    /**********************/
    
    while (fr.getNext(m)){
        c++;
        
        #ifdef WRITE_OUTPUT
            cw.addEntry(format("%d", c)); //write frame number
        #endif
        
        //detect faces in the image:
        fd.findFacesInImage(m, faces);
        
        bool has_match = false;
        double match_conf = 0;
        
        //analyze each detected face:
        for (vector<Rect>::const_iterator face = faces.begin() ; face != faces.end() ; face++){
            Scalar color = NO_MATCH_COLOR;
            Mat face_img = m(*face);
            double confidence = 0;
            bool face_match = false;
            
            //try to recognize the face:
            if (pr.recognize(face_img, confidence)){
                color = MATCH_COLOR;
                has_match = true;
                face_match = true;
                match_conf = confidence;
            }
            
            Point center(face->x + face->width * 0.5, face->y + face->height * 0.5);
            circle(m, center, FACE_RADIUS_RATIO * face->width, color, CIRCLE_THICKNESS, LINE_TYPE, 0);
            
            #ifdef WRITE_OUTPUT
                cw.addEntry(format("%f", face_match ? confidence : 0)); //write confidence of current face
            #endif
        }

        #ifdef WRITE_OUTPUT
            cw.nextLine();
        #endif
        
        //write some information on the frame:
        putText(m, "Face recognition demo (frontal)", POS_TITLE,
                FONT, SCALE_TITLE, FONT_COLOR, THICKNESS_TITLE, LINE_TYPE);
        putText(m, "http://blog.eyalarubas.com/category/opencv/", POS_LINK,
                FONT, SCALE_LINK, FONT_COLOR, THICKNESS_LINK, LINE_TYPE);
        putText(m, format("Frame: %d", c), cvPoint(10, m.rows - 105),
                FONT, 2, FONT_COLOR, 1, LINE_TYPE);
        putText(m, format("FPS: %d", 15), cvPoint(10, m.rows - 80),
                FONT, 2, FONT_COLOR, 1, LINE_TYPE);
        putText(m, format("Faces: %d", faces.size()), cvPoint(10, m.rows - 55),
                FONT, 2, FONT_COLOR, 1, LINE_TYPE);
        putText(m, format("Match: %s", has_match ? "True" : "False"), cvPoint(10, m.rows - 30),
                FONT, 2, FONT_COLOR, 1, LINE_TYPE);
        putText(m, format("Confidence: %f", has_match ? match_conf : 0), cvPoint(10, m.rows - 5),
                FONT, 2, FONT_COLOR, 1, LINE_TYPE);
        
        #ifdef SHOW_OUTPUT
            imshow("Output",m);
            if ('x' == waitKey(1)){
                return 0;
            }
        #endif
        #ifdef WRITE_OUTPUT
            fw.write(m);
        #endif
    }
    
    return 0;
}

