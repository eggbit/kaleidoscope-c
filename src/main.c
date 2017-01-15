#include <stdio.h>
#include <stdlib.h>
#include <llvm-c/Core.h>

int main(__unused int argc, __unused const char *argv[]) {
    LLVMModuleRef mod = LLVMModuleCreateWithName("my_module");
    LLVMDisposeModule(mod);

    return 0;
}
