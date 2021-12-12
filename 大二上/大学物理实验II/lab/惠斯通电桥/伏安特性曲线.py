'''
输入: 4行伏安特性数据,英文逗号分隔，注意I-U对应的数据条数要相同 (2行电阻，2行二极管)
输出: 2张伏安特性曲线图
注意: 修改path对象到data.txt所在路径
'''

import matplotlib.pyplot as plt
import os

path = "C:\\Users\\JerryYang\\Desktop\\大物实验\\惠斯通电桥\\"


class DataProcessing:
    def __init__(self) -> None:
        self.data = []
        self.bridge = None
        with open(os.path.join(path, 'data.txt'), 'r') as f:
            for line in f:
                line = [float(x) for x in line.split(',')]
                self.data.append(line)

    def voltage_current_characteristic(self):
        plt.plot(self.data[0], self.data[1], label='I-U',marker='o')
        plt.xlabel('U/V')
        plt.ylabel('I/mA')
        x_scale = min(self.data[0])*0.8, max(self.data[0])*1.15
        y_scale = min(self.data[1])*0.8, max(self.data[1])*1.15
        plt.axis(x_scale + y_scale)
        plt.legend(loc='best')
        plt.savefig(os.path.join(path,"figure_1.png"),dpi=800)
        plt.show()

        plt.plot(self.data[2], self.data[3], label='I-U',marker='o')
        plt.xlabel('U/V')
        plt.ylabel('I/mA')
        x_scale = min(self.data[2])*0.8, max(self.data[2])*1.15
        y_scale = min(self.data[3])*0.8, max(self.data[3])*1.15
        plt.axis(x_scale + y_scale)
        plt.legend(loc='best')
        plt.savefig(os.path.join(path,"figure_2.png"),dpi=800)
        plt.show()
    def Wheatstone_bridge(self):
        pass

if __name__ == '__main__':
    run = DataProcessing()
    run.voltage_current_characteristic()
    