#include"Utils.hpp"

void PrintEnd(std::ofstream &output){

        output << "FILE" << "\n" << " HEAP:\n\n "  ;


}


//this function print the result for user
std::ofstream createOutput() {
        
        string path;

        path.insert(0, "./dataset/output.data");

	ofstream output(path);

	if (!(output.is_open())) {
          printf("is not possible open the file");
        }
          return output;
        
}




