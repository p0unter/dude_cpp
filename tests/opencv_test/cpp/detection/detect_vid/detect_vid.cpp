#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/all_layers.hpp>

using namespace std;
using namespace cv;
using namespace dnn;

int main(int, char**) {
    try {
        std::vector<std::string> class_names;
        ifstream ifs("../../../../input/object_detection_classes_coco.txt");

        if (!ifs.is_open()) {
            cerr << "ERROR: Cannot open class names file" << endl;
            return -1;
        }

        string line;
        while (getline(ifs, line)) {
            class_names.push_back(line);
        }

        cout << "Loaded " << class_names.size() << " classes" << endl;

        auto model = readNet("../../../../input/frozen_inference_graph.pb",
                             "../../../../input/ssd_mobilenet_v2_coco_2018_03_29.pbtxt.txt",
                             "TensorFlow");

        VideoCapture cap("../../../../input/dirk.mp4");
        if (!cap.isOpened()) {
            cerr << "ERROR: Cannot open video file" << endl;
            return -1;
        }

        int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
        int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));

        VideoWriter out("../../../../outputs/video_result.avi",
                        VideoWriter::fourcc('M', 'J', 'P', 'G'),
                        30,
                        Size(frame_width, frame_height));

        if (!out.isOpened()) {
            cerr << "ERROR: Cannot open video writer" << endl;
            return -1;
        }

        namedWindow("image", WINDOW_NORMAL);
        setWindowProperty("image", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
        cout << "Processing video... Press 'q' to quit, 'ESC' to exit." << endl;

        while (cap.isOpened()) {
            Mat image;
            bool isSuccess = cap.read(image);

            if (!isSuccess) break;

            int image_height = image.rows;
            int image_width = image.cols;

            Mat blob = blobFromImage(image, 1.0, Size(300, 300), Scalar(127.5, 127.5, 127.5),
                                     true, false);
            model.setInput(blob);
            Mat output = model.forward();

            Mat detectionMat(output.size[2], output.size[3], CV_32F, output.ptr<float>());

            for (int i = 0; i < detectionMat.rows; i++){
                float confidence = detectionMat.at<float>(i, 2);

                if (confidence > 0.4){
                    int class_id = static_cast<int>(detectionMat.at<float>(i, 1));

                    string label = "Unknown";
                    if (class_id > 0 && class_id <= (int)class_names.size()) {
                        label = class_names[class_id - 1];
                    }

                    int box_x = static_cast<int>(detectionMat.at<float>(i, 3) * image_width);
                    int box_y = static_cast<int>(detectionMat.at<float>(i, 4) * image_height);
                    int box_width = static_cast<int>(detectionMat.at<float>(i, 5) * image_width - box_x);
                    int box_height = static_cast<int>(detectionMat.at<float>(i, 6) * image_height - box_y);

                    rectangle(image, Point(box_x, box_y),
                              Point(box_x+box_width, box_y+box_height),
                              Scalar(255,255,255), 2);
                    putText(image, label, Point(box_x, box_y-5),
                            FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0,255,255), 1);
                }
            }

            imshow("image", image);
            out.write(image);
            int k = waitKey(10);
            if (k == 'q' || k == 27) {
                break;
            }
        }

        cap.release();
        out.release();
        destroyAllWindows();
        cout << "Video saved to ../../../../outputs/video_result.avi" << endl;

    } catch (const cv::Exception& e) {
        cerr << "OpenCV Error: " << e.what() << endl;
        return -1;
    }

    return 0;
}
