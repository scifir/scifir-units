# Use cases

## Technologies for inventions

scifir-units can be used for any project that needs units of measurement, vectors, coordinates, and related calculations. It's primary intended to program **scientific inventions**, **laboratory machines**, **electronic devices** and **medical devices** (medical devices that need a software, not any medical device). In this section it's explained how to build those devices, in order to be known how to create all the project, and not only how to use scifir-units.

To create the electronic circuit of any electronic device, being it a scientific invention, a laboratory machine, a medical device or of other type, you can use **KiCad**. The electronic circuit is then printed using the file created with KiCad. For the operating system, you can use **FreeRTOS**, **FreeBSD**, or even create a custom linux distribution with **Linux From Scratch**. For the GUI of the software of the invention to run inside this operating system, you can use **GTK+**, **wxWidgets** or **Qt**. The inventions not always use a GUI, they can work just with analog buttons or a LCD display. It's with this software where you can use scifir-units to do the calculations the software requires.

To build a desktop application that connects remotely with the invention, use also GTK+, wxWidgets or Qt to build the GUI. You can use as communication technology **bluetooth**, **wifi direct** (which is a wifi peer-to-peer) or **usb**.

Also, to add 3D to the software, you can use **OpenGL**. To do plots, use **matplot++**, **gnuplot** or **GNU plotutils**. Obviously, to store output from the software, you can use **YAML** or **XML**. To work with XML inside C++ you can use **rapidxml**, **tinyxml** or **libxml2**. To work with YAML you can use **yaml-cpp**. Use **conf** for configuration files, the library of it is **libconfig**. To send messages between different servers/daemons that are run inside the invention, you can use **dbus**. To handle large amounts of data, you can use a simple database, like **SQLite**, with **SQLiteCPP**.

From the graphics part, you can use **SVG++** to work with SVG files. To add GPS to the invention, you can use **gpsd**. To do the translation of the software, use **gettext**.

## Electronic devices

All scientific inventions and medical machines are electronic devices with more components. So, it's first needed to know electronics. An electronic device is composed of an **electronic circuit**, a **microcontroller**, **electronic sensors**, **output devices**, **electronic motors**, an **operating system**, and the **software of the device** (called **firmware**).

The **electronic circuit** connects all the different components and parts of the electronic device, and supplies energy and/or communication signals to each component.

The **microcontroller** executes the software, and sends then signals to one or more electronic component.

The **electronic sensors** measure properties of the environment and send them to the microcontroller, being it able then to read them.

The **output devices** display the output data of the software in some form or another, it can be visual (the monitor), auditive (the speakers), etc.

The **electronic motors** can be powered and controlled by the electronic circuit, and allow to control the movement, like for example the movement of the molecules through a tube.

The **operating system** is the software that handles the processes of the microcontrollers, and executes one process or another, or more than one process at the same time. Good operating systems for electronic devices are **FreeBSD** and **FreeRTOS**.

The **firmware** is the software of the electronic device, it's usually executed inside an operating system, but it can be executed without an operating system too.

## Laboratory machines

A laboratory machine, additional to all the components of electronic devices, contains too output devices and/or input devices that allow to control and get data about the matter, which can be molecules, solids, gases, liquids, cells, or even exotic matter.

Laboratory machines in which to use units are, for example, **NMR spectroscopes**, **IR spectroscopes**, **DNA sequencers**, **Gas chromatographs**. **DNA synthesizers**, a possible scientific invention present in the projects of Scifir, can also be benefited of units. **Printers at nanoscale**, which are essential for **nanotechnology**, are programmed easier, too, with units.

## Scientific inventions

A scientific invention different than a laboratory machine is done similar to those machines. Then, scientific inventions also need electronic components that handle matter. A usual different with laboratory machines is that the inventions usually need other parts too, like for example **spaceships**, which need more mechanical components than the common laboratory machine. Despite that difference, to develop a laboratory machine is similar than to develop any scientific invention.

## Medical devices

A medical device usually controls the flow of some substance, or needs high precision for the position of some part of the machine, and for those purposes scifir-units helps.

Important medical devices which can be benefited with measurement of units are devices of **robotic surgery**, **heart-lung machines**, **mechanical ventilators**, **anesthesic machines**, **lasik machines**, **x-ray machines**, **magnetic resonance imaging machines**, **ultrasound machines**, **tomography machines**.

Other simple devices as **pressure monitor**, **heart rate monitor** and **electrocardiograms** are also improved with units.

## Robotics

**Robotics** is the branch of science, mainly of informatics, whose subject of study are the robots. A **robotist** is a scientist specialized in robotics.

A robot is built with electronics, apart from the components listed previously, it needs a **visual sensor**, a **microphone**, a **speaker**, a **temperature sensor**. It can have also a **sensor of molecules**, in order to have a simulation of the **sense of odor**. In order to build the human shape (or animal shape), you must know **machining**, and use **molds**, the **milling machine** and/or the **lathe** to build each part. For some robotic parts, you can use **carbon fiber**.

All components of robots frequently need at least scalar units, if not also vector units, like for example the visual sensor or the microphone, and so you can use scifir-units inside your robotics projects.

Inside Scifir, it's called **Universal Robotics** an idea of Ismael Correa which consists of robots that can share essentially any part with the other robot. For that purpose, too, scifir-units is useful.

Each component of a robot, being a sensor or a removable part, should be programmed as an independent server inside the operating system of the robot. In that way, it can be restarted, and changed, without modifying the other parts. Then, the visual sensor, the speaker and the temperature sensor, should all be different servers inside the same OS.
