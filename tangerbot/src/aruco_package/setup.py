from setuptools import find_packages, setup
import glob
import os

package_name = 'aruco_package'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/config', glob.glob(os.path.join('config', '*.npy'))),
        ('share/' + package_name + '/config', glob.glob(os.path.join('config', '*.yaml'))),
        ('share/' + package_name, glob.glob("*.xlsx")),
        ('share/' + package_name, glob.glob("*.pth")),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='tm',
    maintainer_email='taemin5315@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "my_tf=aruco_package.my_tf:main",
            'calibration=aruco_package.calibration:main',
            'broadcaster=aruco_package.broadcaster:main',
        ],
    },
)
