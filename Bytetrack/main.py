# Import Python Standard Library dependencies
from dataclasses import dataclass
import json
from pathlib import Path
import random
import time
from typing import List

# Import ByteTrack package
from cjm_byte_track.core import BYTETracker
from cjm_byte_track.matching import match_detections_with_tracks

# Import utility functions
from cjm_psl_utils.core import download_file
from cjm_pil_utils.core import resize_img

# Import OpenCV
import cv2

# Import numpy
import numpy as np

# Import the pandas package
import pandas as pd

# Import PIL for image manipulation
from PIL import Image, ImageDraw, ImageFont

# Import ONNX dependencies
import onnx # Import the onnx module
import onnxruntime as ort # Import the ONNX Runtime

# Import tqdm for progress bar
from tqdm.auto import tqdm

#########################################################################

# The name for the project
project_name = f"pytorch-yolox-object-detector"

# The path for the project folder
project_dir = Path(f"./{project_name}/")

# Create the project directory if it does not already exist
project_dir.mkdir(parents=True, exist_ok=True)

# The path to the checkpoint folder
checkpoint_dir = Path(project_dir/f"2023-08-17_16-14-43")
# checkpoint_dir = Path(project_dir/f"pretrained-coco")

pd.Series({
    "Project Directory:": project_dir,
    "Checkpoint Directory:": checkpoint_dir,
}).to_frame().style.hide(axis='columns')

#########################################################################

# Set the name of the font file
font_file = 'KFOlCnqEu92Fr1MmEU9vAw.ttf'

# Download the font file
download_file(f"https://fonts.gstatic.com/s/roboto/v30/{font_file}", "./")

#########################################################################

# The colormap path
colormap_path = list(checkpoint_dir.glob('*colormap.json'))[0]

# Load the JSON colormap data
with open(colormap_path, 'r') as file:
        colormap_json = json.load(file)

# Convert the JSON data to a dictionary        
colormap_dict = {item['label']: item['color'] for item in colormap_json['items']}

# Extract the class names from the colormap
class_names = list(colormap_dict.keys())

# Make a copy of the colormap in integer format
int_colors = [tuple(int(c*255) for c in color) for color in colormap_dict.values()]

max_stride = 32
input_dim_slice = slice(2, 4, None)

def prepare_image_for_inference(frame:np.ndarray, target_sz:int, max_stride:int):

    """
    Prepares an image for inference by performing a series of preprocessing steps.
    
    Steps:
    1. Converts a BGR image to RGB.
    2. Resizes the image to a target size without cropping, considering a given divisor.
    3. Calculates input dimensions as multiples of the max stride.
    4. Calculates offsets based on the resized image dimensions and input dimensions.
    5. Computes the scale between the original and resized image.
    6. Crops the resized image based on calculated input dimensions.
    
    Parameters:
    - frame (numpy.ndarray): The input image in BGR format.
    - target_sz (int): The target minimum size for resizing the image.
    - max_stride (int): The maximum stride to be considered for calculating input dimensions.
    
    Returns:
    tuple: 
    - rgb_img (PIL.Image): The converted RGB image.
    - input_dims (list of int): Dimensions of the image that are multiples of max_stride.
    - offsets (numpy.ndarray): Offsets from the resized image dimensions to the input dimensions.
    - min_img_scale (float): Scale factor between the original and resized image.
    - input_img (PIL.Image): Cropped image based on the calculated input dimensions.
    """

    # Convert the BGR image to RGB
    rgb_img = Image.fromarray(cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))
    # Resize image without cropping to multiple of the max stride
    resized_img = resize_img(rgb_img, target_sz=target_sz, divisor=1)
    
    # Calculating the input dimensions that multiples of the max stride
    input_dims = [dim - dim % max_stride for dim in resized_img.size]
    # Calculate the offsets from the resized image dimensions to the input dimensions
    offsets = (np.array(resized_img.size) - input_dims) / 2
    # Calculate the scale between the source image and the resized image
    min_img_scale = min(rgb_img.size) / min(resized_img.size)
    
    # Crop the resized image to the input dimensions
    input_img = resized_img.crop(box=[*offsets, *resized_img.size - offsets])
    
    return rgb_img, input_dims, offsets, min_img_scale, input_img