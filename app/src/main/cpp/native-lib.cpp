#include <jni.h>
#include <string>
#include <opencv2/opencv.hpp>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_opencvtest_MainActivity_stringFromJNI( JNIEnv *env, jobject /* this */) {
    cv::Mat mat = cv::imread("sdcard/111/111.png");
    cv::Mat temp = mat(cv::Rect(0, 0, 500, 500));
    cv::imwrite("sdcard/111/222.png", temp);
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
