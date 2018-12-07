# DC motor modeling and control loop design

## Motor description
 
## System modeling

**Electric equation:**
From kirchhoff's voltage law :
$$ L\frac{di(t)}{dt} =v(t) - Ri(t) - e(t) $$

**Mechanical equation:**
By Newton's law:
$$J\frac{d\omega(t)}{dt} = \sum c(t) = c_m(t)-f\omega(t)$$
where $c(t)$ is the total torque applied on the rotor


\subsubsection{Electro-mechanical coupling :}
The back EMF is proportional to speed :
\begin{equation}
e(t) = K_e \omega(t) %\quad{\rm ou}\quad E(p) = K_e \Omega(p)
\end{equation}
$K_e$ : electromotive constant $(\volt.\rad^{-1}.\second)$

The motor torque is proportional to current :
\begin{equation}
c_m(t) = K_T i(t) %\quad{\rm ou}\quad C_m(p) = K_e \Omega(p)
\end{equation}
$K_T$ : Torque constant $(\newton.\meter.\ampere^{-1})$


The mechanical power produced by the DC motor is $c_m\omega = K_Ti\omega$. The electric power  $P_e = vi$ delivered by the source goes into heat loss in the resistance $R$, into stored magnetic energy in the inductance $L$ and the remaining quantity $iK_e\omega$ is converted in mechanical energy $c_m\omega$. It leads to $c_m\omega = K_ci\omega = K_ei\omega$ soit $K_c = K_e = K_\phi$ \cite{Chi05}.

