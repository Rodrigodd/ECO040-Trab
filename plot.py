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
    data = list(csv.reader(csvfile, delimiter='\t'))

    for i, line in enumerate(data):
        if i == 0:
            continue
        for j, s in enumerate(line):
            if j == 0:
                continue
            value, err = s.split('±')
            data[i][j] = [float(value), float(err)]

    sizes = np.array(data[0][1:]).astype(float)

    fig, ax = plt.subplots()

    for line in data[1:]:
        name = line[0]
        print(name)

        line = np.array(line[1:])
        times = line[:,0].astype(float)
        errors = line[:,1].astype(float)

        df = {
            'Tamanho': sizes,
            'Tempo': times,
        };

        # ax.plot(sizes, times, label = name)
        ax.errorbar('Tamanho', 'Tempo', data = df, yerr = errors, capsize=3)

    ax.set_ylabel('microsegundos')
    ax.set_xlabel('n° de palavras')

    ax.set_yscale('log')
    ax.set_xscale('log', base= 2)
    ax.xaxis.set_major_formatter(matplotlib.ticker.ScalarFormatter())

    def to_time(v, pos):
        if v == 0.0000001:
            return '100ns'
        if v == 0.000001:
            return '1us'
        if v == 0.00001:
            return '10us'
        if v == 0.0001:
            return '100us'
        if v == 0.001:
            return '1ms'
        if v == 0.01:
            return '10ms'
        if v == 0.1:
            return '100ms'
        if v == 1:
            return '1s'
        if v == 10:
            return '10s'
        return str(v)

    ax.yaxis.set_major_formatter(matplotlib.ticker.FuncFormatter(to_time))

    ax.set_xticks([int(abs(tick)) for tick in sizes[::2]])

    ax.legend()

    fig.tight_layout()

    plt.show()

    if not os.path.exists('plots'):
        os.mkdir('plots')
    plt.savefig(f'plots/plot.svg')
