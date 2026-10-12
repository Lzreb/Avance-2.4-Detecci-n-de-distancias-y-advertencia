![header](https://64.media.tumblr.com/3f2e2ae1825f317768509ed29d455691/d4b79136d0f51ef1-97/s2048x3072/5534a8ef4e8d917c949c598650bc44e1ee3ab499.pnj)

#  Detección de distancias y advertencia


![divider](https://64.media.tumblr.com/c76de97a3dde5841ec75206ce9f260cd/65c2ca21c727c407-e3/s1280x1920/b34250fcfabf92e5fcebc300a0b6c8e7bbf2d07b.pnj)


## Introducción
- En esta práctica realizaremos un circuito utilizando un Arduino UNO, un sensor ultrasónico HC-SR04 y un buzzer. El objetivo es aprender sobre el funcionamiento e implementación de este sensor, tanto para medir la distancia hacia objetos como para usar ese valor para controlar otros módulos, en este caso un Buzzer.

![divider](https://64.media.tumblr.com/c76de97a3dde5841ec75206ce9f260cd/65c2ca21c727c407-e3/s1280x1920/b34250fcfabf92e5fcebc300a0b6c8e7bbf2d07b.pnj)

## Materiales

- Se necesitan los siguientes materiales para llevar acabo este proyecto:

    - Arduino UNO R3
    - Protoboard
    - Sensor Ultrasónico HC-SR04
    - Buzzer (Puede ser activo o pasivo)
    - Jumpers

![divider](https://64.media.tumblr.com/c76de97a3dde5841ec75206ce9f260cd/65c2ca21c727c407-e3/s1280x1920/b34250fcfabf92e5fcebc300a0b6c8e7bbf2d07b.pnj)
## Circuito y Conexiones

Figura 1.1

Pinout del Sensor Ultrasónico

![TinkerCAD](https://cdn.discordapp.com/attachments/1503185091583545355/1559047983394324500/hy-srf05-pinout.png?ex=6acda814&is=6acc5694&hm=8325c1ead6235bbf582e537c650bed8c6c9f204a71b299d45257d8cacdeae1ec&)

- Para usar correctamente este sensor debemos entender el funcionamiento de sus pines, cuenta con los estándar para alimentación y conexión a tierra, más los pines para su control; Trigger y Echo. El pin de Trigger, como su nombre indica, es aquel que recibe la señal del Arduino para emitir el la onda ultrasónica, mientras que Echo se encarga de medir el tiempo que tarda este sonido en regresar al sensor; pasando este valor al Arduino. 

 Figura 1.2

 Diagrama del circuito y conexiones

 ![TinkerCAD2](https://media.discordapp.net/attachments/1503185091583545355/1559048245626273812/image.png?ex=6acda853&is=6acc56d3&hm=3b641ee82270e30868682bf46ab9f23785bec9adbfdf2d997a51bd8dab5ecb9f&=&format=webp&quality=lossless&width=1280&height=539)

- En este circuito, primero conectamos 5V del arduino a la línea positiva de la protoboard  para entregar energía, conectamos el pin GND a la línea negativa del mismo, permitiendo que la corriente tenga un camino de regreso para cerrar el circuito.
Conectamos el sensor ultrasónico HC-SR04, su pin VCC a 5V para energizarlo, y su pin GND conectado a tierra. En este sensor usamos tanto el pin Trigger, que está conectado al pin digital 6 del Arduino y se encarga de enviar una señal que activa el sensor para que pueda emitir las ondas ultrasónicas, como el pin Echo el cual está conectado al pin digital 5, y que recibe la señal que sirve para medir cuánto tiempo tardaron en regresar las ondas.
El buzzer está conectado al pin digital 4 y funciona como una alarma que se activa bajo condiciones definidas en el código.

![divider](https://64.media.tumblr.com/c76de97a3dde5841ec75206ce9f260cd/65c2ca21c727c407-e3/s1280x1920/b34250fcfabf92e5fcebc300a0b6c8e7bbf2d07b.pnj)
## Código

Figura 2.1

Configuración Inicial

![Código](https://media.discordapp.net/attachments/1503185091583545355/1559048397342904422/image.png?ex=6acda877&is=6acc56f7&hm=2b1d728145071381561601870fa7e2f67e8991ce40b59299ac92517a1eb51ac8&=&format=webp&quality=lossless&width=512&height=233)

- En primera instancia, definimos los pines de los que haremos uso; dos para el Sensor Ultrasónico y uno para el buzzer, así mismo los asignamos como Inputs u Outputs respectivamente dentro del setup.

Figura 2.2

Sensor Ultrasónico

![Código2](https://media.discordapp.net/attachments/1503185091583545355/1559048488124289094/image.png?ex=6acda88d&is=6acc570d&hm=e34bea3e7df2dbea0f2e7b5c1afb76ee7e4c77d52cec11d8de8a0d3c3a52318e&=&format=webp&quality=lossless)

- Después de esto iniciamos con el loop y la programación del sensor; iniciando con una señal LOW la cual tras cierta espera cambiará a HIGH, activando la lectura del sensor y convirtiendo el resultado medido (variable t) a una distancia en cm (variable d), con la fórmula señalada por el fabricante (basada en la velocidad del sonido en aire).

Figura 2.3

Feedback

![Código3](https://media.discordapp.net/attachments/1503185091583545355/1559048541962248192/image.png?ex=6acda89a&is=6acc571a&hm=ab889c8755536741a21e24a6edfaaef9ccc44d7bad9169881642d98e444db119&=&format=webp&quality=lossless)

- Finalmente, la distancia medida se comunica al usuario mediante el Serial, y el Buzzer emite un pitido siempre y cuando la distancia medida sea menor a 50 cm, y entre menor sea esa distancia más frecuente será el pitido.

![divider](https://64.media.tumblr.com/c76de97a3dde5841ec75206ce9f260cd/65c2ca21c727c407-e3/s1280x1920/b34250fcfabf92e5fcebc300a0b6c8e7bbf2d07b.pnj)
## Demo

- El siguiente link te redirige a un video demostrativo del circuito.

- [Demo](https://drive.google.com/file/d/1KIKutkj1BCSo_4tRiXr-1NvQ1puh7ocx/view?usp=sharing)

![divider](https://64.media.tumblr.com/c76de97a3dde5841ec75206ce9f260cd/65c2ca21c727c407-e3/s1280x1920/b34250fcfabf92e5fcebc300a0b6c8e7bbf2d07b.pnj)
## Conclusión

- En conclusión, esta práctica nos ayudó a tener un mayor entendimiento sobre el uso de un Sensor Ultrasónico, la lectura e interpretación de datos otorgados por medio de este al Arduino así como el uso que es posible darle a un Buzzer. Reforzamos más el conocimiento que teníamos sobre el uso del Serial y otros conocimientos previos generales de programación

- Pese a que probablemente no le daremos uso al Sensor Ultrasónico en nuestro proyecto, aún consideramos que este avance fue valioso para profundizar en la lectura de datos y el uso de este para ejecutar instrucciones. 


![divider](https://64.media.tumblr.com/c76de97a3dde5841ec75206ce9f260cd/65c2ca21c727c407-e3/s1280x1920/b34250fcfabf92e5fcebc300a0b6c8e7bbf2d07b.pnj)
## Colaboradores

- [@AtlasDaKiwi](https://github.com/AtlasDaKiwi) (Atlas)
- [@val130613](https://github.com/val130613) (Valeria)
- [@arianacastt](https://github.com/arianacastt)  (Ariana)
- [@Lzreb](https://github.com/Lzreb) (Rebeca)
