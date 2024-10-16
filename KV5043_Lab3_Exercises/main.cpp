#include <iostream>
//ToDo: Add the filestream header
#include <fstream>
//ToDo: Add the string stream header
#include <sstream>
#include "window.h"

int main(int argc, char* argv[])
{
	//ToDo: Declare an input file stream object named inputFile
	std::ifstream inputFile;
		
	//ToDo: Open the inputFile object using the "windowParameters.txt" file
	inputFile.open("windowParameters.txt");
	
	if (inputFile.is_open())
	{
		std::string lineOfText;
		int xPos = 0;
		int yPos = 0;
		int width = 0;
		int height = 0;

		std::string windowName, strX, strY, strWidth, strHeight;

		while (std::getline(inputFile, lineOfText))
		{
			//Todo: Declare a stringstream object named sStream to work lineOfText string
			std::stringstream sStream(lineOfText);
			
			/*ToDo: Use the getline() function with a delimiter to work on the sStream object and store each of the comma seperated
			* values in the file to the five string variables decclared above
			*/
			std::getline(sStream, windowName, ',');
			std::getline(sStream, strX, ',');
			std::getline(sStream, strY, ',');
			std::getline(sStream, strWidth, ',');
			std::getline(sStream, strHeight, ',');
			//ToDo: use the stoi() function to convert the strings to integers where required.
			try
			{
				xPos = std::stoi(strX);
				yPos = std::stoi(strY);
				width = std::stoi(strWidth);
				height = std::stoi(strHeight);
			}
			catch (std::invalid_argument e)
			{
				std::cerr << "Could not convert a string to an int: " << e.what() << std::endl;
			}
			

		}

		Window aWindow = Window(windowName, xPos, yPos, width, height);
		aWindow.Run();
		
	}
	else
	{
		std::cerr << "Couldn't open the file: windowParameters.txt";
	}

	return 0;
}