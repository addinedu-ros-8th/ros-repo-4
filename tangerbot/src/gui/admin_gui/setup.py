# from setuptools import find_packages, setup

# package_name = 'admin_gui'

# setup(
#     name=package_name,
#     version='0.0.0',
#     packages=find_packages(exclude=['test']),
#     data_files=[
#         ('share/ament_index/resource_index/packages',
#             ['resource/' + package_name]),
#         ('share/' + package_name, ['package.xml']),
#     ],
#     install_requires=['setuptools'],
#     zip_safe=True,
#     maintainer='addinedu',
#     maintainer_email='pjb804@gmail.com',
#     description='TODO: Package description',
#     license='TODO: License declaration',
#     tests_require=['pytest'],
#     entry_points={
#         'console_scripts': [
#         ],
#     },
# )

from setuptools import setup

package_name = 'admin_gui'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/admin_gui']),
        ('share/' + package_name, ['package.xml']),
        # UI 및 데이터 파일 포함
        ('share/' + package_name + '/ui', ['ui/admin_interface.ui']),
        ('share/' + package_name + '/data', [
            'data/47727.jpg',
            'data/37005.jpg',
            'data/robot_report.png',
            'data/report.png',
            'data/settings.png',
        ]),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='your_name',
    maintainer_email='your_email@example.com',
    description='Admin GUI for robot monitoring',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'admin_gui_node = admin_gui.admin_interface:main'
        ],
    },
)
