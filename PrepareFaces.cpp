/* 
 * File:   PrepareFaces.cpp
 * Author: Eyal Arubas <EyalArubas at gmail>
 */

#define DEFAULT_CASCADE_PATH "cascades/haarcascade_frontalface_default.xml"
#define ORIGINALS_LIST "obama_raw/list"
#define OUTPUT_DIR "obama_faces"
#define OUTPUT_LIST "list"
#define FACE_SIZE Size(150,150)

#include <cstdlib>
#include <fstream>
#include "cv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "FaceDetector.h"

using namespace std;
using namespace cv;

void read_input_list(const string &list_path, vector<Mat> &images) {
    ifstream file(list_path.c_str());
    string path;
    while (getline(file, path)) {
        images.push_back(imread(path));
    }
}

int main(int argc, char** argv) {
    FaceDetector fd(string(DEFAULT_CASCADE_PATH));
    vector<Mat> raw_faces;
    ofstream out_list(format("%s/%s", OUTPUT_DIR, OUTPUT_LIST).c_str());
    read_input_list(string(ORIGINALS_LIST), raw_faces);
    int img_c = 0; //images counter
    
    //now detect the faces in each of the raw images:
    for (vector<Mat>::const_iterator raw_img = raw_faces.begin() ; raw_img != raw_faces.end() ; raw_img++){
        vector<Rect> faces;
        //detect faces in the image (there should be only one):
        fd.findFacesInImage(*raw_img, faces);
        
        //cut each face and write to disk:
        for (vector<Rect>::const_iterator face = faces.begin() ; face != faces.end() ; face++){
            int edge_size = max(face->width, face->height);
            Rect square(face->x, face->y, edge_size, edge_size);
            Mat face_img = (*raw_img)(square);
            
            //resize:
            resize(face_img, face_img, FACE_SIZE);
            
            //write to disk:
            string face_path = format("%s/%d.jpg", OUTPUT_DIR, img_c++);
            imwrite(face_path,face_img);
            out_list << face_path << endl;
        }
    }
    out_list.close();
    return 0;
}

