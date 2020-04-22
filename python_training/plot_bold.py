from scipy import signal
import matplotlib.pyplot as plt

u=1E-6

hs_01u = signal.lti([50*0.1*u, 0],[50*0.1*u, 1])
hs_01u_w, hs_01u_mag, hs_01u_ph = signal.bode(hs_01u,None,10000)


def find_cutoff_freq_hpf(freq_array, gain_array):
  for iter in range(len(gain_array)):
    if gain_array[iter] > -3.0:
      return iter-1, freq_array[iter-1], gain_array[iter-1]

cf_01u_i, cf_01u_f, cf_01u_g = find_cutoff_freq_hpf(hs_01u_w, hs_01u_mag)


print("01u vals:")
print("iter = %d, freq=%f, gain=%f" % (cf_01u_i,cf_01u_f,cf_01u_g) )

arrowprops = dict(
    arrowstyle = "->",
    connectionstyle = "angle,angleA=0,angleB=90,rad=10")

bbox = dict(boxstyle="round", fc="0.8")

plt.figure()
plt.plot(hs_01u_w,hs_01u_mag,color="blue",label="01u")
plt.plot(cf_01u_f,cf_01u_g,color="red",marker='*')
plt.annotate('-3dB\n cut-off point\n freq=\n%f'%cf_01u_f, 
             xy=(cf_01u_f, cf_01u_g),     
            )
plt.xscale('log')
plt.legend(loc='upper left')
plt.grid()
plt.show()