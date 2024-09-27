#include <string>
#include <iostream>

::std::string BuildScmStatus();
int BuildTimeStampStatus();
::std::string BuildScmRevision();

int main() {
  ::std::cout << "BUILD_SCM_STATUS is: " << BuildScmStatus() << std::endl;
  ::std::cout << "BUILD_TIMESTAMP is: " << BuildTimeStampStatus() << std::endl;
  ::std::cout << "STABLE_GIT_COMMIT is: " << BuildScmRevision() << std::endl;

  return 0;
}
