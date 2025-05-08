from setuptools import setup

package_name = 'vision_server'

setup(
    name=package_name,
    version='0.0.1',
    packages=[],
    # packages=find_packages(include=['scripts', 'scripts.*']),
    py_modules=['gesture_publisher'],           
    data_files=[
        ('share/ament_index/resource_index/packages', 
         ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='selni',
    maintainer_email='qkrtpfls9902@gmail.com',
    description='vision Server package with gesture nodes',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'gesture_node = gesture_node:main',  # 이동된 경로로 수정
        ],
    },
)
