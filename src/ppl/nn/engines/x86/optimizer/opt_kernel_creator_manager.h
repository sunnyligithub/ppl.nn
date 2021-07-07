// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef _ST_HPC_PPL_NN_ENGINES_X86_OPTIMIZER_OPT_KERNEL_CREATOR_MANAGER_H_
#define _ST_HPC_PPL_NN_ENGINES_X86_OPTIMIZER_OPT_KERNEL_CREATOR_MANAGER_H_

#include "ppl/nn/engines/x86/optimizer/opt_kernel.h"

namespace ppl { namespace nn { namespace x86 {

typedef X86OptKernel* (*OptKernelCreator)(const ir::Node*);

class OptKernelCreatorManager {
public:
    static OptKernelCreatorManager* Instance() {
        static OptKernelCreatorManager mgr;
        return &mgr;
    }

    ppl::common::RetCode Register(const std::string& domain, const std::string& type, OptKernelCreator);
    OptKernelCreator Find(const std::string& domain, const std::string& type);

private:
    std::map<std::string, std::map<std::string, OptKernelCreator>> domain_type_creator_;

private:
    OptKernelCreatorManager();
};

}}} // namespace ppl::nn::x86

#endif