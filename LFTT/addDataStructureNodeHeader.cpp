#include <rose.h>

using namespace std;



class visitorTraversal : public AstSimpleProcessing
{
  protected:
    virtual void visit(SgNode* n);
};

void visitorTraversal::visit(SgNode* node)
{
  PreprocessingInfo::RelativePositionType position = PreprocessingInfo::before;
  if (node->variantT() == V_SgClassDefinition) {
    SageInterface::attachArbitraryText(isSgLocatedNode(node), "bool IsNodePresent(Node* n, int key);", position);
    SageInterface::attachArbitraryText(isSgLocatedNode(node), "bool IsKeyPresent(Node* n);", position);
  }
 
}





int main (int argc, char** argv)
{
    // Build the AST used by ROSE
    SgProject* project = frontend(argc, argv);

    // Run internal consistency tests on AST
    AstTests::runAllTests(project);
    visitorTraversal myVisitor;
    myVisitor.traverseInputFiles(project, preorder);



    SgSourceFile *sourceFile;
    const SgFilePtrList& fileList = project->get_fileList();
    SgFilePtrList::const_iterator file = fileList.begin();
    sourceFile = isSgSourceFile(*file);
    const std::string &headerFileName = "LinkedListNode.h";
    PreprocessingInfo::RelativePositionType position = PreprocessingInfo::before;
    bool isSystemHeader = false;

    SageInterface::insertHeader (sourceFile, headerFileName, isSystemHeader, position);




    // Generate source code from AST and invoke your backend compiler
    return backend(project);
}
