#include <vector>
#include <iostream>
#include <fstream>

#include "GLSLProgram.h"

GLSLProgram::GLSLProgram() : numAttribute(0), programID(0), vertexShaderID(0), fragShaderID(0) {

}

GLSLProgram::~GLSLProgram() {

}


void GLSLProgram::compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath) {
	//Vertex and fragment shaders are successfully compiled.
	//Now time to link them together into a program.
	//Get a program object.
	programID = glCreateProgram();

	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

	if (vertexShaderID == 0) {
		std::printf("ERROR : could not create Vertex shader");
	}

	fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	if (fragShaderID == 0) {
		std::printf("ERROR : could not create Fragment shader");
	}

	compileShader(vertexShaderFilePath, vertexShaderID);
	compileShader(fragmentShaderFilePath, fragShaderID);
}

void GLSLProgram::linkShaders() {
	//Vertex and fragment shaders are successfully compiled.
	//Now time to link them together into a program.
	//Get a program object.
	//programID = glCreateProgram();

	//Attach our shaders to our program
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragShaderID);

	//Link our program
	glLinkProgram(programID);

	//Note the different functions here: glGetProgram* instead of glGetShader*.
	GLint isLinked = 0;
	glGetProgramiv(programID, GL_LINK_STATUS, (int *)&isLinked);

	if (isLinked == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<GLchar> errorLog(maxLength);
		glGetProgramInfoLog(programID, maxLength, &maxLength, &errorLog[0]);

		//We don't need the program anymore.
		glDeleteProgram(programID);
		//Don't leak shaders either.
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragShaderID);

		//Use the infoLog as you see fit.
		std::cout << ("%s", &errorLog[0]);
		std::cout << ("Shaders failed to link: %s");
		//In this simple program, we'll just leave
		return;
	}

	//Always detach shaders after a successful link.
	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragShaderID);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragShaderID);
}

/*
void GLSLProgram::addAttribute(const std::string& attributeName) {
	glBindAttribLocation(programID, numAttribute, attributeName.c_str());
	numAttribute++;
}
*/

void GLSLProgram::use() {
	glUseProgram(programID);
}

void GLSLProgram::unuse() {
	glUseProgram(0);
}

GLuint GLSLProgram::getProgramId() {
	return programID;
}

void GLSLProgram::compileShader(const std::string& filepath, GLuint id) {
	std::ifstream vertexFile(filepath);

	if (vertexFile.fail()) {
		std::cout << ("ERROR: Failed to open %s\n", filepath);
	}

	std::string fileContents = "";
	std::string line;

	while (std::getline(vertexFile, line)) {
		fileContents += line + "\n";
	}

	vertexFile.close();

	const char* contentsPtr = fileContents.c_str();
	glShaderSource(id, 1, &contentsPtr, nullptr);
	glCompileShader(id);

	GLint success = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE) {
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		//We don't need the shader anymore.
		glDeleteShader(id);

		std::cout << ("%s", &errorLog[0]);
		std::cout << ("Shader failed to compile: %s", filepath);
		return;
	}
}