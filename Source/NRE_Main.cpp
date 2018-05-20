
    #include "Support/Stage/NRE_Stage.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "World/NRE_World.hpp"
    #include "Time/Clock/NRE_Clock.hpp"
    #include "Renderer/DeferredRenderer/NRE_DeferredRenderer.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        try {
            Support::Stage engineStage("NRE 0.1 - Dev version", Maths::Vector2D<int>(1280, 720));
            World::World engineWorld(Maths::Vector2D<GLuint>(5, 5), Maths::Vector2D<GLint>(0, 0));

            Camera::MoveableCamera camera(70.0, 1280.0 / 720.0, Maths::Vector2D<NREfloat>(0.1, 2000.0), Maths::Vector3D<NREfloat>(0, 1, 100), Maths::Vector3D<NREfloat>(0, 0, 100), &engineWorld);

            std::vector<Light::Light*> engineLight;
            Light::DirectionnalLight engineLight1(Maths::Point3D<NREfloat>(0, 0, 300),Maths::Vector3D<NREfloat>(0.06, 0.16, 0.5), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0));
            Light::PointLight engineLight2(Maths::Point3D<NREfloat>(29.7,  28.0, 29.0), Maths::Vector3D<NREfloat>(400.0, 0.0, 0.0));
            Light::PointLight engineLight3(Maths::Point3D<NREfloat>(71.6,  41.7, 29.0), Maths::Vector3D<NREfloat>(0.0, 400.0, 0.0));
            Light::PointLight engineLight4(Maths::Point3D<NREfloat>(60.5, -44.8, 29.0), Maths::Vector3D<NREfloat>(0.0, 0.0, 400.0));
            Light::PointLight engineLight5(Maths::Point3D<NREfloat>(50.0, -4.8,  29.0), Maths::Vector3D<NREfloat>(4000.0, 4000.0, 4000.0));
            Light::PointLight engineLight6(Maths::Point3D<NREfloat>(-0.5, -5.0,  28.0), Maths::Vector3D<NREfloat>(4000.0, 4000.0, 4000.0));
            engineLight.push_back(&engineLight1);
            engineLight.push_back(&engineLight2);
            engineLight.push_back(&engineLight3);
            engineLight.push_back(&engineLight4);
            engineLight.push_back(&engineLight5);
            engineLight.push_back(&engineLight6);

            Maths::Matrix4x4<NREfloat> projection, modelview, invProjection, invModelview, rotation, tmp;

            Time::Clock engineClock;

            Renderer::EnvironmentMap engineSkybox("Data/SkyBox/Space_HD.hdr");

            camera.computeProjectionMatrix(projection);

            Renderer::EngineShader::sendProjection(projection);

            Renderer::DeferredRenderer engineDeferredRenderer(Maths::Vector2D<NREfloat>(1280.0, 720.0));

            NREfloat skyboxAngleX = 0.0;
            //int nbFrames = 0;

            std::vector<Object::Object3D*> materialSpheres;

            for (GLuint i = 1; i < World::VoxelTypes::getSize(); i = i + 1) {
                Object::Object3D* sphere = new Object::Object3D();
                sphere->push_back(new Object::Mesh3D(GL_FLOAT));
                sphere->processSphere(GL_STATIC_DRAW, 5, 50, 50, i);
                materialSpheres.push_back(sphere);
            }

            Object::Object3D ironMan;
            ironMan.load(GL_STATIC_DRAW, "Data/Model/IronMan.obj");

            glViewport(0, 0, 1280.0, 720.0);

            Camera::Key& mode = camera.Keyboard::getKey(SDL_SCANCODE_F1);
            mode.setSwitch(true);

            while(!camera.getQuit())
            {
                /*engineClock.updateActualTime();
                nbFrames = nbFrames + 1;

                if (engineClock.getActualTime() - engineClock.getLastTime() >= 1000.0) {
                    std::cout << 1000.0 / nbFrames << "ms / frame" << std::endl;
                    nbFrames = 0;
                    engineClock.setLastTime(engineClock.getLastTime() + 1000.0);
                }*/
                engineClock.updateTimestep(1000.0 / 60.0);

                camera.update();

                camera.travelTo(Maths::Point3D<NREfloat>(-0.5, -5.0,  28.0), 0.5);

                skyboxAngleX += 0.01;
                if (skyboxAngleX >= 360) {
                    skyboxAngleX = 0.0;
                }
                rotation.setIdentity();

                rotation.rotate(-skyboxAngleX, Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0));

                engineLight1.setPosition(rotation * Maths::Vector3D<NREfloat>(0, 0, 300));

                rotation.rotate(skyboxAngleX, Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0));
                rotation.rotate(skyboxAngleX, Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0));

                modelview.setIdentity();
                camera.setView(modelview);

                engineDeferredRenderer.startGBufferPass();
                    if (mode.isActive()) {
                        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                    }
                    //engineWorld.render(modelview, &camera);
                    const Renderer::GBufferShader* const s = static_cast <const Renderer::GBufferShader* const> (Renderer::EngineShader::getShader("GBuffer"));
                    tmp = modelview;
                    tmp.translate(Maths::Vector3D<NREfloat>(0, -85, 100));
                    for (GLuint i = 0; i < materialSpheres.size(); i = i + 1) {
                        s->bind();
                            tmp.translate(Maths::Vector3D<NREfloat>(0, 12, 0));
                            s->sendModelview(tmp);
                            materialSpheres[i]->draw();
                        s->unbind();
                    }
                    s->bind();
                        tmp = modelview;
                        s->sendModelview(tmp);
                        ironMan.draw();
                    s->unbind();

                    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

                    tmp = modelview * rotation;
                    engineSkybox.render(projection, tmp);
                engineDeferredRenderer.endGBufferPass();

                invModelview = modelview;
                invModelview.inverse();

                engineDeferredRenderer.render(invModelview, rotation, camera, engineLight, engineSkybox);

                engineWorld.update(1);

                engineStage.updateScreen();
            }

            for (GLuint i = 0; i < materialSpheres.size(); i = i + 1) {
                delete materialSpheres[i];
            }
        }
        catch (Exception::ExceptionHandler const& e) {
            std::cout << e.what() << std::endl;
        }
        catch (std::exception const& e) {
            std::cout << e.what() << std::endl;
        }

        return 0;
    }
