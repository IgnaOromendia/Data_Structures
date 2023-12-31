import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

data_pb_l = pd.read_csv("samples/linked_push_back.csv")
data_pf_l = pd.read_csv("samples/linked_push_front.csv")
data_push_v = pd.read_csv("../samples_cpp/vector_push_back.csv")
data_pb_lc = pd.read_csv("../samples_cpp/list_push_back.csv")
data_pf_lc = pd.read_csv("../samples_cpp/list_push_front.csv")

data_l_access = pd.read_csv("samples/access_linked_list.csv")
data_lo_access = pd.read_csv("samples/access_linked_list_opt.csv")
data_lc_access = pd.read_csv("../samples_cpp/access_list.csv")

# fig1 = plt.figure(figsize=(8, 6))

plt.plot(data_pb_lc['n'], data_pb_lc['time'], label='C++ List push back', color='red', linewidth = 2)
plt.plot(data_pf_lc['n'], data_pf_lc['time'], label='C++ List push front', color='orange', linewidth = 2)
plt.plot(data_pb_l['n'], data_pb_l['time'], label='List push back', color='blue', linewidth = 2)
plt.plot(data_pf_l['n'], data_pf_l['time'], label='List push front', color='green', linewidth = 2)
plt.xlabel('N')
plt.ylabel('Time (miliseconds)')
plt.title('Insertion Double Linked List vs C++ List')
plt.grid(True)
plt.legend()
plt.show()

# fig2 = plt.figure(figsize=(8, 6))

plt.plot(data_push_v['n'], data_push_v['time'], label='C++ Vector', color='red', linewidth = 2)
plt.plot(data_pb_l['n'], data_pb_l['time'], label='List push back', color='blue', linewidth = 2)
plt.plot(data_pf_l['n'], data_pf_l['time'], label='List push front', color='green', linewidth = 2)
plt.xlabel('N')
plt.ylabel('Time (miliseconds)')
plt.title('Insertion Double Linked List vs C++ vector')
plt.grid(True)
plt.legend()
plt.show()

fig3 = plt.figure(figsize=(8, 6))

plt.plot(data_l_access['n'], data_l_access['time'], label='Double linked list', color='blue', linewidth = 2)
plt.plot(data_lo_access['n'], data_lo_access['time'], label='Double linked list optimized', color='green', linewidth = 2)
plt.plot(data_lc_access['n'], data_lc_access['time'], label='C++ List', color='red', linewidth = 2)
plt.xlabel('i-th')
plt.ylabel('Time (miliseconds)')
plt.title('Access Double Linked List vs C++ list')
plt.grid(True)
plt.legend()
plt.show()







