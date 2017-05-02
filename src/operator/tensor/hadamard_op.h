#ifndef MXNET_OPERATOR_TENSOR_HADAMARD_OP_H_
#define MXNET_OPERATOR_TENSOR_HADAMARD_OP_H_

#include <mxnet/operator_util.h>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>
#include <mshadow/tensor.h>
#include <mxnet/operator_util.h>
#include "../mshadow_op.h"
#include "../operator_common.h"
#include "../mxnet_op.h"
#include "../elemwise_op_common.h"
#include "./elemwise_binary_op.h"
#include "broadcast_reduce-inl.h"
#include "broadcast_reduce_op.h"


namespace mxnet {
namespace op {
using namespace mshadow;
using namespace std;


template<int n_in, int n_out>
inline bool HadaShape(const nnvm::NodeAttrs& attrs,
                      std::vector<TShape> *in_attrs,
                      std::vector<TShape> *out_attrs) {

  CHECK_EQ(in_attrs->size(), n_in) << " in operator " << attrs.name;
  CHECK_EQ(out_attrs->size(), n_out) << " in operator " << attrs.name;

  const TShape &rshape = (*in_attrs)[0];
  const TShape &cshape = (*in_attrs)[1];
  out_attrs->clear();
  out_attrs->push_back(Shape2(rshape[0], cshape[1]));
  return true;
}


template<int n_in, int n_out>
inline bool HadaType(const nnvm::NodeAttrs& attrs,
                     std::vector<int> *in_attrs,
                     std::vector<int> *out_attrs) {
  CHECK_EQ(in_attrs->size(), n_in) << " in operator " << attrs.name;
  CHECK_EQ(out_attrs->size(), n_out) << " in operator " << attrs.name;

  int dtype = (*in_attrs)[0];
  out_attrs->clear();
  out_attrs->push_back(dtype);
  return true;
}

}  // namespace op
}  // namespace mxnet
#endif  // MXNET_OPERATOR_TENSOR_HADAMARD_OP_H_
