void spawn_jogador()
{

        GLint model_uniform           = glGetUniformLocation(g_GpuProgramID, "model"); // Vari�vel da matriz "model"
        GLint render_as_black_uniform = glGetUniformLocation(g_GpuProgramID, "render_as_black");

        glm::mat4 model = Matrix_Identity(); // Transforma��o inicial = identidade.

        // Transla��o inicial do torso
        model = model * Matrix_Translate(g_TorsoPositionX, g_TorsoPositionY, 0.0f);
        // Guardamos matriz model atual na pilha
        PushMatrix(model);
            // Atualizamos a matriz model (multiplica��o � direita) para fazer um escalamento do torso
            model = model * Matrix_Scale(0.8f/3, 1.0f/3, 0.2f/3);
            // Enviamos a matriz "model" para a placa de v�deo (GPU). Veja o
            // arquivo "shader_vertex.glsl", onde esta � efetivamente
            // aplicada em todos os pontos.
            glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model));
            // Desenhamos um cubo. Esta renderiza��o ir� executar o Vertex
            // Shader definido no arquivo "shader_vertex.glsl", e o mesmo ir�
            // utilizar as matrizes "model", "view" e "projection" definidas
            // acima e j� enviadas para a placa de v�deo (GPU).
            DrawCube(render_as_black_uniform); // #### TORSO
        // Tiramos da pilha a matriz model guardada anteriormente
        PopMatrix(model);

        // CABE�A
        PushMatrix(model);
            model = model * Matrix_Translate(0.0f/3, 0.31f/3, 0.0f/3);
            //model = model // Atualizamos matriz model (multiplica��o � direita) com a rota��o do bra�o direito
            //        * Matrix_Rotate_Z(g_AngleZ + M_PI)  // TERCEIRO rota��o Z de Euler
            //        * Matrix_Rotate_Y(g_AngleY)  // SEGUNDO rota��o Y de Euler
            //        * Matrix_Rotate_X(g_AngleX); // PRIMEIRO rota��o X de Euler
            model = model * Matrix_Scale(0.28f/3, 0.28f/3, 0.28f/3); // Atualizamos matriz model (multiplica��o � direita) com um escalamento do bra�o direito
            glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
            DrawCube(render_as_black_uniform); // #### Desenha cabe�a
        PopMatrix(model);


        // BRA�O DIREITO
        PushMatrix(model); // Guardamos matriz model atual na pilha
            model = model * Matrix_Translate(-0.55f/3, 0.0f/3, 0.0f/3); // Atualizamos matriz model (multiplica��o � direita) com uma transla��o para o bra�o direito
            PushMatrix(model); // Guardamos matriz model atual na pilha
                model = model // Atualizamos matriz model (multiplica��o � direita) com a rota��o do bra�o direito
                      * Matrix_Rotate_Z(g_AngleZ)  // TERCEIRO rota��o Z de Euler
                      * Matrix_Rotate_Y(g_AngleY)  // SEGUNDO rota��o Y de Euler
                      * Matrix_Rotate_X(g_AngleX); // PRIMEIRO rota��o X de Euler
                PushMatrix(model); // Guardamos matriz model atual na pilha
                    model = model * Matrix_Scale(0.2f/3, 0.6f/3, 0.2f/3); // Atualizamos matriz model (multiplica��o � direita) com um escalamento do bra�o direito
                    glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                    DrawCube(render_as_black_uniform); // #### BRA�O DIREITO // Desenhamos o bra�o direito
                PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
                PushMatrix(model); // Guardamos matriz model atual na pilha
                    model = model * Matrix_Translate(0.0f/3, -0.65f/3, 0.0f/3); // Atualizamos matriz model (multiplica��o � direita) com a transla��o do antebra�o direito
                    model = model // Atualizamos matriz model (multiplica��o � direita) com a rota��o do antebra�o direito
                          * Matrix_Rotate_Z(g_ForearmAngleZ)  // SEGUNDO rota��o Z de Euler
                          * Matrix_Rotate_X(g_ForearmAngleX); // PRIMEIRO rota��o X de Euler
                    PushMatrix(model); // Guardamos matriz model atual na pilha
                        model = model * Matrix_Scale(0.2f/3, 0.6f/3, 0.2f/3); // Atualizamos matriz model (multiplica��o � direita) com um escalamento do antebra�o direito
                        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                        DrawCube(render_as_black_uniform); // #### ANTEBRA�O DIREITO // Desenhamos o antebra�o direito

                    // M�O DIREITA
                    PopMatrix(model);
                    PushMatrix(model);
                        model = model * Matrix_Translate(0.0f/3, -0.65f/3, 0.0f/3);
                        model = model * Matrix_Scale(0.2f/3, 0.1f/3, 0.2f/3); // Atualizamos matriz model (multiplica��o � direita) com um escalamento do antebra�o direito
                        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                        DrawCube(render_as_black_uniform); // #### MAO DIREITA

                    PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
                PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
            PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
        PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente


        // BRA�O ESQUERDO
        PushMatrix(model); // Guardamos matriz model atual na pilha
            model = model * Matrix_Translate(0.55f/3, 0.0f/3, 0.0f/3); // Atualizamos matriz model (multiplica��o � direita) com uma transla��o para o bra�o direito
            PushMatrix(model); // Guardamos matriz model atual na pilha
                model = model // Atualizamos matriz model (multiplica��o � direita) com a rota��o do bra�o direito
                      * Matrix_Rotate_Z(-g_AngleZ)  // TERCEIRO rota��o Z de Euler
                      * Matrix_Rotate_Y(g_AngleY)  // SEGUNDO rota��o Y de Euler
                      * Matrix_Rotate_X(g_AngleX); // PRIMEIRO rota��o X de Euler
                PushMatrix(model); // Guardamos matriz model atual na pilha
                    model = model * Matrix_Scale(0.2f/3, 0.6f/3, 0.2f/3); // Atualizamos matriz model (multiplica��o � direita) com um escalamento do bra�o direito
                    glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                    DrawCube(render_as_black_uniform); // #### BRA�O ESQUERDO
                PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
                PushMatrix(model); // Guardamos matriz model atual na pilha
                    model = model * Matrix_Translate(0.0f/3, -0.65f/3, 0.0f/3); // Atualizamos matriz model (multiplica��o � direita) com a transla��o do antebra�o direito
                    model = model // Atualizamos matriz model (multiplica��o � direita) com a rota��o do antebra�o direito
                          * Matrix_Rotate_Z(-g_ForearmAngleZ)  // SEGUNDO rota��o Z de Euler
                          * Matrix_Rotate_X(g_ForearmAngleX); // PRIMEIRO rota��o X de Euler
                    PushMatrix(model); // Guardamos matriz model atual na pilha
                        model = model * Matrix_Scale(0.2f/3, 0.6f/3, 0.2f/3); // Atualizamos matriz model (multiplica��o � direita) com um escalamento do antebra�o direito
                        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                        DrawCube(render_as_black_uniform); // #### ANTEBRA�O ESQUERDO

                    // M�O ESQUERDA
                    PopMatrix(model);
                    PushMatrix(model);
                        model = model * Matrix_Translate(0.0f/3, -0.65f/3, 0.0f/3);
                        model = model * Matrix_Scale(0.2f/3, 0.1f/3, 0.2f/3); // Atualizamos matriz model (multiplica��o � direita) com um escalamento do antebra�o direito
                        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                        DrawCube(render_as_black_uniform); // #### MAO ESQUERDA


                    PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
                PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
            PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
        PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente

        // PERNA DIREITA
        PushMatrix(model); // Guardamos matriz model atual na pilha
            model = model * Matrix_Translate(-0.20f/3, -1.05f/3, 0.0f/3); // Atualizamos matriz model (multiplica��o � direita) com uma transla��o para o bra�o direito
            PushMatrix(model); // Guardamos matriz model atual na pilha
                model = model * Matrix_Scale(0.3f/3, 0.7f/3, 0.3f/3); // Atualizamos matriz model (multiplica��o � direita) com um escalamento do bra�o direito
                glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                DrawCube(render_as_black_uniform); // #### COXA DIREITA
            PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
            PushMatrix(model); // Guardamos matriz model atual na pilha
                model = model * Matrix_Translate(0.0f/3, -0.75f/3, 0.0f/3); // Atualizamos matriz model (multiplica��o � direita) com a transla��o do antebra�o direito
                PushMatrix(model); // Guardamos matriz model atual na pilha
                        model = model * Matrix_Scale(0.25f/3, 0.6f/3, 0.25f/3); // Atualizamos matriz model (multiplica��o � direita) com um escalamento do antebra�o direito
                        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                        DrawCube(render_as_black_uniform); // #### CANELA DIREITA

                // P� DIREITO
                PopMatrix(model);
                PushMatrix(model);
                    model = model * Matrix_Translate(0.0f/3, -0.65f/3, 0.1f/3);
                    model = model * Matrix_Scale(0.2f/3, 0.1f/3, 0.5f/3); // Atualizamos matriz model (multiplica��o � direita) com um escalamento do antebra�o direito
                    glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                    DrawCube(render_as_black_uniform); // #### P� DIREITO

                    PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
            PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
        PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente

        // PERNA ESQUERDA
        PushMatrix(model); // Guardamos matriz model atual na pilha
            model = model * Matrix_Translate(0.20f/3, -1.05f/3, 0.0f/3); // Atualizamos matriz model (multiplica��o � direita) com uma transla��o para o bra�o direito
            PushMatrix(model); // Guardamos matriz model atual na pilha
                model = model * Matrix_Scale(0.3f/3, 0.7f/3, 0.3f/3); // Atualizamos matriz model (multiplica��o � direita) com um escalamento do bra�o direito
                glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                DrawCube(render_as_black_uniform); // #### COXA ESQUERDA
            PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
            PushMatrix(model); // Guardamos matriz model atual na pilha
                model = model * Matrix_Translate(0.0f/3, -0.75f/3, 0.0f/3); // Atualizamos matriz model (multiplica��o � direita) com a transla��o do antebra�o direito
                PushMatrix(model); // Guardamos matriz model atual na pilha
                        model = model * Matrix_Scale(0.25f/3, 0.6f/3, 0.25f/3); // Atualizamos matriz model (multiplica��o � direita) com um escalamento do antebra�o direito
                        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                        DrawCube(render_as_black_uniform); // #### CANELA ESQUERDA

                // P� ESQUERDO
                PopMatrix(model);
                PushMatrix(model);
                    model = model * Matrix_Translate(0.0f/3, -0.65f/3, 0.1f/3);
                    model = model * Matrix_Scale(0.2f/3, 0.1f/3, 0.5f/3); // Atualizamos matriz model (multiplica��o � direita) com um escalamento do antebra�o direito
                    glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model)); // Enviamos matriz model atual para a GPU
                    DrawCube(render_as_black_uniform); // #### P� ESQUERDO

                    PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
            PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente
        PopMatrix(model); // Tiramos da pilha a matriz model guardada anteriormente

        // Neste ponto a matriz model recuperada � a matriz inicial (transla��o do torso)

        // Agora queremos desenhar os eixos XYZ de coordenadas GLOBAIS.
        // Para tanto, colocamos a matriz de modelagem igual � identidade.
        // Veja slides 2-14 e 184-190 do documento Aula_08_Sistemas_de_Coordenadas.pdf.
        model = Matrix_Identity();

        // Enviamos a nova matriz "model" para a placa de v�deo (GPU). Veja o
        // arquivo "shader_vertex.glsl".
        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model));

        // Pedimos para OpenGL desenhar linhas com largura de 10 pixels.
        glLineWidth(10.0f);

        // Informamos para a placa de v�deo (GPU) que a vari�vel booleana
        // "render_as_black" deve ser colocada como "false". Veja o arquivo
        // "shader_vertex.glsl".
        glUniform1i(render_as_black_uniform, false);

        // Pedimos para a GPU rasterizar os v�rtices dos eixos XYZ
        // apontados pelo VAO como linhas. Veja a defini��o de
        // g_VirtualScene["axes"] dentro da fun��o BuildTriangles(), e veja
        // a documenta��o da fun��o glDrawElements() em
        // http://docs.gl/gl3/glDrawElements.
        //glDrawElements(
        //    g_VirtualScene["axes"].rendering_mode,
        //    g_VirtualScene["axes"].num_indices,
        //    GL_UNSIGNED_INT,
        //    (void*)g_VirtualScene["axes"].first_index
        //);

        // "Desligamos" o VAO, evitando assim que opera��es posteriores venham a
        // alterar o mesmo. Isso evita bugs.
        glBindVertexArray(0);

}
