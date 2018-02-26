
    #include "GL_Wrapper/BufferObject/VBO/NRE_VBO.hpp"
    #include "GL_Wrapper/VAO/NRE_VAO.hpp"
    #include "Support/Scene/NRE_Scene.hpp"
    #include "SDL_Wrapper/Event/NRE_Event.hpp"
    #include "Camera/Input/NRE_Input.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
        SDL::Event event;
        GL::VBO buffer(true);
        GL::VAO vao(true);
        Input::Input in("kBinder.cfg", "mBinder.cfg");

        /*NREfloat data[3 * 3] = {-0.5, -0.5, -1.0,
                                 0.0, 0.5, -1.0,
                                 0.5, -0.5, -1.0};

        GLubyte color[3 * 3] = {255, 0, 0,
                                0, 255, 0,
                                0, 0, 255};

        GLbyte normal[3 * 3] = {1.0, 0.0, 0.0,
                                1.0, 0.0, 0.0,
                                1.0, 0.0, 0.0};

        buffer.allocate(sizeof(NREfloat), 3, GL_STREAM_DRAW);
        buffer.update(0, sizeof(NREfloat), 3, data, color, normal);

        vao.bind();
            buffer.bind();
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
                glEnableVertexAttribArray(0);

                glVertexAttribPointer(1, 3, GL_UNSIGNED_BYTE, GL_FALSE, 0, 0);
                glEnableVertexAttribArray(1);

                glVertexAttribPointer(2, 3, GL_BYTE, GL_FALSE, 0, 0);
                glEnableVertexAttribArray(2);
            buffer.unbind();
        vao.unbind();*/

        while (!in.getQuit()) {
            in.update(NULL);
        }
        std::cout << Input::Keyboard(in) << std::endl;
        std::cout << Input::Mouse(in) << std::endl;

        in.Keyboard::save("kBinder.cfg");
        in.Mouse::save("mBinder.cfg");

        return 0;
    }
