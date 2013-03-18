/* 
 * File:   defs.h
 * Author: Eyal Arubas <EyalArubas at gmail>
 */

#ifndef DEFS_H
#define	DEFS_H

/** Flags: **/
#define SHOW_OUTPUT
#define WRITE_OUTPUT
#define WRITE_CSV

/** Inputs: **/
#define CASCADE_PATH  "cascades/haarcascade_frontalface_default.xml"
#define IN_VID        "input_vid/031213_POTUS_ExportCouncil_HD.mp4"
#define TRAINING_LIST "obama_faces/list"

/** Input video: **/
#define START_FRAME  2400
#define END_FRAME    4800
#define FRAMES_DELTA -1

/** Outputs: **/
#define OUT_VID  "1.avi"
#define CSV_FILE "1.csv"

/** Output video: **/
#define OUT_FPS    15
#define OUT_FOURCC CV_FOURCC('M','J','P','G') //codec

/** Colors, fonts, lines... **/
#define NO_MATCH_COLOR    Scalar(0,0,255) //red
#define MATCH_COLOR       Scalar(0,255,0) //green
#define FACE_RADIUS_RATIO 0.75
#define CIRCLE_THICKNESS  2.5
#define LINE_TYPE         CV_AA
#define FONT              FONT_HERSHEY_PLAIN
#define FONT_COLOR        Scalar(255,255,255)
#define THICKNESS_TITLE   1.9
#define SCALE_TITLE       1.9
#define POS_TITLE         cvPoint(10, 30)
#define THICKNESS_LINK    1.6
#define SCALE_LINK        1.3
#define POS_LINK          cvPoint(10, 55)

/** Face detector: **/
#define DET_SCALE_FACTOR   1.01
#define DET_MIN_NEIGHBORS  40
#define DET_MIN_SIZE_RATIO 0.06
#define DET_MAX_SIZE_RATIO 0.18

/** LBPH face recognizer: **/
#define LBPH_RADIUS    3
#define LBPH_NEIGHBORS 8
#define LBPH_GRID_X    8
#define LBPH_GRID_Y    8
#define LBPH_THRESHOLD 180.0

#endif	/* DEFS_H */

