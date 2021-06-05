////
////  planet.cpp
////  COSC3000
////
////  Created by Keyne Kassapa on 26/5/19.
////  Copyright © 2019 Keyne Kassapa. All rights reserved.
////
//#pragma once
//#include "planet.hpp"
//#include <iostream>
//#include <math.h>
//
//// Lib includes
//#define GLEW_STATIC
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//#include "../SOIL2/SOIL2.h"
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//// local includes
//#include "shader.h"
//#include "camera.h"
//#include "model.h"
//
//
//
//
//
//
//
///*
// By downloading, copying, installing or using the software you agree to this
// license. If you do not agree to this license, do not download, install,
// copy or use the software.
//
//                           License Agreement
//                For Open Source Computer Vision Library
//                        (3-clause BSD License)
//
// Copyright (C) 2013, OpenCV Foundation, all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * Neither the names of the copyright holders nor the names of the contributors
//     may be used to endorse or promote products derived from this software
//     without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are
// disclaimed. In no event shall copyright holders or contributors be liable for
// any direct, indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
// */
//
//
// #include <opencv2/highgui.hpp>
// #include <opencv2/aruco.hpp>
// #include <iostream>
//
// using namespace std;
// using namespace cv;
//
// namespace {
// const char* about = "Basic marker detection";
// const char* keys  =
//         "{d        |       | dictionary: DICT_4X4_50=0, DICT_4X4_100=1, DICT_4X4_250=2,"
//         "DICT_4X4_1000=3, DICT_5X5_50=4, DICT_5X5_100=5, DICT_5X5_250=6, DICT_5X5_1000=7, "
//         "DICT_6X6_50=8, DICT_6X6_100=9, DICT_6X6_250=10, DICT_6X6_1000=11, DICT_7X7_50=12,"
//         "DICT_7X7_100=13, DICT_7X7_250=14, DICT_7X7_1000=15, DICT_ARUCO_ORIGINAL = 16,"
//         "DICT_APRILTAG_16h5=17, DICT_APRILTAG_25h9=18, DICT_APRILTAG_36h10=19, DICT_APRILTAG_36h11=20}"
//         "{v        |       | Input from video file, if ommited, input comes from camera }"
//         "{ci       | 0     | Camera id if input doesnt come from video (-v) }"
//         "{c        |       | Camera intrinsic parameters. Needed for camera pose }"
//         "{l        | 0.1   | Marker side length (in meters). Needed for correct scale in camera pose }"
//         "{dp       |       | File of marker detector parameters }"
//         "{r        |       | show rejected candidates too }"
//         "{refine   |       | Corner refinement: CORNER_REFINE_NONE=0, CORNER_REFINE_SUBPIX=1,"
//         "CORNER_REFINE_CONTOUR=2, CORNER_REFINE_APRILTAG=3}";
// }
//
////planet 변수
//
//const GLint WIDTH = 1400, HEIGHT = 800;
//const double PI = 3.141592653589793238463;
//int SCREEN_WIDTH, SCREEN_HEIGHT;
//
//// Function prototypes
//void KeyCallback( GLFWwindow *window, int key, int scancode, int action, int mode );
//void MouseCallback_p( GLFWwindow *window, double xPos, double yPos );
//void DoMovement( );
//bool CloseEnough(GLfloat user_x, GLfloat user_y, GLfloat obj_x, GLfloat obj_y, GLfloat select_distance);
//glm::vec3 process_keyboard_user( GLfloat deltaTime, GLfloat* user_x, GLfloat* user_y );
//
//// Camera
//Camera camera( glm::vec3( 40.0f, 0.0f, 30.0f ) );
//bool key_p[1024];
//GLfloat lastX = 400, lastY = 300;
//bool firstMouse = true;
//string cameraType = "";
//bool view_mode = true;
//
//
//// Light attributes
//glm::vec3 lightPos( 0.0f, 0.0f, 0.0f );
//
//GLfloat deltaTime = 0.0f;
//GLfloat lastFrame = 0.0f;
//
//GLfloat speed = 30.0f;
//
////마우스 좌표
//GLfloat mouse_x;
//GLfloat mouse_y;
//GLfloat mouse_scale = 19.0f;
//bool move_2 = true;
//
//
//
//
//
//
// /**
//  */
// static bool readCameraParameters(string filename, Mat &camMatrix, Mat &distCoeffs) {
//     FileStorage fs(filename, FileStorage::READ);
//     if(!fs.isOpened())
//         return false;
//     fs["camera_matrix"] >> camMatrix;
//     fs["distortion_coefficients"] >> distCoeffs;
//     return true;
// }
//
//
//
// /**
//  */
// static bool readDetectorParameters(string filename, Ptr<aruco::DetectorParameters> &params) {
//     FileStorage fs(filename, FileStorage::READ);
//     if(!fs.isOpened())
//         return false;
//     fs["adaptiveThreshWinSizeMin"] >> params->adaptiveThreshWinSizeMin;
//     fs["adaptiveThreshWinSizeMax"] >> params->adaptiveThreshWinSizeMax;
//     fs["adaptiveThreshWinSizeStep"] >> params->adaptiveThreshWinSizeStep;
//     fs["adaptiveThreshConstant"] >> params->adaptiveThreshConstant;
//     fs["minMarkerPerimeterRate"] >> params->minMarkerPerimeterRate;
//     fs["maxMarkerPerimeterRate"] >> params->maxMarkerPerimeterRate;
//     fs["polygonalApproxAccuracyRate"] >> params->polygonalApproxAccuracyRate;
//     fs["minCornerDistanceRate"] >> params->minCornerDistanceRate;
//     fs["minDistanceToBorder"] >> params->minDistanceToBorder;
//     fs["minMarkerDistanceRate"] >> params->minMarkerDistanceRate;
//     fs["cornerRefinementMethod"] >> params->cornerRefinementMethod;
//     fs["cornerRefinementWinSize"] >> params->cornerRefinementWinSize;
//     fs["cornerRefinementMaxIterations"] >> params->cornerRefinementMaxIterations;
//     fs["cornerRefinementMinAccuracy"] >> params->cornerRefinementMinAccuracy;
//     fs["markerBorderBits"] >> params->markerBorderBits;
//     fs["perspectiveRemovePixelPerCell"] >> params->perspectiveRemovePixelPerCell;
//     fs["perspectiveRemoveIgnoredMarginPerCell"] >> params->perspectiveRemoveIgnoredMarginPerCell;
//     fs["maxErroneousBitsInBorderRate"] >> params->maxErroneousBitsInBorderRate;
//     fs["minOtsuStdDev"] >> params->minOtsuStdDev;
//     fs["errorCorrectionRate"] >> params->errorCorrectionRate;
//     return true;
// }
//
//
//
// /**
//  */
// int main_like_function(int argc, char *argv[]) {
//     
//     
//     bool move = true;
//     
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//     glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
//     
//     GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "learn Opengl", nullptr, nullptr);
//     
//     if ( nullptr == window )
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate( );
//         
//         return EXIT_FAILURE;
//     }
//     
//     glfwMakeContextCurrent( window );
//     glfwGetFramebufferSize( window, &SCREEN_WIDTH, &SCREEN_HEIGHT );
//     glfwSetKeyCallback( window, KeyCallback );
//     glfwSetCursorPosCallback( window, MouseCallback_p );
//     glfwSetInputMode( window, GLFW_CURSOR, GLFW_CURSOR_NORMAL );
//     glewExperimental = GL_TRUE;
//     
//     if ( GLEW_OK != glewInit( ) )
//     {
//         std::cout << "Failed to initialize GLEW" << std::endl;
//         return EXIT_FAILURE;
//     }
//     
//     glViewport( 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT );
//     glEnable( GL_DEPTH_TEST );
//     
//     Shader shader( "resources/shaders/modelLoading.vs", "resources/shaders/modelLoading.frag" );
//     Shader directionalShader( "resources/shaders/directional.vs", "resources/shaders/directional.frag" );
//     Shader lampShader( "resources/shaders/lamp.vs", "resources/shaders/lamp.frag" );
//     
//     // Load models
//     Model earthModel( "resources/models/earth/Earth.obj" );
//     Model space( "resources/models/space/space.obj" );
//     Model sunModel( "resources/models/sun/sun.obj" );
//     Model mercuryModel( "resources/models/mercury/mercury.obj" );
//     Model venusModel( "resources/models/venus/venus.obj" );
//     Model marsModel( "resources/models/mars/mars.obj" );
//     Model jupiterModel("resources/models/jupiter/jupiter.obj");
//     Model saturnModel("resources/models/saturn/13906_Saturn_v1_l3.obj");
//     Model uranusModel("resources/models/uranus/13907_Uranus_v2_l3.obj");
//     Model neptuneModel("resources/models/neptune/13908_Neptune_v2_l3.obj");
//     
// //    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
//     
//     glm::mat4 projection(1);
//     projection = glm::perspective( camera.GetZoom( ), ( float )SCREEN_WIDTH/( float )SCREEN_HEIGHT, 0.1f, 100.0f );
//     
//     GLfloat scale = 0.1f;
//     GLuint i = 0;
//     
//     
//     // 유저오브젝트의 좌표
//     GLfloat user_x = 5.0f;
//     GLfloat user_y = 5.0f;
//     
//     CommandLineParser parser(argc, argv, keys);
//     parser.about(about);
//
//     if(argc < 2) {
//         parser.printMessage();
//         return 0;
//     }
//
//     int dictionaryId = parser.get<int>("d");
//     bool showRejected = parser.has("r");
//     bool estimatePose = parser.has("c");
//     float markerLength = parser.get<float>("l");
//
//     Ptr<aruco::DetectorParameters> detectorParams = aruco::DetectorParameters::create();
//     if(parser.has("dp")) {
//         bool readOk = readDetectorParameters(parser.get<string>("dp"), detectorParams);
//         if(!readOk) {
//             cerr << "Invalid detector parameters file" << endl;
//             return 0;
//         }
//     }
//
//     if (parser.has("refine")) {
//         //override cornerRefinementMethod read from config file
//         detectorParams->cornerRefinementMethod = parser.get<int>("refine");
//     }
//     std::cout << "Corner refinement method (0: None, 1: Subpixel, 2:contour, 3: AprilTag 2): " << detectorParams->cornerRefinementMethod << std::endl;
//
//     int camId = parser.get<int>("ci");
//
//     String video;
//     if(parser.has("v")) {
//         video = parser.get<String>("v");
//     }
//
//     if(!parser.check()) {
//         parser.printErrors();
//         return 0;
//     }
//
//     Ptr<aruco::Dictionary> dictionary =
//         aruco::getPredefinedDictionary(aruco::PREDEFINED_DICTIONARY_NAME(dictionaryId));
//
//     Mat camMatrix, distCoeffs;
//     if(estimatePose) {
//         bool readOk = readCameraParameters(parser.get<string>("c"), camMatrix, distCoeffs);
//         if(!readOk) {
//             cerr << "Invalid camera file" << endl;
//             return 0;
//         }
//     }
//
//     VideoCapture inputVideo;
//     int waitTime;
//     if(!video.empty()) {
//         inputVideo.open(video);
//         waitTime = 0;
//     } else {
//         inputVideo.open(camId);
//         waitTime = 10;
//     }
//
//     double totalTime = 0;
//     int totalIterations = 0;
//
//     while(inputVideo.grab() || ) {
//         Mat image, imageCopy;
//         inputVideo.retrieve(image);
//
//         double tick = (double)getTickCount();
//
//         vector< int > ids;
//         vector< vector< Point2f > > corners, rejected;
//         vector< Vec3d > rvecs, tvecs;
//
//         // detect markers and estimate pose
//         aruco::detectMarkers(image, dictionary, corners, ids, detectorParams, rejected);
//         if(estimatePose && ids.size() > 0)
//             aruco::estimatePoseSingleMarkers(corners, markerLength, camMatrix, distCoeffs, rvecs,
//                                              tvecs);
//
//         double currentTime = ((double)getTickCount() - tick) / getTickFrequency();
//         totalTime += currentTime;
//         totalIterations++;
//         if(totalIterations % 30 == 0) {
//             cout << "Detection Time = " << currentTime * 1000 << " ms "
//                  << "(Mean = " << 1000 * totalTime / double(totalIterations) << " ms)" << endl;
//         }
//
//         // draw results
//         image.copyTo(imageCopy);
//         if(ids.size() > 0) {
//             aruco::drawDetectedMarkers(imageCopy, corners, ids);
//
//             if(estimatePose) {
//                 for(unsigned int i = 0; i < ids.size(); i++)
//                     aruco::drawAxis(imageCopy, camMatrix, distCoeffs, rvecs[i], tvecs[i],
//                                     markerLength * 0.5f);
//             }
//         }
//
//         if(showRejected && rejected.size() > 0)
//             aruco::drawDetectedMarkers(imageCopy, rejected, noArray(), Scalar(100, 0, 255));
//
//         imshow("out", imageCopy);
//         char key = (char)waitKey(waitTime);
//         if(key == 27) break;
//         
//         GLfloat currentFrame = glfwGetTime( );
//         deltaTime = currentFrame - lastFrame;
//         lastFrame = currentFrame;
//         
//         if(move_2){
//             i ++;
//         }
//         glfwPollEvents( );
//         DoMovement( );
//         glClearColor( 0.05f, 0.05f, 0.05f, 1.0f );
//         glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
//         
//         
//         glm::mat4 view(1);
//         view = camera.GetViewMatrix( );
//     
//         directionalShader.Use( );
//         
//         // Set lights properties
//         glUniform3f( glGetUniformLocation( directionalShader.Program, "light.position" ), lightPos.x, lightPos.y, lightPos.z );
//         glUniform3f( glGetUniformLocation( directionalShader.Program, "light.ambient" ),  0.2f, 0.2f, 0.2f );
//         glUniform3f( glGetUniformLocation( directionalShader.Program, "light.diffuse" ),  1.5f, 1.5f, 1.5f );
//         glUniform3f( glGetUniformLocation( directionalShader.Program, "light.specular" ), 0.0f, 0.0f, 0.0f);
//         
//         glUniformMatrix4fv( glGetUniformLocation( directionalShader.Program, "projection" ), 1, GL_FALSE, glm::value_ptr( projection ) );
//         glUniformMatrix4fv( glGetUniformLocation( directionalShader.Program, "view" ), 1, GL_FALSE, glm::value_ptr( view ) );
//         
//         // Model
//         
//         // SPACE
//         glm::mat4 model(1);
//         model = glm::translate( model, glm::vec3( 0.0f, 0.0f, 0.0f) );
//         model = glm::scale( model, glm::vec3( 20.0f ) );
//         glUniformMatrix4fv( glGetUniformLocation( directionalShader.Program, "model" ), 1, GL_FALSE, glm::value_ptr( model ) );
//         space.Draw( directionalShader );
//         
//         GLfloat angle, radius, x, y;
//         
//         shader.Use( );
//         GLint viewPosLoc  = glGetUniformLocation( shader.Program, "viewPos" );
//         glUniform3f( viewPosLoc,  camera.GetPosition( ).x, camera.GetPosition( ).y, camera.GetPosition( ).z );
//         
//         
//         
//         // Set lights properties
//         glUniform3f( glGetUniformLocation( shader.Program, "light.position" ), lightPos.x, lightPos.y, lightPos.z );
//         glUniform3f( glGetUniformLocation( shader.Program, "light.ambient" ),  2.2f, 2.2f, 2.2f );
//         glUniform3f( glGetUniformLocation( shader.Program, "light.diffuse" ),  1.5f, 1.5f, 1.5f );
//         glUniform3f( glGetUniformLocation( shader.Program, "light.specular" ), 0.0f, 0.0f, 0.0f);
//         glUniform1f( glGetUniformLocation( shader.Program, "light.constant" ), 1.0f );
//         glUniform1f( glGetUniformLocation( shader.Program, "light.linear" ), 0.02f );
//         glUniform1f( glGetUniformLocation( shader.Program, "light.quadratic" ), 0.006f );
//         
//         glUniformMatrix4fv( glGetUniformLocation( shader.Program, "projection" ), 1, GL_FALSE, glm::value_ptr( projection ) );
//         glUniformMatrix4fv( glGetUniformLocation( shader.Program, "view" ), 1, GL_FALSE, glm::value_ptr( view ) );
//         
//         // MERCURY
//         model = glm::mat4(1);
//         if (move) {
//             angle = 0.008f * i * speed;
//             radius = 70.0f * scale;
//             x = radius * sin(PI * 2 * angle / 360);
//             y = radius * cos(PI * 2 * angle / 360);
//             model = glm::translate( model, glm::vec3( x, 0.0f, y) );
//         } else {
//             model = glm::translate( model, glm::vec3( 70.0f * scale, 0.0f, 0.0f) );
//         }
//         
//         if (cameraType == "Mercury") {
//             camera.SetPosition(glm::vec3(x + 0.5f, 0.0f, y+0.5f));
//         }
//         
//         model = glm::scale( model, glm::vec3( 0.3f * scale ) );
//         glUniformMatrix4fv( glGetUniformLocation( shader.Program, "model" ), 1, GL_FALSE, glm::value_ptr( model ) );
//         mercuryModel.Draw( shader );
//         if (CloseEnough(-mouse_y/mouse_scale, mouse_x/mouse_scale, x, y, (0.3f+4.0f)*scale)){
//             std::cout << "close! mercury" << endl;
//         }
//         
//         // VENUS
//         model = glm::mat4(1);
//         if (move) {
//             angle = 0.007f * i  * speed;
//             radius = 80.0f * scale;
//             x = radius * sin(PI * 2 * angle / 360);
//             y = radius * cos(PI * 2 * angle / 360);
//             model = glm::translate( model, glm::vec3( x, 0.0f, y) );
//         } else {
//             model = glm::translate( model, glm::vec3( 80.0f * scale, 0.0f, 0.0f) );
//         }
//         
//         if (cameraType == "Venus") {
//             camera.SetPosition(glm::vec3(x + 0.5f, 0.0f, y+0.5f));
//         }
//         
//         model = glm::scale( model, glm::vec3( 0.5f * scale ) );
//         glUniformMatrix4fv( glGetUniformLocation( shader.Program, "model" ), 1, GL_FALSE, glm::value_ptr( model ) );
//         venusModel.Draw( shader );
//         if (CloseEnough(-mouse_y/mouse_scale, mouse_x/mouse_scale, x, y, (0.5f+4.0f)*scale)){
//             std::cout << "close! Venus" << endl;
//         }
//         
//         
//         // EARTH
//         model = glm::mat4(1);
//         if (move) {
//             angle = 0.006f * i  * speed;
//             radius = 90.0f * scale;
//             x = radius * sin(PI * 2 * angle / 360);
//             y = radius * cos(PI * 2 * angle / 360);
//             model = glm::translate( model, glm::vec3( x, 0.0f, y) );
//         } else {
//             model = glm::translate( model, glm::vec3( 90.0f * scale, 0.0f, 0.0f) );
//         }
//         
//         if (cameraType == "Earth") {
//             
//             camera.SetPosition(glm::vec3(x + 0.5f, -0.5f, y+0.5f));
//         }
//         
//         model = glm::scale( model, glm::vec3( 0.5f * scale ) );
//         angle = 0.001f * i;
//         model = glm::rotate( model, angle, glm::vec3( 0.0f, 0.1f, 0.0f ) );
//         glUniformMatrix4fv( glGetUniformLocation( shader.Program, "model" ), 1, GL_FALSE, glm::value_ptr( model ) );
//         earthModel.Draw( shader );
//         
//         if (CloseEnough(-mouse_y/mouse_scale, mouse_x/mouse_scale, x, y, (0.5f+4.0f)*scale)){
//             std::cout << "close! Earth" << endl;
//         }
//         
//         
//         
//         // 새로만들기
//         model = glm::mat4(1);
//         /*
//          키보드로 움직이기
//         glm::vec3 position = process_keyboard_user(deltaTime, &user_x, &user_y);
//         */
//         
//         //
//         glm::vec3 position = glm::vec3(-mouse_y/mouse_scale, 0.0f, mouse_x/mouse_scale);
//         
//          if (move) {
//             model = glm::translate( model, position);
//         } else {
//             model = glm::translate( model, glm::vec3( 90.0f * scale, 0.0f, 0.0f) );
//         }
//         
//         if (cameraType == "Earth") {
//             camera.SetPosition(glm::vec3(x + 0.5f, -0.5f, y+0.5f));
//         }
//         
//         model = glm::scale( model, glm::vec3( 4.0f * scale ) );
//         angle = 0.001f * i;
//         model = glm::rotate( model, angle, glm::vec3( 0.0f, 0.1f, 0.0f ) );
//         glUniformMatrix4fv( glGetUniformLocation( shader.Program, "model" ), 1, GL_FALSE, glm::value_ptr( model ) );
//         earthModel.Draw( shader );
//   
//         
//         
//         // MARS
//         model = glm::mat4(1);
//         if (move) {
//             angle = 0.005f * i * speed;
//             radius = 100.0f * scale;
//             x = radius * sin(PI * 2 * angle / 360);
//             y = radius * cos(PI * 2 * angle / 360);
//             model = glm::translate( model, glm::vec3( x, 0.0f, y) );
//         } else {
//            model = glm::translate( model, glm::vec3( 100.0f * scale, 0.0f, 0.0f) );
//         }
//         
//         if (cameraType == "Mars") {
//             camera.SetPosition(glm::vec3(x + 0.5f, 0.0f, y+0.5f));
//         }
//         
//         model = glm::scale( model, glm::vec3( 0.3f * scale ) );
//         glUniformMatrix4fv( glGetUniformLocation( shader.Program, "model" ), 1, GL_FALSE, glm::value_ptr( model ) );
//         marsModel.Draw( shader );
//         
//         if (CloseEnough(-mouse_y/mouse_scale, mouse_x/mouse_scale, x, y, (0.3f+4.0f)*scale)){
//             std::cout << "close! Mars" << endl;
//         }
//         
//         // JUPITER
//         model = glm::mat4(1);
//         if (move) {
//             angle = 0.0045f * i  * speed;
//             radius = 120.0f * scale;
//             x = radius * sin(PI * 2 * angle / 360);
//             y = radius * cos(PI * 2 * angle / 360);
//             model = glm::translate( model, glm::vec3( x, 0.0f, y) );
//         } else {
//             model = glm::translate( model, glm::vec3( 120.0f * scale, 0.0f, 0.0f) );
//         }
//         
//         if (cameraType == "Jupiter") {
//             camera.SetPosition(glm::vec3(x + 0.5f, 0.0f, y+2.5f));
//         }
//         
//         model = glm::scale( model, glm::vec3( 4.0f * scale ) );
//         glUniformMatrix4fv( glGetUniformLocation( shader.Program, "model" ), 1, GL_FALSE, glm::value_ptr( model ) );
//         jupiterModel.Draw( shader );
//         
//         if (CloseEnough(-mouse_y/mouse_scale, mouse_x/mouse_scale, x, y, (4.0f+4.0f)*scale)){
//             std::cout << "close! Jupiter" << endl;
//         }
//         
//         
//         // SATURN
//         model = glm::mat4(1);
//         if (move) {
//             angle = 0.0040f * i * speed;
//             radius = 160.0f * scale;
//             x = radius * sin(PI * 2 * angle / 360);
//             y = radius * cos(PI * 2 * angle / 360);
//             model = glm::translate( model, glm::vec3( x, 0.0f, y) );
//         } else {
//             model = glm::translate( model, glm::vec3( 160.0f * scale, 0.0f, 0.0f) );
//         }
//         
//         if (cameraType == "Saturn") {
//             camera.SetPosition(glm::vec3(x + 0.5f, 0.0f, y+2.5f));
//         }
//         
//         model = glm::scale( model, glm::vec3( 0.032f * scale ) );
//         angle = 0.0001f * i;
//         model = glm::rotate( model, 90.0f + angle, glm::vec3( 0.0f, 0.1f, 0.5f ) );
//         glUniformMatrix4fv( glGetUniformLocation( shader.Program, "model" ), 1, GL_FALSE, glm::value_ptr( model ) );
//         saturnModel.Draw( shader );
//         
//         if (CloseEnough(-mouse_y/mouse_scale, mouse_x/mouse_scale, x, y, (0.032f+4.0f)*scale)){
//             std::cout << "close! Saturn" << endl;
//         }
//         
//         // Uranus
//         model = glm::mat4(1);
//         if (move) {
//             angle = 0.0035f * i * speed;
//             radius = 190.0f * scale;
//             x = radius * sin(PI * 2 * angle / 360);
//             y = radius * cos(PI * 2 * angle / 360);
//             model = glm::translate( model, glm::vec3( x, 0.0f, y) );
//         } else {
//             model = glm::translate( model, glm::vec3( 190.0f * scale, 0.0f, 0.0f) );
//         }
//         
//         if (cameraType == "Uranus") {
//             camera.SetPosition(glm::vec3(x + 0.5f, 0.0f, y+2.0f));
//         }
//         
//         model = glm::scale( model, glm::vec3( 0.03f * scale ) );
//         angle = 0.00001f * i;
//         model = glm::rotate( model, 160.0f + angle, glm::vec3( 0.0f, 0.1f, 0.5f ) );
//         glUniformMatrix4fv( glGetUniformLocation( shader.Program, "model" ), 1, GL_FALSE, glm::value_ptr( model ) );
//         uranusModel.Draw( shader );
//         
//         if (CloseEnough(-mouse_y/mouse_scale, mouse_x/mouse_scale, x, y, (0.03f+4.0f)*scale)){
//             std::cout << "close! Uranus" << endl;
//         }
//         
//         // NEPTUNE
//         model = glm::mat4(1);
//         if (move) {
//             angle = 0.003f * i * speed;
//             radius = 220.0f * scale;
//             x = radius * sin(PI * 2 * angle / 360);
//             y = radius * cos(PI * 2 * angle / 360);
//             model = glm::translate( model, glm::vec3( x, 0.0f, y) );
//         } else {
//             model = glm::translate( model, glm::vec3( 220.0f * scale, 0.0f, 0.0f) );
//         }
//         
//         if (cameraType == "Neptune") {
//             camera.SetPosition(glm::vec3(x + 0.5f, 0.0f, y+2.0f));
//         }
//         
//         model = glm::scale( model, glm::vec3( 0.03f * scale ) );
//         angle = 0.00001f * i;
//         model = glm::rotate( model, 130.0f + angle, glm::vec3( 0.0f, 0.1f, 0.5f ) );
//         glUniformMatrix4fv( glGetUniformLocation( shader.Program, "model" ), 1, GL_FALSE, glm::value_ptr( model ) );
//         neptuneModel.Draw( shader );
//         
//         if (CloseEnough(-mouse_y/mouse_scale, mouse_x/mouse_scale, x, y, (0.03f+4.0f)*scale)){
//             std::cout << "close! Neptune" << endl;
//         }
//         
//         
//         
//         
//         // SUN
//         lampShader.Use( );
//         GLint modelLoc = glGetUniformLocation( lampShader.Program, "model" );
//         GLint viewLoc = glGetUniformLocation( lampShader.Program, "view" );
//         GLint projLoc = glGetUniformLocation( lampShader.Program, "projection" );
//
//         glUniformMatrix4fv( viewLoc, 1, GL_FALSE, glm::value_ptr( view ) );
//         glUniformMatrix4fv( projLoc, 1, GL_FALSE, glm::value_ptr( projection ) );
//         model = glm::mat4(1);
//         model = glm::translate( model, lightPos );
//         model = glm::scale( model, glm::vec3( 20.0f * scale  ) );
//         glUniformMatrix4fv( glGetUniformLocation( shader.Program, "model" ), 1, GL_FALSE, glm::value_ptr( model ) );
//         glUniformMatrix4fv( modelLoc, 1, GL_FALSE, glm::value_ptr( model ) );
//         sunModel.Draw( lampShader );
//         
//         if (CloseEnough(-mouse_y/mouse_scale, mouse_x/mouse_scale, 0, 0, (20.0f+4.0f)*scale)){
//             std::cout << "close! sun" << endl;
//         }
//         
//         
//         if (cameraType == "Up") {
//             //camera.SetPosition(glm::vec3(-1.438195, 38.160343, 1.159209));
//             camera.SetPosition(glm::vec3(0, 38.160343, 0));
//             camera.SetYaw(180.0f);
//             camera.SetPitch(-90.0f);
//         }
//         
//         glfwSwapBuffers( window );
//     }
//     
//     glfwTerminate( );
//
//     return 0;
// }
//
//
//
//
//glm::vec3 process_keyboard_user( GLfloat deltaTime, GLfloat* user_x, GLfloat* user_y ) {
//    GLfloat velocity = 0.6f * deltaTime;
//    
//    GLfloat x = 4.0f;
//    GLfloat y = 4.0f;
//    
//    
//    if (firstMouse){
//        if ( key_p[GLFW_KEY_UP] ) {
//            *user_x +=  x * velocity;
//        }
//        if ( key_p[GLFW_KEY_DOWN] ) {
//            *user_x -= x * velocity;
//        }
//        if ( key_p[GLFW_KEY_LEFT] ) {
//            *user_y -= y * velocity;
//        }
//        if ( key_p[GLFW_KEY_RIGHT] ) {
//            *user_y += y * velocity;
//        }
//    } else {
//        if ( key_p[GLFW_KEY_UP] ) {
//            *user_x -=  x * velocity;
//        }
//        if ( key_p[GLFW_KEY_DOWN] ) {
//            *user_x += x * velocity;
//        }
//        if ( key_p[GLFW_KEY_LEFT] ) {
//            *user_y += y * velocity;
//        }
//        if ( key_p[GLFW_KEY_RIGHT] ) {
//            *user_y -= y * velocity;
//        }
//    }
//    
//    //std::cout << "USER_X : " << *user_x << std::endl;
//    return glm::vec3(*user_x, 0.0f, *user_y);
//}
//
//
//void DoMovement() {
//    
//    if (key_p[GLFW_KEY_W] ) {
//        camera.ProcessKeyboard( FORWARD, deltaTime );
//    }
//    
//    if (key_p[GLFW_KEY_S] ) {
//        camera.ProcessKeyboard( BACKWARD, deltaTime );
//    }
//    
//    if (key_p[GLFW_KEY_A] ) {
//        camera.ProcessKeyboard( LEFT, deltaTime );
//    }
//    
//    if (key_p[GLFW_KEY_D] ) {
//        camera.ProcessKeyboard( RIGHT, deltaTime );
//    }
//    
//    if (key_p[GLFW_KEY_MINUS]) {
//        camera.DecreaseSpeed();
//    }
//    
//    if (key_p[GLFW_KEY_EQUAL]) {
//        camera.IncreaseSpeed();
//    }
//    if (key_p[GLFW_KEY_R]) {
//        move_2 = true;
//    }
//    if (key_p[GLFW_KEY_1]) {
//        cameraType = "Mercury";
//    } else if (key_p[GLFW_KEY_2]) {
//        cameraType = "Venus";
//    } else if (key_p[GLFW_KEY_3]) {
//        cameraType = "Earth";
//    } else if (key_p[GLFW_KEY_4]) {
//        cameraType = "Mars";
//    } else if (key_p[GLFW_KEY_5]) {
//        cameraType = "Jupiter";
//    } else if (key_p[GLFW_KEY_6]) {
//        cameraType = "Saturn";
//    } else if (key_p[GLFW_KEY_7]) {
//        cameraType = "Uranus";
//    } else if (key_p[GLFW_KEY_8]) {
//        cameraType = "Neptune";
//    } else if (key_p[GLFW_KEY_0]) {
//        cameraType = "";
//        view_mode = false;
//    } else if (key_p[GLFW_KEY_U]) {
//        cameraType = "Up";
//        view_mode = true;
//    }
//    
//    if (key_p[GLFW_KEY_M]) {
//        speed = speed + 0.1f;
//        std::cout << "SPEED : " << speed << std::endl;
//    } else if (key_p[GLFW_KEY_N]) {
//        speed = speed - 0.1f;
//        std::cout << "SPEED : " << speed << std::endl;
//    }
//}
//
//
//void KeyCallback( GLFWwindow *window, int key, int scancode, int action, int mode ) {
//    if ( GLFW_KEY_ESCAPE == key && GLFW_PRESS == action ) {
//        glfwSetWindowShouldClose(window, GL_TRUE);
//    }
//    
//    if ( key >= 0 && key < 1024 ) {
//        if ( action == GLFW_PRESS ) {
//            key_p[key] = true;
//        } else if ( action == GLFW_RELEASE ) {
//            key_p[key] = false;
//        }
//    }
//}
//
//
//void MouseCallback_p( GLFWwindow *window, double xPos, double yPos ) {
//    if ( firstMouse ) {
//        lastX = xPos;
//        lastY = yPos;
//        firstMouse = false;
//    }
//    
//    GLfloat xOffset = xPos - lastX;
//    GLfloat yOffset = lastY - yPos;
//    
//    lastX = xPos;
//    lastY = yPos;
//    if(view_mode){
//        mouse_x = xPos - 1400/2; // width, hight 값 바뀌면 이거도 바꿔야함
//        //std::cout << "set mouse_x" << mouse_x << std::endl;
//        mouse_y = yPos - 800/2 ;
//        //std::cout << "set mouse_y" << mouse_y << std::endl;
//    } else{
//        camera.ProcessMouseMovement( xOffset, yOffset );
//    }
//    
//}
//
//bool CloseEnough(GLfloat user_x, GLfloat user_y, GLfloat obj_x, GLfloat obj_y, GLfloat select_distance) {
//    if( sqrt( pow(user_x-obj_x,2) + pow(user_y-obj_y, 2) < select_distance )) {
//        move_2 = false;
//        return true;
//    } else {
//        return false;
//    }
//}
