# Makes my commits look like I'm working hard
import os
import subprocess

with open('temp.txt', 'r') as f:
    lines = f.readlines()

for line in lines:
    if line.startswith('#'):
        continue
    line = line.rstrip()
    subprocess.run(['git', 'add', line], shell=True)
    subprocess.run(
        ['git', 'commit', '-m', f"Deleted: {line.split('/')[-1]}", line],
        shell=True,
    )
    print(f"Deleted: {line.split('/')[-1]}")

subprocess.run(['git', 'push', 'origin', 'master'], shell=True)