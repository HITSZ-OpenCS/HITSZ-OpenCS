'''
本代码只针对分光计实验编写，数据格式要求和指导书表格对应要求一致
- 输入9*8个数，每行为4个角度值，度和分之间用','隔开，角度值之间也用','隔开，即每行8个数，数字间多余空格不影响结果
- 请首先修改路径对象 path 到 data.txt 所在的路径，处理后存入 data_proc.txt
- 需要numpy包(可通过修改代码去除，此前编写时未考虑相关问题)

(计算结果无异常不需要阅读以下内容)
注意：必须输入完整数据，要让程序运行需要9*8个数，可查看data.txt的范例
注意：如果同一组数据中有跨越360度的情况，需要将较小值+360作为输入数据(可通过计算结果判断某组数据需要更正，比如计算出好几千的波长)
示例:
第一组数据：7度35分 187度37分 26度28分 206度29分=>
7,35,187,37,26,28,206,29
第二组数据：357度54分 177度59分 36度10分 216度12分=>
357,54,177,59,396,10,216,12
即前两组输入为
7,35,187,37,26,28,206,29
357,54,177,59,396,10,216,12
'''
import math
import os
import numpy as np
data_rad = np.ndarray([9, 4], dtype=float)
data_deg = np.ndarray([9, 4], dtype=float)
psi_rad = np.ndarray([9, 1])
psi_deg = np.ndarray([9, 1])
d = 1/300 * 1e6
lam_k = np.ndarray([9, 1])
aver_lam = np.ndarray([3, 1])
std_lam = np.array([[546.1], [577.0], [579.1]])
error = np.ndarray([3, 1])

path = 'C:/Users/JerryYang/Desktop/大物实验/分光计/'
with open(os.path.join(path, 'data.txt'), 'r') as f_in:
    for i in range(9):
        row = f_in.readline()
        num = row.split(',')
        for j in range(4):
            # print(num[j * 2], num[j * 2 + 1])
            data_deg[i][j] = float(num[j * 2]) + float(num[j * 2 + 1]) / 60  # 拼接成以度为单位的数值
            data_rad[i][j] = math.radians(data_deg[i][j])
        psi_rad[i][0] = abs(data_rad[i][0] + data_rad[i][1] -
                            data_rad[i][2] - data_rad[i][3]) / 4  # radians
        psi_deg[i][0] = abs(data_deg[i][0] + data_deg[i][1] -
                            data_deg[i][2] - data_deg[i][3]) / 4  # degrees str
        
        k = i % 3 + 1
        lam_k[i][0] = d * math.sin(psi_rad[i][0]) / k
        if k == 3:
            aver_lam[i//3][0] = (lam_k[i][0]+lam_k[i-1][0]+lam_k[i-2][0])/3
            error[i//3][0] = abs(std_lam[i//3][0] -
                                 aver_lam[i//3][0]) / std_lam[i//3][0] * 100
            # print(aver_lam)
        
with open(os.path.join(path, 'data_proc.txt'),'w') as f_out:
    f_out.write('psi_k (radian):\n')
    f_out.write('\n'.join(str(e) for e in psi_rad[0:9, 0]))
    
    f_out.write('\n\npsi_k (degree):\n')
    f_out.write('\n'.join(str(e) for e in psi_deg[0:9, 0]))
    
    f_out.write('\n\nlambda_k (nm):\n')
    f_out.write('\n'.join(str(e) for e in lam_k[0:9, 0]))
    
    f_out.write('\n\naverage_lambda (nm):\n')
    f_out.write('\n'.join(str(e) for e in aver_lam[0:3,0]))

    f_out.write('\n\nrelative error (%):\n')
    f_out.write('\n'.join(str(e) for e in error[0:3,0]))

    print("\n经处理的数据已写入文件\'data_proc.txt\'")
    print("Processed data have been written to file\'data_proc.txt\'")
    print("Including:\npsi_k (radian)\npsi_k (degree)\nlambda_k (nm)\naverage_lambda (nm)\nrelative error (%)")