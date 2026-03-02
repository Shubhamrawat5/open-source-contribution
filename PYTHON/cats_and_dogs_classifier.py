# ============================================================
# Cat vs Dog Image Classifier - TensorFlow 2.0 / Keras CNN
# freeCodeCamp Machine Learning Certification Project
# ============================================================

# ─── Cell 1: Import Libraries ───────────────────────────────
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense, Dropout
from tensorflow.keras.preprocessing.image import ImageDataGenerator
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import os

# ─── Cell 2: Download Data & Set Variables ──────────────────
# Run this in Google Colab
# !wget https://cdn.freecodecamp.org/project-data/cats-and-dogs/cats_and_dogs.zip
# !unzip cats_and_dogs.zip

PATH = 'cats_and_dogs'

train_dir      = os.path.join(PATH, 'train')
validation_dir = os.path.join(PATH, 'validation')
test_dir       = os.path.join(PATH, 'test')

# Image dimensions
IMG_HEIGHT = 150
IMG_WIDTH  = 150
BATCH_SIZE = 32
EPOCHS     = 15

# ─── Cell 3: Create Image Generators ────────────────────────
# Rescale pixel values from [0-255] to [0-1]
train_image_generator      = ImageDataGenerator(rescale=1./255)
validation_image_generator = ImageDataGenerator(rescale=1./255)
test_image_generator       = ImageDataGenerator(rescale=1./255)

train_data_gen = train_image_generator.flow_from_directory(
    batch_size  = BATCH_SIZE,
    directory   = train_dir,
    target_size = (IMG_HEIGHT, IMG_WIDTH),
    class_mode  = 'binary'
)

val_data_gen = validation_image_generator.flow_from_directory(
    batch_size  = BATCH_SIZE,
    directory   = validation_dir,
    target_size = (IMG_HEIGHT, IMG_WIDTH),
    class_mode  = 'binary'
)

test_data_gen = test_image_generator.flow_from_directory(
    batch_size  = BATCH_SIZE,
    directory   = test_dir,
    target_size = (IMG_HEIGHT, IMG_WIDTH),
    class_mode  = None,   # No labels for test set
    shuffle     = False   # Keep order consistent for predictions
)

# ─── Cell 4: Plot Helper Function ───────────────────────────
def plotImages(images_arr, probabilities=False):
    fig, axes = plt.subplots(len(images_arr), 1, figsize=(5, len(images_arr) * 3))
    if probabilities is False:
        for img, ax in zip(images_arr, axes):
            ax.imshow(img)
            ax.axis('off')
    else:
        for img, probability, ax in zip(images_arr, probabilities, axes):
            ax.imshow(img)
            ax.axis('off')
            if probability > 0.5:
                ax.set_title("%.2f" % (probability * 100) + "% dog")
            else:
                ax.set_title("%.2f" % ((1 - probability) * 100) + "% cat")
    plt.show()

# Plot 5 sample training images
sample_training_images, _ = next(train_data_gen)
plotImages(sample_training_images[:5])

# ─── Cell 5: Data Augmentation ──────────────────────────────
train_image_generator = ImageDataGenerator(
    rescale            = 1./255,
    rotation_range     = 40,
    width_shift_range  = 0.2,
    height_shift_range = 0.2,
    shear_range        = 0.2,
    zoom_range         = 0.2,
    horizontal_flip    = True,
    fill_mode          = 'nearest'
)

# ─── Cell 6: Recreate Train Generator with Augmentation ─────
train_data_gen = train_image_generator.flow_from_directory(
    batch_size  = BATCH_SIZE,
    directory   = train_dir,
    target_size = (IMG_HEIGHT, IMG_WIDTH),
    class_mode  = 'binary'
)

# Plot a single image 5 times with different augmentations
augmented_images = [train_data_gen[0][0][0] for _ in range(5)]
plotImages(augmented_images)

# ─── Cell 7: Build the CNN Model ────────────────────────────
model = Sequential([
    Conv2D(32, (3, 3), activation='relu', input_shape=(IMG_HEIGHT, IMG_WIDTH, 3)),
    MaxPooling2D(2, 2),

    Conv2D(64, (3, 3), activation='relu'),
    MaxPooling2D(2, 2),

    Conv2D(128, (3, 3), activation='relu'),
    MaxPooling2D(2, 2),

    Conv2D(128, (3, 3), activation='relu'),
    MaxPooling2D(2, 2),

    Flatten(),
    Dense(512, activation='relu'),
    Dropout(0.5),
    Dense(1, activation='sigmoid')   # Binary: cat=0, dog=1
])

model.compile(
    optimizer = 'adam',
    loss      = 'binary_crossentropy',
    metrics   = ['accuracy']
)

model.summary()

# ─── Cell 8: Train the Model ────────────────────────────────
history = model.fit(
    x               = train_data_gen,
    steps_per_epoch = train_data_gen.samples // BATCH_SIZE,
    epochs          = EPOCHS,
    validation_data = val_data_gen,
    validation_steps= val_data_gen.samples // BATCH_SIZE
)

# ─── Cell 9: Visualize Training History ─────────────────────
acc     = history.history['accuracy']
val_acc = history.history['val_accuracy']
loss    = history.history['loss']
val_loss= history.history['val_loss']

epochs_range = range(EPOCHS)

plt.figure(figsize=(8, 8))
plt.subplot(1, 2, 1)
plt.plot(epochs_range, acc, label='Training Accuracy')
plt.plot(epochs_range, val_acc, label='Validation Accuracy')
plt.legend(loc='lower right')
plt.title('Training and Validation Accuracy')

plt.subplot(1, 2, 2)
plt.plot(epochs_range, loss, label='Training Loss')
plt.plot(epochs_range, val_loss, label='Validation Loss')
plt.legend(loc='upper right')
plt.title('Training and Validation Loss')
plt.show()

# ─── Cell 10: Predict on Test Images ────────────────────────
test_data_gen.reset()
probabilities = model.predict(test_data_gen)
probabilities = [p[0] for p in probabilities]   # Flatten to 1D list

test_data_gen.reset()
test_images = [test_data_gen[0][0][i] for i in range(len(test_data_gen[0][0]))]
plotImages(test_images, probabilities=probabilities)

# ─── Cell 11: Evaluate (Pass/Fail Check) ────────────────────
# The freeCodeCamp test checks that accuracy >= 63%
# Re-evaluate on validation set
loss, accuracy = model.evaluate(val_data_gen)
print(f"\nValidation Accuracy: {accuracy * 100:.2f}%")
if accuracy >= 0.63:
    print("✅ PASSED! You met the 63% accuracy threshold.")
    if accuracy >= 0.70:
        print("🌟 BONUS: You hit 70%+ accuracy!")
else:
    print("❌ Not yet passing. Try more epochs, augmentation, or a deeper model.")
