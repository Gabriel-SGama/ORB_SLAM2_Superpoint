#ifndef SUPERPOINT_H
#define SUPERPOINT_H

#include <torch/script.h>
#include <torch/torch.h>

#include <opencv2/opencv.hpp>
#include <vector>

#ifdef EIGEN_MPL2_ONLY
#undef EIGEN_MPL2_ONLY
#endif

namespace ORB_SLAM2 {

struct SuperPoint : torch::nn::Module {
    SuperPoint();

    // std::vector<torch::Tensor> forward(torch::Tensor x);

    // torch::nn::Conv2d conv1a;
    // torch::nn::Conv2d conv1b;

    // torch::nn::Conv2d conv2a;
    // torch::nn::Conv2d conv2b;

    // torch::nn::Conv2d conv3a;
    // torch::nn::Conv2d conv3b;

    // torch::nn::Conv2d conv4a;
    // torch::nn::Conv2d conv4b;

    // torch::nn::Conv2d convPa;
    // torch::nn::Conv2d convPb;

    // // descriptor
    // torch::nn::Conv2d convDa;
    // torch::nn::Conv2d convDb;
};

cv::Mat SPdetect(torch::jit::script::Module model, cv::Mat img, std::vector<cv::KeyPoint> &keypoints, double threshold, bool nms, bool cuda);
// torch::Tensor NMS(torch::Tensor kpts);

class SPDetector {
   public:
    SPDetector(torch::jit::script::Module _model);
    void detect(cv::Mat &image, bool cuda);
    void getKeyPoints(float threshold, int iniX, int maxX, int iniY, int maxY, std::vector<cv::KeyPoint> &keypoints, bool nms);
    void computeDescriptors(const std::vector<cv::KeyPoint> &keypoints, cv::Mat &descriptors);

   private:
    // std::shared_ptr<SuperPoint> model;
    torch::jit::script::Module model;

    at::Tensor mProb;
    at::Tensor mDesc;
};

}  // namespace ORB_SLAM2

#endif
