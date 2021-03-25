# Histogramas

Este programa escrito em C++, trata de analizar uma determinada imagem para poder gerar o seu histogramas, entretanto, ao invés de gerar apenas o histograma (forma grafica); os seus valores são salvos em quatro arquivos **.txt**: um para a cor vermelha (*red*), verde (*green*), azul (*blue*) e em escala de cinza.  Este programa mescla dois codigos (que se encontram na pasta chamada ***source***): Um codigo retorna somente o valores do histograma escala de cinza, enquanto o outro codigo retorna o histograma **RGB** da fotografia. Sendo preciso trabalhar com os valores de cada histograma separadamente. 

```
Exemplo do nome dos arquivos:

Escala de cinza: NomeDaFoto.txt
Vermelho: r_NomeDaFoto.txt
Verde: g_NomeDaFoto.txt
Azul: b_NomeDaFoto.txt

```

Na fotografia, o histograma é usado para saber se há muita luz e onde há muita sombra. Alguns programas de edição permite apontar para uma determinada região da foto e com isso gerar o histograma para ser possivel ver se há muita luz ou sombra. 

> Histograma é um gráfico que mede a luminosidade da foto, auxiliando na obtenção de uma melhor exposição da imagem.
>
> Como os visores das câmeras mostram uma imagem compactada de baixa  qualidade, muitas vezes o que vemos nesses visores não é o real: podemos achar que a foto está boa, mas pode haver falta ou excesso de luz.
>
> Por meio do histograma, podemos corrigir isso, verificar o tipo de luz (dura ou suave) e medir os tons de cinza.
>
> Erica Dal Bello - [PhotoPro](https://www.photopro.com.br/)

## Como Usar

Para compilar e rodar o programa é preciso instalar e configurar a biblioteca chamada [**OpenCV**](https://opencv.org/), do qual visa tornar a computação visual em tempo-real optimizada. A [documentação](https://docs.opencv.org/master/d9/df8/tutorial_root.html) ensina como instalar dentre outras coisas interesantes que a biblioteca permite fazer,  porém para este projeto (e outro que trabalham com **OpenCV**) é preciso configurar no [**IDE** ***Visual Studio***](https://docs.opencv.org/master/dd/d6e/tutorial_windows_visual_studio_opencv.html).  

  

