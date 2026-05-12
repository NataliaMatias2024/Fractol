<h1 align="center">
    <img alt="fract-ol" width="200px" src="https://raw.githubusercontent.com/NataliaMatias2024/42-project-badges/main/badges/fract-ole.png">
</h1>

# ❄️ Fract-ol - @42SP
**Score:** 100/100 ✅

Este repositório contém um explorador de fractais desenvolvido em C com a biblioteca gráfica MiniLibX para o projeto `fract-ol` do currículo da [42 São Paulo](https://www.42sp.org.br/).       
O projeto implementa renderização pixel a pixel utilizando aritmética de números complexos, permitindo a visualização interativa de conjuntos matemáticos famosos.

## 🚀 Objetivos

> - Renderizar conjuntos de fractais (Mandelbrot e Julia) utilizando fórmulas matemáticas complexas.
> - Implementar um sistema de zoom suave a partir do scroll do mouse.
> - Gerenciar o buffer de imagem da MiniLibX para otimizar a velocidade de renderização.
> - Criar uma interface responsiva a eventos de teclado (movimentação, troca de cores e reset).

## 🛠️ Tecnologias e Conceitos
<div align="left">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C" />
  <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="Linux" />
</div>

> - **Complex Numbers:** Implementação manual de soma e quadrado de números complexos para iterar a fórmula $$z_{n+1} = z_n^2 + c$$.
> - **MiniLibX (X11):** Manipulação de janelas, hooks de eventos e buffers de imagem no sistema gráfico do Linux.
> - **Event Hooks:** Uso de mlx_hook para capturar eventos de teclado, mouse e fechamento de janela (X-Notify) de forma assíncrona.
> - **Pixel Buffer:** Escrita direta no endereço de memória da imagem (pixels_ptr) para otimizar o tempo de renderização antes de enviar o frame para a janela.

## 📁 Estrutura do Projeto

```bash
.
├── Libs/              # biblioteca reutilizável
├── minilibx-linux     # biblioteca para projetos gráficos
├── src/               # Código-fonte do projeto (.c)
├── Makefile           # Automação de compilação (all, clean, fclean, re)
└── README.md          # Este arquivo
```

## ⚙️ Compilação e Uso

### 1. Pré-requisitos
No Linux (WSL/Ubuntu), é necessário instalar as dependências da X11:
```bash
$ sudo apt-get install libx11-dev libxext-dev zlib1g-dev libbsd-dev
```

### 2. Compilação gera o arquivo executável `fractol`
```bash
$ make
```

### 3. Executar
O programa aceita parâmetros para definir o tipo de fractal e coordenadas iniciais

```bash
# Para o conjunto de Mandelbrot
$ ./fractol mandelbrot
```
<p  align="center">
  <img width="458" height="342" alt="image mandelbrot" src="https://github.com/user-attachments/assets/3c19e735-985d-4d93-b001-d528f141eee9" />
</p>

```bash
# Para o conjunto de Julia
$ ./fractol julia [valor_real] [valor_imaginario]

# Exemplos
$ ./fractol julia -0.5125 0.5213
```
<p  align="center">
  <img width="458" height="342" alt="image julia" src="https://github.com/user-attachments/assets/deb91d99-838e-4cb9-ab37-2a9c00e33032" />
</p>

## 🎮 Controles Interativos

|Comando              | Ação                                       |
|---------------------|--------------------------------------------|
| `Setas (↑, ↓, ←, →)`| Movimentação pelo plano complexo           |
| `Mouse Scroll`      | Zoom In e Zoom Out                         |
| `Teclas + / -`      | Aumentar ou diminuir a precisão (iterações)|
| `ESC`               | Fecha o programa de forma segura           |


## 🧠 Lições Aprendidas

**- Matemática de Baixo Nível:** Transformar fórmulas matemáticas abstratas em algoritmos de renderização, lidando com a performance de operações de ponto flutuante.

**- Gerenciamento de Pixel Buffer:** Entender como a memória de vídeo é estruturada e como escrever cores diretamente no buffer de imagem para otimizar o output gráfico.

**- Arquitetura de Sistemas:** Lidar com dependências externas (X11), automação de Makefiles e a importância de um ambiente de desenvolvimento bem configurado (Linux/WSL).

**- Resiliência e Debug:** A experiência de configurar o ambiente gráfico e sincronizar bibliotecas de sistema reforçou minha habilidade em resolver problemas de infraestrutura de software.

