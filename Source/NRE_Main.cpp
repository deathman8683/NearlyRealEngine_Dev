
    #include "Support/Stage/NRE_Stage.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "World/NRE_World.hpp"
    #include "Time/Clock/NRE_Clock.hpp"
    #include "Renderer/DeferredRenderer/NRE_DeferredRenderer.hpp"

    #include "Object/NRE_Object.hpp"

    using namespace NRE;
    using namespace Maths;

    int main(int argc, char **argv) {
        try {
            Support::Stage engineStage("NRE 0.1 - Dev version", Maths::Vector2D<int>(1280, 720));
            Camera::MoveableCamera camera(70.0, 1280.0 / 720.0, Maths::Vector2D<NREfloat>(0.1, 2000.0), Maths::Vector3D<NREfloat>(0, 1, 100), Maths::Vector3D<NREfloat>(0, 0, 100));

            World::World engineWorld(Maths::Vector2D<GLuint>(5, 5), Maths::Vector2D<GLint>(0, 0));

            std::vector<Light::Light*> engineLight;
            Light::DirectionnalLight engineLight1(Maths::Point3D<NREfloat>(0, 0, 300),Maths::Vector3D<NREfloat>(0.06, 0.16, 0.5), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0));
            Light::PointLight engineLight2(Maths::Point3D<NREfloat>(29.7,  28.0, 29.0), Maths::Vector3D<NREfloat>(400.0, 0.0, 0.0));
            Light::PointLight engineLight3(Maths::Point3D<NREfloat>(71.6,  41.7, 29.0), Maths::Vector3D<NREfloat>(0.0, 400.0, 0.0));
            Light::PointLight engineLight4(Maths::Point3D<NREfloat>(60.5, -44.8, 29.0), Maths::Vector3D<NREfloat>(0.0, 0.0, 400.0));
            Light::PointLight engineLight5(Maths::Point3D<NREfloat>(50.0, -4.8,  29.0), Maths::Vector3D<NREfloat>(4000.0, 4000.0, 4000.0));
            engineLight.push_back(&engineLight1);
            engineLight.push_back(&engineLight2);
            engineLight.push_back(&engineLight3);
            engineLight.push_back(&engineLight4);
            engineLight.push_back(&engineLight5);

            Renderer::Shader skyBoxShader("Shaders/SkyBox.vert", "Shaders/SkyBox.frag", true);
                skyBoxShader.addUniformLocation("MVP");
            Renderer::Shader captureShader("Shaders/CaptureShader.vert", "Shaders/CaptureShader.frag", true);
                captureShader.addUniformLocation("skyBox");
                captureShader.addUniformLocation("modelview");
            Renderer::Shader irradianceShader("Shaders/IrradianceShader.vert", "Shaders/IrradianceShader.frag", true);
                irradianceShader.addUniformLocation("skyBox");
                irradianceShader.addUniformLocation("modelview");
            Renderer::Shader prefilterShader("Shaders/PrefilterShader.vert", "Shaders/PrefilterShader.frag", true);
                prefilterShader.addUniformLocation("skyBox");
                prefilterShader.addUniformLocation("modelview");
                prefilterShader.addUniformLocation("roughness");
            Renderer::Shader gBufferPass("Shaders/GBufferPass.vert", "Shaders/GBufferPass.frag", true);
                gBufferPass.addUniformLocation("modelview");
                gBufferPass.addUniformLocation("projection");
            Renderer::Shader ssaoPass("Shaders/SSAOPass.vert", "Shaders/SSAOPass.frag", true);
                ssaoPass.addUniformLocation("texDepth");
                ssaoPass.addUniformLocation("texNormal");
                ssaoPass.addUniformLocation("texNoise");
                ssaoPass.addUniformLocation("projection");
                ssaoPass.addUniformLocation("invProjection");
                ssaoPass.addUniformLocation("gKernel");
                ssaoPass.addUniformLocation("gSampleRad");
            Renderer::Shader pbrShader("Shaders/PBRShader.vert", "Shaders/PBRShader.frag", true);
                pbrShader.addUniformLocation("texDepth");
                pbrShader.addUniformLocation("texDiffuse");
                pbrShader.addUniformLocation("texNormal");
                pbrShader.addUniformLocation("irradianceMap");
                pbrShader.addUniformLocation("prefilterMap");
                pbrShader.addUniformLocation("brdfLUT");
                for (GLuint i = 0; i < engineLight.size(); i = i + 1) {
                    std::ostringstream index;
                    index << i;
                    pbrShader.addUniformLocation("lights[" + index.str() + "].position");
                    pbrShader.addUniformLocation("lights[" + index.str() + "].intensities");
                    pbrShader.addUniformLocation("lights[" + index.str() + "].direction");
                    pbrShader.addUniformLocation("lights[" + index.str() + "].angle");
                }
                for (unsigned int i = 0; i < World::VoxelTypes::getSize(); i = i + 1) {
                    std::ostringstream index;
                    index << i;
                    pbrShader.addUniformLocation("materials[" + index.str() + "].albedo");
                    pbrShader.addUniformLocation("materials[" + index.str() + "].metallic");
                    pbrShader.addUniformLocation("materials[" + index.str() + "].roughness");
                }
                pbrShader.addUniformLocation("cameraV");
                pbrShader.addUniformLocation("invModelview");
                pbrShader.addUniformLocation("invProjection");
                pbrShader.addUniformLocation("rotation");
                pbrShader.addUniformLocation("numLights");
            Renderer::Shader brdfShader("Shaders/BRDFShader.vert", "Shaders/BRDFShader.frag", true);

            Maths::Matrix4x4<NREfloat> projection, modelview, invProjection, invModelview, rotation;

            Time::Clock engineClock;

            Renderer::EnvironmentMap engineSkybox("Data/SkyBox/Space_HD.hdr", captureShader, irradianceShader, prefilterShader, brdfShader);

            camera.computeProjectionMatrix(projection);

            Renderer::DeferredRenderer engineDeferredRenderer(Maths::Vector2D<NREfloat>(1280.0, 720.0));

            NREfloat skyboxAngleX = 0.0;
            int colorAngle = 0, nbFrames = 0;

            glViewport(0, 0, 1280.0, 720.0);

            camera.Keyboard::getKey(SDL_SCANCODE_E).setSwitch(true);
            camera.Keyboard::getKey(SDL_SCANCODE_F).setAction(new Command<World::World>(&engineWorld, World::World::shiftChunksLeft));
            camera.Keyboard::getKey(SDL_SCANCODE_H).setAction(new Command<World::World>(&engineWorld, World::World::shiftChunksRight));
            camera.Keyboard::getKey(SDL_SCANCODE_G).setAction(new Command<World::World>(&engineWorld, World::World::shiftChunksBack));
            camera.Keyboard::getKey(SDL_SCANCODE_T).setAction(new Command<World::World>(&engineWorld, World::World::shiftChunksFront));

            GL::IBO* oTIBO = new GL::IBO(true);
            oTIBO->push_back(new GL::MaterialBuffer(true));
            oTIBO->push_back(new GL::NormalBuffer(true));

            Object::Mesh* oTMesh = new Object::Mesh();
            oTMesh->push_back(new Object::MaterialData());
            oTMesh->push_back(new Object::NormalData());
            oTMesh->push_back(new Object::IndexData());

            Object::Object oT(oTIBO, oTMesh, GL_INT);

            GLint vData[24] = {
                -10, -10, -10,
                -10, -10, 10,
                -10, 10, -10,
                -10, 10, 10,
                10, 10, 10,
                10, 10, -10,
                10, -10, 10,
                10, -10, -10
            };

            GLuint iData[36] = {
                7, 0, 2, 2, 5, 7,
                2, 0, 1, 1, 3, 2,
                4, 6, 7, 7, 5, 4,
                4, 3, 1, 1, 6, 4,
                4, 5, 2, 2, 3, 4,
                0, 7, 1, 1, 7, 6,
            };

            GLbyte nData[24] = {
                1, 0, 0,
                1, 0, 0,
                1, 0, 0,
                1, 0, 0,
                1, 0, 0,
                1, 0, 0
            };

            GLubyte mData[8] = {
                11, 11, 11, 11, 11, 11, 11, 11,
            };

            oT.add(0, vData, 24);
            oT.add(1, mData, 8);
            oT.add(2, nData, 24);
            oT.add(3, iData, 36);

            oT.allocateAndFill(GL_STREAM_DRAW);

            while(!camera.getQuit())
            {
                engineClock.updateActualTime();
                nbFrames = nbFrames + 1;

                if (engineClock.getActualTime() - engineClock.getLastTime() >= 1000.0) {
                    std::cout << 1000.0 / nbFrames << "ms / frame" << std::endl;
                    nbFrames = 0;
                    engineClock.setLastTime(engineClock.getLastTime() + 1000.0);
                }
                //engineClock.updateTimestep(1000.0 / 60.0);

                camera.update();

                colorAngle = colorAngle + 1;
                colorAngle = colorAngle % 360;

                skyboxAngleX += 0.01;
                if (skyboxAngleX >= 360) {
                    skyboxAngleX = 0.0;
                }
                rotation.setIdentity();

                Color::HSL color(colorAngle, 1.0, 0.5);
                Color::RGB colorRGB(color);
                Maths::Vector3D<NREfloat> tmpColor((static_cast <NREfloat> (colorRGB.getR() / 255.0)) * 4000.0,
                                                   (static_cast <NREfloat> (colorRGB.getG() / 255.0)) * 4000.0,
                                                   (static_cast <NREfloat> (colorRGB.getB() / 255.0)) * 4000.0);
                engineLight5.setIntensities(tmpColor);

                rotation.rotate(-skyboxAngleX, Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0));

                engineLight1.setPosition(rotation * Maths::Vector3D<NREfloat>(0, 0, 300));

                rotation.rotate(skyboxAngleX, Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0));
                rotation.rotate(skyboxAngleX, Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0));

                modelview.setIdentity();
                camera.setView(modelview);

                engineDeferredRenderer.startGBufferPass();
                    //engineWorld.render(gBufferPass, modelview, projection, &camera);
                    gBufferPass.bind();
                        gBufferPass.useMat4("modelview", 1, &modelview);
                        gBufferPass.useMat4("projection", 1, &projection);
                        oT.draw();
                    gBufferPass.unbind();
                    Maths::Matrix4x4<NREfloat> tmp(modelview);
                    modelview = modelview * rotation;
                    engineSkybox.render(skyBoxShader, projection, modelview);
                    modelview = tmp;
                engineDeferredRenderer.endGBufferPass();

                invProjection = projection;
                invProjection.inverse();
                invModelview = modelview;
                invModelview.inverse();

                engineDeferredRenderer.SSAOPass(ssaoPass, projection, invProjection);

                engineDeferredRenderer.render(pbrShader, invModelview, invProjection, rotation, camera, engineLight, engineSkybox);

                engineWorld.update(1);

                engineStage.updateScreen();
            }
        }
        catch (Exception::ExceptionHandler const& e) {
            std::cout << e.what() << std::endl;
        }
        catch (std::exception const& e) {
            std::cout << e.what() << std::endl;
        }

        World::VoxelTypes::free();

        return 0;
    }
