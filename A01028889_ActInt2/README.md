# Integrative Activity 2


- **Name**: Ricardo Alfredo Calvo Pérez
- **ID**: A01028889
- **Date**: 23/11/2024

- **Goal**: Solve two interconnected graph problems:
  1. Determine the optimal way to connect cities (colonias) with fiber-optic cables at minimum cost.
  2. Calculate the shortest route for a delivery person to visit every city exactly once and return to the starting city.

---

## Overview

This Python-based tool is designed to solve two specific problems for a city transitioning into modern infrastructure:

1. **Cable Problem**: Determine the optimal way to connect all cities with fiber-optic cables using the Minimum Spanning Tree (MST).
2. **Traveler's Problem**: Calculate the shortest possible route that visits each city exactly once and returns to the starting point (Traveling Salesman Problem - TSP).

The program can read graphs from files or generate random graphs for testing. It visualizes the solutions and provides detailed outputs for the MST and TSP.

---

## Problem Details

### 1. **Cable Problem**
- **Objective**: Determine the optimal way to connect cities with fiber-optic cables, minimizing the total connection cost.
- **Output**:
  - A list of edges representing the cable connections (e.g., `(A, B)`).
  - The total cost of the cable installation.

### 2. **Traveler's Problem**
- **Objective**: Find the shortest cyclic route that visits each city once and returns to the starting city. This route is used for distributing physical account statements, advertisements, and notifications.
- **Output**:
  - The sequence of cities in the shortest route (e.g., `A → B → C → A`).
  - The total cost of the route.

---

## Input and Output

### **Input**:
1. An integer `N` representing the number of cities (nodes).
2. An adjacency matrix of size
`N x N` representing the distances (in kilometers) between cities. A distance of `-1` indicates no direct connection between two cities.

### **Output**:
1. The **Cable Problem** solution:
   - The list of edges in the MST (`(A, B)` format).
   - The total cost of connecting the cities.
2. The **Traveler's Problem** solution:
   - The shortest cyclic route visiting all cities.
   - The total cost of the route.

---

## Features

- **File-Based Input**: Read graphs from a file in the specified adjacency matrix format.
- **Random Graph Generation**: Create random graphs for testing with user-defined nodes.
- **Cable Problem Solver**:
  - Uses Prim's Algorithm to compute the Minimum Spanning Tree (MST).
- **Traveler's Problem Solver**:
  - Uses a heuristic-based nearest neighbor approach to calculate the Traveling Salesman Problem (TSP).
- **Visualization**: Display graphs with weights and solution paths.
- **Adjacency Matrix Utilities**: Print and save adjacency matrices for better analysis.

---

## Requirements

- Python 3.6 or higher
- Required Python libraries:
  - `matplotlib`
  - `networkx`

Install dependencies using:
```bash
pip install matplotlib networkx
