import matplotlib.pyplot as plt
import numpy as np
import math

pi = math.pi
line_resolution = 1000

t = np.linspace(0, pi, line_resolution)

test_point = [
	[0,5], 
	# [3,4], 
	# [5,0],
  # [0,-5],
  [-4,-3]
]

#def find_intersection(data_2D, num_cross_is_intersetion, max_matched_val):
def find_intersection(data_2D):
  length_axis_dim = len(data_2D)
  
  if length_axis_dim < 2:
    raise Exception("Input argument error: Dimension x of dim(data_2D[x][y]) < 2")
  
  length_axis_datas = len(data_2D[0])
  location = []
  
  for i in range(length_axis_datas):
    all_equal = True
    last_val = None
    for j in range(length_axis_dim):
      val = data_2D[j][i]
      if last_val is not None:
        if last_val != val:
          all_equal = False
      last_val = val
    if all_equal:
      location.append(i)
  return location

def get_hough_spcae(x_point, y_point, x_axis):
  r_axis = np.empty(len(x_axis))
  i = 0
  for th in x_axis:
    numerator = 2*(x_point * math.cos(th) + y_point * math.sin(th))
    denominator = x_point * x_point + y_point * y_point
    r_axis[i] = numerator / denominator
    i+=1
  return r_axis

r = np.empty( [ len(test_point), line_resolution ] )

#get hough val
point_count = 0
for i in test_point :
  r[point_count] = get_hough_spcae (test_point[point_count][0],
                                   test_point[point_count][1],
                                   t
                                   )
  point_count+=1

print( "intersection: " + str( find_intersection(r) ) )
#plot  
plt.figure()

plot_hough_count = 0
for i in test_point :
  #plot Hough space
  plt.plot(t,
           r[plot_hough_count],
           label=( "t" + "-r" + str(plot_hough_count) + 
                    "[ " + str(test_point[plot_hough_count][0]) + 
                          " , " +
                          str(test_point[plot_hough_count][1]) + 
                  " ]" )
          )
  #plot xy space        
  # plt.plot(test_point[plot_hough_count][0],
	# 	   test_point[plot_hough_count][1],
	# 	   '*')
  plot_hough_count+=1

# plt.xticks([0, pi/2, pi],
#            ['$0$', r'$\frac{\pi}{2}$', r'$\pi$'])
plt.legend(loc="upper right")
plt.xlabel("t")
plt.ylabel("r")
plt.grid()
plt.show()
