# Lidar Point Cloud Toolkit

Lidar Point Cloud Toolkit is a command-line tool for processing and visualizing point cloud data from PCD files. It provides functionalities such as visualization and conversion of point cloud data to a depth map.

## Installation

To build the toolkit, use the provided `build.sh` script:

```sh
./build.sh
```

This script compiles the project and places the executable in the `bin/` directory.

## Usage

Run the toolkit using the `run.sh` script:

```sh
./run.sh --pcd-file-path <path_to_pcd_file> [--visualize-pcd] [--pcd-to-depth]
```

Alternatively, you can execute the binary directly:

```sh
./bin/lidar_point_cloud_toolkit --pcd-file-path <path_to_pcd_file> [--visualize-pcd] [--pcd-to-depth]
```

## Command-Line Options

The following flags can be used to control the tool’s behavior:

- `-h, --help` - Show help information.
- `--pcd-file-path <path>` - Specify the path to the PCD file to be processed.
- `--visualize-pcd` - Enable visualization of the point cloud data.
- `--pcd-to-depth` - Convert the PCD file to a depth map and save it as `depthmap.png`.

## Features

- Load and process point cloud data from PCD files.
- Visualize point cloud data.
- Convert point cloud data into a depth map image.

## Example Usage

### Visualizing a PCD File

```sh
./bin/lidar_point_cloud_toolkit --pcd-file-path data/example.pcd --visualize-pcd
```

### Converting a PCD File to a Depth Map

```sh
./bin/lidar_point_cloud_toolkit --pcd-file-path data/example.pcd --pcd-to-depth
```

This command will generate `depthmap.png` in the current directory.

## License

This project is licensed under the MIT License.

