#include<glad/glad.h>
namespace YaoRender {
	void SetclearColor(float R, float G, float B, float A) {
		glClearColor(R, G, B, A);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}



}