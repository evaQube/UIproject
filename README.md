# MVVM Based Game UI Widget Library
This project is a widget library for video game user interfaces built entirely in **C++**, using **SFML** for rendering and **CMake** for project generation.
> [!NOTE]
> _This library is still in its early development stages and is not yet ready for use._

## Overview
The main motivation behind this project is to improve my C++ skills and learn to apply the **Model–View–ViewModel (MVVM) architectural pattern**, which is extremely useful for implementing video game UIs. Its strength lies in the **clear separation of responsibilities** it enforces: one developer can focus on the **Model** (game data and logic) while another works on the **View** (visual presentation), with the **ViewModel** acting as the bridge between them. This separation not only makes the UI **easier to maintain and extend**, but also enables **greater code reusability**: a single Model can support countless Views, each displaying the same data in entirely different ways.

Ultimately, the goal of this project is to provide a collection of **reusable widgets** suitable for any game project and a **showroom**, where each widget can be demonstrated and tested interactively.

## Project Structure
- [WidgetLibraryEvaQube](/WidgetLibraryEvaQube) contains all the components that make up the widget library.
- [Root](/) directory contains the files for the showroom.

Each widget is built following the MVVM structure:
- **Model**	holds the data and core logic.
- **ViewModel**	provides a specific “shape” of data and exposes commands. It has no knowledge of how the data is displayed or where it comes from. Serves as the bridge between Model and View.
- **View**	displays the data as defined by the ViewModel. It has no knowledge of the data source or logic behind it.

### Widget List
- [x] **Text**
- [x] **Image**
- [x] **Button**
- [ ] **Progress Bar**
- [ ] **Slider**
- [ ] **Checkbox**
- [ ] **Input Field**
- [ ] **Scroll Box**
- [ ] **Throbber**

The goal is for all widgets to be **data-driven**, **scalable**, and **responsive** to different screen sizes. Future development will also include **layout features** such as:
- [ ] Horizontal and vertical boxes
- [ ] Grid layouts
- [ ] Anchors and masking support

## Current Development Status
Development is currently focused on building the widgets in their most **basic form**, with the goal of gradually expanding them by adding features that allow for **deeper customization** and more **advanced behavior**. Once a solid set of widgets is complete, I’ll begin working on the **showroom**, which will serve both as a **demo environment** to visualize each element in action and as a **testing ground** for refining and improving the existing components based on how they perform.

<p align="left">
  <img src="https://github.com/user-attachments/assets/a12d0db1-df41-49d1-8bef-9baceb4e6092" alt="Text functioning"/>
</p>

> **WIP** - Text functioning
