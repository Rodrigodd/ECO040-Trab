import matplotlib
import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np
import csv
import os

plt.rcParams['svg.fonttype'] = 'none'
plt.rcParams["font.family"] = "Verdana"
mpl.use("SVG")

with plt.style.context('ggplot'), open('out.tsv', newline='') as csvfile:
    data = np.array(list(csv.reader(csvfile, delimiter='\t')))

    sizes = data[0][1:].astype(float)

    fig, ax = plt.subplots()

    for line in data[1:]:
        name = line[0]
        print(name)
        times = line[1:].astype(float)

        ax.plot(sizes, times, label = name)

    ax.set_ylabel('microsegundos')
    ax.set_xlabel('n° de palavras')

    ax.set_yscale('log')
    ax.set_xscale('log', base= 2)
    ax.xaxis.set_major_formatter(matplotlib.ticker.ScalarFormatter())

    def to_time(v, pos):
        if v == 0.0000001:
            return '100ns'
        if v == 0.00001:
            return '10us'
        if v == 0.001:
            return '1ms'
        if v == 0.1:
            return '100ms'
        if v == 10:
            return '10s'
        return str(v)

    ax.yaxis.set_major_formatter(matplotlib.ticker.FuncFormatter(to_time))

    ax.set_xticks([int(abs(tick)) for tick in sizes[::2]])

    ax.legend()

    # plt.show()

    fig.tight_layout()
    if not os.path.exists('plots'):
        os.mkdir('plots')
    plt.savefig(f'plots/plot.svg')
