void spawn_jogador()
{

        GLint model_uniform           = glGetUniformLocation(g_GpuProgramID, "model"); // Variável da matriz "model"
        GLint render_as_black_uniform = glGetUniformLocation(g_GpuProgramID, "render_as_black");

        glm::mat4 model = Matrix_Identity(); // Transformação inicial = identidade.

        // Translação inicial do torso
        model = model * Matrix_Translate(g_TorsoPositionX, g_TorsoPositionY, 0.0f);
        // Guardamos matriz model atual na pilha
        PushMatrix(model);
            // Atualizamos a matriz model (multiplicação à direita) para fazer um escalamento do torso
            model = model * Matrix_Scale(0.8f/3, 1.0f/3, 0.2f/3);
            // Enviamos a matriz "model" para a placa de vídeo (GPU). Veja o
            // arquivo "shader_vertex.glsl", onde esta é efetivamente
            // aplicada em todos os pontos.
            glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model));
            // Desenhamos um cubo. Esta renderização irá executar o Vertex
            // Shader definido no arquivo "shader_vertex.glsl", e o mesmo irá
            // utilizar as matrizes "model", "view" e "projection" definidas
            // acima e já enviadas para a placa de vídeo (GPU).
            DrawCube(render_as_black_uniform); // #### TORSO
        // Tiramos da pilha a matriz model guardada anteriormente
        PopMatrix(model);

        // CABEÇA
        PushMatrix(model);
            model = model * Matrix_Translate(0.0f/3, 0.31f/3, 0.0f/3);
            //model = model // Atualizamos matriz model (multiplicação à direita) com a rotação do braço direito
            //        * Matrix_Rotate_Z(g_AngleZ + M_PI)  // TERCEIRO rotação Z de Euler
            //        * Matrix_Rotate_Y(g_AngleY)  // SEGUNDO rotação Y de Euler
            //        * Matrix_Rotate_X(g_AngleX); // PRIMEIRO rotação X de Euler
            model = model * Matrix_Scale(0.28f/3, 0.28f/3, 0.28f/3); // Atualizamos matriz model (multiplicação à direita) com um escalamento do braço direito
            glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
            DrawCube(render_as_black_uniform); // #### Desenha cabeça
        PopMatrix(model);


        // BRAÇO DIREITO
        PushMatrix(model); // Guardamos matriz model atual na pilha
            model = model * Matrix_Translate(-0.55f/3, 0.0f/3, 0.0f/3); // Atualizamos matriz model (multiplicação à direita) com uma translação para o braço direito
            PushMatrix(model); // Guardamos matriz model atual na pilha
                model = model // Atualizamos matriz model (multiplicação à direita) com a rotação do braço direito
                      * Matrix_Rotate_Z(g_AngleZ)  // TERCEIRO rotação Z de Euler
                      * Matrix_Rotate_Y(g_AngleY)  // SEGUNDO rotação Y de Euler
                      * Matrix_Rotate_X(g_AngleX); // PRIMEIRO rotação X de Euler
                PushMatrix(model); // Guardamos matriz model atual na pilha
                    model = model * Matrix_Scale(0.2f/3, 0.6f/3, 0.2f/3); // Atualizamos matriz model (multiplicação à direita) com um escalamento do braço direito
                    glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                    DrawCube(render_as_black_uniform); // #### BRAÇO DIREITO // Desenhamos o braço direito
                PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
                PushMatrix(model); // Guardamos matriz model atual na pilha
                    model = model * Matrix_Translate(0.0f/3, -0.65f/3, 0.0f/3); // Atualizamos matriz model (multiplicação à direita) com a translação do antebraço direito
                    model = model // Atualizamos matriz model (multiplicação à direita) com a rotação do antebraço direito
                          * Matrix_Rotate_Z(g_ForearmAngleZ)  // SEGUNDO rotação Z de Euler
                          * Matrix_Rotate_X(g_ForearmAngleX); // PRIMEIRO rotação X de Euler
                    PushMatrix(model); // Guardamos matriz model atual na pilha
                        model = model * Matrix_Scale(0.2f/3, 0.6f/3, 0.2f/3); // Atualizamos matriz model (multiplicação à direita) com um escalamento do antebraço direito
                        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                        DrawCube(render_as_black_uniform); // #### ANTEBRAÇO DIREITO // Desenhamos o antebraço direito

                    // MÃO DIREITA
                    PopMatrix(model);
                    PushMatrix(model);
                        model = model * Matrix_Translate(0.0f/3, -0.65f/3, 0.0f/3);
                        model = model * Matrix_Scale(0.2f/3, 0.1f/3, 0.2f/3); // Atualizamos matriz model (multiplicação à direita) com um escalamento do antebraço direito
                        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                        DrawCube(render_as_black_uniform); // #### MAO DIREITA

                    PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
                PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
            PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
        PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente


        // BRAÇO ESQUERDO
        PushMatrix(model); // Guardamos matriz model atual na pilha
            model = model * Matrix_Translate(0.55f/3, 0.0f/3, 0.0f/3); // Atualizamos matriz model (multiplicação à direita) com uma translação para o braço direito
            PushMatrix(model); // Guardamos matriz model atual na pilha
                model = model // Atualizamos matriz model (multiplicação à direita) com a rotação do braço direito
                      * Matrix_Rotate_Z(-g_AngleZ)  // TERCEIRO rotação Z de Euler
                      * Matrix_Rotate_Y(g_AngleY)  // SEGUNDO rotação Y de Euler
                      * Matrix_Rotate_X(g_AngleX); // PRIMEIRO rotação X de Euler
                PushMatrix(model); // Guardamos matriz model atual na pilha
                    model = model * Matrix_Scale(0.2f/3, 0.6f/3, 0.2f/3); // Atualizamos matriz model (multiplicação à direita) com um escalamento do braço direito
                    glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                    DrawCube(render_as_black_uniform); // #### BRAÇO ESQUERDO
                PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
                PushMatrix(model); // Guardamos matriz model atual na pilha
                    model = model * Matrix_Translate(0.0f/3, -0.65f/3, 0.0f/3); // Atualizamos matriz model (multiplicação à direita) com a translação do antebraço direito
                    model = model // Atualizamos matriz model (multiplicação à direita) com a rotação do antebraço direito
                          * Matrix_Rotate_Z(-g_ForearmAngleZ)  // SEGUNDO rotação Z de Euler
                          * Matrix_Rotate_X(g_ForearmAngleX); // PRIMEIRO rotação X de Euler
                    PushMatrix(model); // Guardamos matriz model atual na pilha
                        model = model * Matrix_Scale(0.2f/3, 0.6f/3, 0.2f/3); // Atualizamos matriz model (multiplicação à direita) com um escalamento do antebraço direito
                        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                        DrawCube(render_as_black_uniform); // #### ANTEBRAÇO ESQUERDO

                    // MÃO ESQUERDA
                    PopMatrix(model);
                    PushMatrix(model);
                        model = model * Matrix_Translate(0.0f/3, -0.65f/3, 0.0f/3);
                        model = model * Matrix_Scale(0.2f/3, 0.1f/3, 0.2f/3); // Atualizamos matriz model (multiplicação à direita) com um escalamento do antebraço direito
                        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                        DrawCube(render_as_black_uniform); // #### MAO ESQUERDA


                    PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
                PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
            PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
        PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente

        // PERNA DIREITA
        PushMatrix(model); // Guardamos matriz model atual na pilha
            model = model * Matrix_Translate(-0.20f/3, -1.05f/3, 0.0f/3); // Atualizamos matriz model (multiplicação à direita) com uma translação para o braço direito
            PushMatrix(model); // Guardamos matriz model atual na pilha
                model = model * Matrix_Scale(0.3f/3, 0.7f/3, 0.3f/3); // Atualizamos matriz model (multiplicação à direita) com um escalamento do braço direito
                glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                DrawCube(render_as_black_uniform); // #### COXA DIREITA
            PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
            PushMatrix(model); // Guardamos matriz model atual na pilha
                model = model * Matrix_Translate(0.0f/3, -0.75f/3, 0.0f/3); // Atualizamos matriz model (multiplicação à direita) com a translação do antebraço direito
                PushMatrix(model); // Guardamos matriz model atual na pilha
                        model = model * Matrix_Scale(0.25f/3, 0.6f/3, 0.25f/3); // Atualizamos matriz model (multiplicação à direita) com um escalamento do antebraço direito
                        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                        DrawCube(render_as_black_uniform); // #### CANELA DIREITA

                // PÉ DIREITO
                PopMatrix(model);
                PushMatrix(model);
                    model = model * Matrix_Translate(0.0f/3, -0.65f/3, 0.1f/3);
                    model = model * Matrix_Scale(0.2f/3, 0.1f/3, 0.5f/3); // Atualizamos matriz model (multiplicação à direita) com um escalamento do antebraço direito
                    glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                    DrawCube(render_as_black_uniform); // #### PÉ DIREITO

                    PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
            PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
        PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente

        // PERNA ESQUERDA
        PushMatrix(model); // Guardamos matriz model atual na pilha
            model = model * Matrix_Translate(0.20f/3, -1.05f/3, 0.0f/3); // Atualizamos matriz model (multiplicação à direita) com uma translação para o braço direito
            PushMatrix(model); // Guardamos matriz model atual na pilha
                model = model * Matrix_Scale(0.3f/3, 0.7f/3, 0.3f/3); // Atualizamos matriz model (multiplicação à direita) com um escalamento do braço direito
                glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                DrawCube(render_as_black_uniform); // #### COXA ESQUERDA
            PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
            PushMatrix(model); // Guardamos matriz model atual na pilha
                model = model * Matrix_Translate(0.0f/3, -0.75f/3, 0.0f/3); // Atualizamos matriz model (multiplicação à direita) com a translação do antebraço direito
                PushMatrix(model); // Guardamos matriz model atual na pilha
                        model = model * Matrix_Scale(0.25f/3, 0.6f/3, 0.25f/3); // Atualizamos matriz model (multiplicação à direita) com um escalamento do antebraço direito
                        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                        DrawCube(render_as_black_uniform); // #### CANELA ESQUERDA

                // PÉ ESQUERDO
                PopMatrix(model);
                PushMatrix(model);
                    model = model * Matrix_Translate(0.0f/3, -0.65f/3, 0.1f/3);
                    model = model * Matrix_Scale(0.2f/3, 0.1f/3, 0.5f/3); // Atualizamos matriz model (multiplicação à direita) com um escalamento do antebraço direito
                    glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                    DrawCube(render_as_black_uniform); // #### PÉ ESQUERDO

                    PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
            PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
        PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente

        // Neste ponto a matriz model recuperada é a matriz inicial (translação do torso)

        // Agora queremos desenhar os eixos XYZ de coordenadas GLOBAIS.
        // Para tanto, colocamos a matriz de modelagem igual à identidade.
        // Veja slides 2-14 e 184-190 do documento Aula_08_Sistemas_de_Coordenadas.pdf.
        model = Matrix_Identity();

        // Enviamos a nova matriz "model" para a placa de vídeo (GPU). Veja o
        // arquivo "shader_vertex.glsl".
        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model));

        // Pedimos para OpenGL desenhar linhas com largura de 10 pixels.
        glLineWidth(10.0f);

        // Informamos para a placa de vídeo (GPU) que a variável booleana
        // "render_as_black" deve ser colocada como "false". Veja o arquivo
        // "shader_vertex.glsl".
        glUniform1i(render_as_black_uniform, false);

        // Pedimos para a GPU rasterizar os vértices dos eixos XYZ
        // apontados pelo VAO como linhas. Veja a definição de
        // g_VirtualScene["axes"] dentro da função BuildTriangles(), e veja
        // a documentação da função glDrawElements() em
        // http://docs.gl/gl3/glDrawElements.
        //glDrawElements(
        //    g_VirtualScene["axes"].rendering_mode,
        //    g_VirtualScene["axes"].num_indices,
        //    GL_UNSIGNED_INT,
        //    (void*)g_VirtualScene["axes"].first_index
        //);

        // "Desligamos" o VAO, evitando assim que operações posteriores venham a
        // alterar o mesmo. Isso evita bugs.
        glBindVertexArray(0);

}
