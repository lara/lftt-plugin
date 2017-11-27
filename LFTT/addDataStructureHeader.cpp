#include <rose.h>

using namespace std;

int main (int argc, char** argv)
{
    // Build the AST used by ROSE
    SgProject* project = frontend(argc, argv);

    // Run internal consistency tests on AST
    AstTests::runAllTests(project);

    SgSourceFile *sourceFile;
    const SgFilePtrList& fileList = project->get_fileList();
    SgFilePtrList::const_iterator file = fileList.begin();
    sourceFile = isSgSourceFile(*file);
    const std::string &headerFileName = "LinkedList.h";
    PreprocessingInfo::RelativePositionType position = PreprocessingInfo::before;
    bool isSystemHeader = false;

    SageInterface::insertHeader (sourceFile, headerFileName, isSystemHeader, position);

    // Generate source code from AST and invoke your backend compiler
    return backend(project);
}
