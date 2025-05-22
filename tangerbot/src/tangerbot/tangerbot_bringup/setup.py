from setuptools import find_packages, setup
import os, glob

package_name = 'tangerbot_bringup'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob.glob(os.path.join('launch', '*.launch.xml'))),
        ('share/' + package_name + '/config', glob.glob(os.path.join('config', '*.npy'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='mkh',
    maintainer_email='kyung133851@pinkab.art',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'tangerbot_bringup = tangerbot_bringup.pinky_bringup:main',
            'camera = tangerbot_bringup.camera:main',
            'pinky_battery_publiser=tangerbot_bringup.pinky_battery_publiser:main'
        ],
    },
)
