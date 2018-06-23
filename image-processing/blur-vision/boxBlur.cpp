#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<int>> boxBlur(std::vector<std::vector<int>> image) {
    int cellsAve;
    vector<int> row;
    vector<vector<int>> outputImage;
    for (int i=1;i<image.size()-1;i++) {
        row={};
        for (int j=1;j<image[i].size()-1;j++) {
            cellsAve = (image[i-1][j-1]+image[i-1][j]+image[i-1][j+1]+
                         image[i][j-1]+image[i][j]+image[i][j+1]+
                         image[i+1][j-1]+image[i+1][j]+image[i+1][j+1])/9;
            row.push_back(cellsAve);
        }
        outputImage.push_back(row);
    }
    return outputImage;
}



int main() {
    vector<vector<int>> image, blurredImage;

    image = {{7,4,0,1},
            {5,6,2,2},
            {6,10,7,8},
            {1,4,2,0}};

    blurredImage = boxBlur(image);
    for (vector<int> v:blurredImage) {
        for (int w:v) {
            cout << w << " ";
        }
        cout << "\n";
    }
    return 0;
}
