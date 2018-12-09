# DC motor modeling and control loop design

## Motor description

![Motor Scheme](.gitbook/assets/mcc%20%281%29.png)

![Variables and parameters table](.gitbook/assets/table_variables%20%281%29.png)

## System modeling

**Electric equation:**

From kirchhoff's voltage law :

$$
L\frac{di(t)}{dt} =v(t) - Ri(t) - e(t)
$$

**Mechanical equation:**

By Newton's law:

$$
J\frac{d\omega(t)}{dt} = \sum T(t) = T_m(t)-f\omega(t)
$$

where $$T(t)$$ is the total torque applied on the rotor.

**Electro-mechanical coupling:**

The back EMF is proportional to speed :

$$
e(t) = K_e \omega(t)
$$

$$K_e$$ : electromotive constant $$(V.rad^{-1}.s)$$

The motor torque is proportional to current :

$$
T_m(t) = K_T i(t)
$$

$$K_T$$ : Torque constant $$(N.m.A^{-1})$$

The mechanical power produced by the DC motor is $$T_m\omega = K_Ti\omega$$. The electric power $$P_e = vi$$ delivered by the source goes into heat loss in the resistance $$R$$, into stored magnetic energy in the inductance $$L$$ and the remaining quantity $$iK_e\omega$$ is converted in mechanical energy $$T_m\omega$$. It leads to $$T_m\omega = K_Ti\omega = K_ei\omega$$ whether $$K_T = K_e = K_\phi$$ \(Chiasson2005\).

## Motor Bloc Diagram

![DC Motor Bloc Diagram](.gitbook/assets/dcmotordiagram.png)

## Motor control : cascaded strategy

The control synthesis is inspired by Permanent Magnet Synchronous Motor control synthesis based on cascaded control synthesis. Due to frequency separation the control can be divided into two control loops. The inner loop control the electrical dynamic while the outer loop treats the mechanical dynamic. Generally the the electrical dynamics is neglected and the mechanical dynamics is considered only. However in the case where motor resistance is low, this strategy can damage the motor.

### Electrical dynamics control

The objective is to control the motor torque $$T_m(t)$$. Indeed $$T_m(t) = K_\phi i(t)$$ the motor torque is imposed by the current.

![Closed loop electrical system](.gitbook/assets/clelecdyn.png)

With the assumption that the mechanical dynamic is slower the the electrical one, one has :

$$
\tau_{\rm elec} = \frac{L}{R}<<\tau_{\rm meca} = \frac{J}{f}
$$

The velocity $$\omega$$ can then be considered as constant from the point of view of the electrical dynamics.

**Feedback control with integral action**

The electrical dynamics is given by

$$
\begin{array}{lcl}
\dot{i}  &=& -\frac{R}{L} i + \frac{1}{L}v -\frac{K_\phi}{L}w\\
     &=& -\frac{1}{\tau_e} i + \frac{K_e}{\tau_e}v -\frac{K_\phi}{L}w
\end{array}
$$

The control objective is to ensure $$i^\star =i_{\rm ref}$$, where $$i^\star$$ is the current steady state and $$i_{\rm ref}$$ is the current reference. To ensure zero steady state error, an integral action is necessary. The principle is to insert an integral action the the feed-forward loop between the error compactor and the process \(Ogata2010\).
The control scheme is given by :

![Electrical dynamics state feedback](.gitbook/assets/elecsfb.png)

From the figure one gets :

$$
\begin{array}{lcl}
   \dot{i}  & = & -\frac{R}{L} i + \frac{1}{L}v -\frac{K_\phi}{L}w \\
   \dot{\varepsilon} & = & i_{\rm ref} - i \\
   v & = & -Ki+K_I\varepsilon
\end{array}
$$

with $$\varepsilon$$ the output of the integrator.


The system dynamics can be described by

$$
\begin{bmatrix}
\dot{i}\\\dot{\varepsilon}
\end{bmatrix} = 
\begin{bmatrix}
-\frac{R}{L} & 0\\-1 &0
\end{bmatrix} \begin{bmatrix}
{i}\\{\varepsilon}
\end{bmatrix}+
\begin{bmatrix}
\frac{1}{L}\\0
\end{bmatrix}v+
\begin{bmatrix}
\frac{K_\phi}{L}\\0
\end{bmatrix}\omega+
\begin{bmatrix}
0\\1
\end{bmatrix}i_{\rm ref}
$$

with the control

$$
v  =  -Ki-K_I\varepsilon
$$

The closed loop system leads to :

$$
\begin{bmatrix}
\dot{i}\\\dot{\xi}
\end{bmatrix} = 
\left(\begin{bmatrix}
-\frac{R}{L} & 0\\-1 &0
\end{bmatrix} -
\begin{bmatrix}
\frac{1}{L}\\0
\end{bmatrix} \begin{bmatrix}K&K_I\end{bmatrix}\begin{bmatrix}i\\\varepsilon\end{bmatrix}\right)+
\begin{bmatrix}
\frac{K_\phi}{L}\\0
\end{bmatrix}\omega+
\begin{bmatrix}
0\\1
\end{bmatrix}i_{\rm ref}
$$

The closed loop dynamics depends on the eigenvalues of the matrix :

$$
\left(\begin{bmatrix}
-\frac{R}{L} & 0\\-1 &0
\end{bmatrix} -
\begin{bmatrix}
\frac{1}{L}\\0
\end{bmatrix} \begin{bmatrix}K&K_I\end{bmatrix}\right)= 
\begin{bmatrix}
-\frac{R+K}{L} & -\frac{K_I}{L}\\-1 &0
\end{bmatrix}
$$

One has

$$
{\rm eig}\left(
\begin{bmatrix}
-\frac{R+K}{L} & -\frac{K_I}{L}\\-1 &0
\end{bmatrix}\right) = {\rm det}\left(sI-\begin{bmatrix}
-\frac{R+K}{L} & -\frac{K_I}{L}\\-1 &0
\end{bmatrix}\right)
$$

It leads to a characteristic equation

$$
P(s) = s^2+\frac{K+R}{L}s -K_I
$$

to be identified with the classical second order characteristic equation

$$
P(s) = p^2+2\zeta\omega_n s +\omega_n^2
$$

where $$\omega_n$$ is the desired closed loop natural frequency and $$\zeta$$ the damping coefficient.


### Mechanical dynamics control
![Closed loop cascaded system](.gitbook/assets/clmecadyn.png)

Assuming the electrical control has been correctly synthesized with respect to frequency separation principle, which means that the closed loop electrical dynamics is faster than the mechanical desired dynamics, then the mechanical dynamics control synthesis can be designed without considering the closed loop electrical system. The control scheme can be simplified as :

![Closed loop mechanical system](.gitbook/assets/clmecadyn2.png)

The mechanical dynamics is 

$$
\begin{array}{lcl}
\dot{\omega} &=&  \frac{1}{J}T_m-\frac{f}{J}\omega\\
	&=&  \frac{K_\phi}{J}i-\frac{f}{J}\omega
\end{array}
$$

where $$T_m = K_\phi i$$

The control synthesis is similar than the one proposed for the electrical dynamics
with $$\dot\varepsilon_\omega = \omega_{\rm ref}-\omega$$ leading to 
$$
\begin{bmatrix}
\dot{\omega}\\\dot{\varepsilon_\omega}
\end{bmatrix} = 
\begin{bmatrix}
-\frac{f}{J} & 0\\-1 &0
\end{bmatrix} \begin{bmatrix}
{\omega}\\{\varepsilon_\omega}
\end{bmatrix}+
\begin{bmatrix}
\frac{K_\phi}{J}\\0
\end{bmatrix}i+
\begin{bmatrix}
0\\1
\end{bmatrix}\omega_{\rm ref}
$$
with the control  
$$
 i  =  -K_\omega \omega-K_{\omega,I}\varepsilon_\omega
$$


By analogy, it leads to a characteristic equation 

$$
P(s) = s^2+\frac{K_\phi K_\omega+f}{L}s -K\phi K_{\omega,I} 
$$

to be identified with the classical second order characteristic equation

$$
P(s) = p^2+2\zeta\omega_n s +\omega_n^2 .
$$

## References

\(Chiasson2005\) Chiasson, J.-N. \(2005\). Modeling and High-Performance Control of Electric Machines \(IEEE Press\).

\(Ogata2010\) Ogata, K. \(2010\). Modern Control Engineering. Prentice Hall.

