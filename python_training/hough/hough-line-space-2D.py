import matplotlib.pyplot as plt
import numpy as np
import math

pi = math.pi
line_resolution = 1000

theta = np.linspace(0, pi, line_resolution)

test_point = [
	[1,1], 
	[2,2], 
	[3,3]
]

def get_hough_spcae(x_point, y_point, x_axis):
  r_axis = np.empty(len(x_axis))
  i = 0
  for th in x_axis:
    r_axis[i] = x_point * math.cos(th) + y_point * math.sin(th)
    i+=1
  return r_axis

r = np.empty( [ len(test_point), line_resolution ] )

#get hough val
point_count = 0
for i in test_point :
  r[point_count] = get_hough_spcae (test_point[point_count][0],
                                   test_point[point_count][1],
                                   theta
                                   )
  point_count+=1

#plot  
plt.figure()

plot_hough_count = 0
for i in test_point :
  plt.plot(theta,
           r[plot_hough_count],
           label=( r"$\theta$" + "-r" + str(plot_hough_count) )
          )#plot Hough space
  plt.plot(test_point[plot_hough_count][0],
		   test_point[plot_hough_count][1],
		   '*')#plot xy space
  plot_hough_count+=1


	
plt.xticks([0, pi/2, pi],
           ['$0$', r'$\frac{\pi}{2}$', r'$\pi$'])
plt.legend(loc="upper right")
plt.xlabel(r"$\theta$")
plt.ylabel("r")
plt.grid()
plt.show()