import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('os_combined-ww-monthly-200901-202312.csv')
df = df.filter(items=['Date', 'iOS', 'Android'])
df.plot.line(x='Date', title='Worldwide OS Market Share')
plt.savefig('worldwide_os_market_share.png')

df = pd.read_csv('os_combined-TW-monthly-200901-202312.csv')
df = df.filter(items=['Date', 'iOS', 'Android'])
df.plot.line(x='Date', title='Taiwan OS Market Share')
plt.savefig('taiwan_os_market_share.png')

plt.show()