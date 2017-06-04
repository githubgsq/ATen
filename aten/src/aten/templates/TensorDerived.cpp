#include "${Tensor}.h"
#include "HalfConvert.h"

//sketch:

/*

class Type {
  // ctor is configurable as well
  Tensor new(...) {}
  // all  methods and pure functions, virtually dispatched
  virtual Tensor add(Tensor a, Tensor b);

  // no Tensor arguments but virtually dispatched on type
  virtual Tensor linspace(int a, int b);
  //
}

// base class of derived tensors
class TensorImpl {
  Type * type_; //non-virtual so that we don't double indirect unnecessarily ...

  // not virtual - Type * handles the virtual dispatch
  Tensor add(Tensor b) {
    type_->add(self,b);
  }
}

// non-method style dispatch
Tensor add(Tensor a, Tensor b) {
  return a->type_->add(a,b);
}


}

*/

namespace tlib {

${Tensor}::${Tensor}(Context* context):
    tensor(${THTensor}_new(${state})), context(context) {}

${Tensor}::~${Tensor}() {
  ${THTensor}_free(${state,} tensor);
}

Type& ${Tensor}::type() const {
  return context->getType(Processor::${Processor},ScalarType::${ScalarName});
}

}