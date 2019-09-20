//        created: 2019-09-01
//  last modified: 2019-09-18
//         author: Teragump

#include <boost/shared_ptr.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "caffe/blob.hpp"
#include "caffe/layer.hpp"
#include "caffe/net.hpp"
#include "caffe/proto/caffe.pb.h"
#include "caffe/util/io.hpp"
#include "caffe/util/upgrade_proto.hpp"

using boost::shared_ptr;
using caffe::Blob;
using caffe::Layer;
using std::vector;

int main(int argc, char** argv) {
  if (argc != 3) {
    LOG(ERROR) << "Usage: " << argv[0] << " input_proto_file output_model_file";
    return 1;
  }
  std::string proto_file = argv[1];
  std::string model_file = argv[2];
  caffe::NetParameter src_param, dst_param;
  ReadProtoFromTextFileOrDie(proto_file, &src_param);
  UpgradeNetAsNeeded(proto_file, &src_param);
  src_param.mutable_state()->set_phase(caffe::TEST);
  caffe::Net<float> net(src_param);
  std::vector<shared_ptr<Layer<float>>> layers = net.layers();
  for (int i = 0; i < layers.size(); i++) {
    static unsigned int seed = 1;
    shared_ptr<Layer<float>> layer = layers[i];
    std::vector<shared_ptr<Blob<float>>> blobs = layer->blobs();
    for (int j = 0; j < blobs.size(); j++) {
      if (!blobs[j]->count()) {
        continue;
      }
      for (int k = 0; k < blobs[j]->count(); k++) {
        blobs[j]->mutable_cpu_data()[k] =
            1.0 * rand_r(&seed) / INT_MAX / blobs[j]->count();
      }
    }
  }
  net.ToProto(&dst_param, false);
  WriteProtoToBinaryFile(dst_param, model_file);
  return 0;
}
