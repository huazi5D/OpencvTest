#include <jni.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <android/log.h>

using namespace cv;

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_opencvtest_MainActivity_stringFromJNI( JNIEnv *env, jobject /* this */) {
    cv::Mat mat = cv::imread("sdcard/111/111.png");

    __android_log_print(ANDROID_LOG_DEBUG, "zhx", "111");
    bool isBlanckFrame = true;
    int step = mat.cols / 5;
    for (int i = 0; i < 5; ++i) {
        Scalar color = mat.at<Vec3b>(step * i, 0);
        if (color(0) != 0 || color(1) != 0 || color(2) != 0) {
            isBlanckFrame = false;
            break;
        }
    }
    __android_log_print(ANDROID_LOG_DEBUG, "zhx", "222");
    Scalar color = mat.at<Vec3b>(150, 150);
    __android_log_print(ANDROID_LOG_DEBUG, "zhx", "%f %f %f", color(0), color(1), color(2));
    circle(mat, Point(150, 150), 4, Scalar(0, 0, 255));
    imwrite("sdcard/111/222.png", mat);
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
