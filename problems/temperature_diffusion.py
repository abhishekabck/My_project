import numpy as np
import matplotlib.pyplot as plt

# Parameters
length = 1.0  # Length of the rod (meters)
time = 0.1    # Total time (seconds)
dx = 0.01     # Space step (meters)
dt = 0.0001   # Time step (seconds)
alpha = 0.01  # Thermal diffusivity (m^2/s)

nx = int(length / dx) + 1  # Number of spatial points
nt = int(time / dt)        # Number of time steps

# Initialize temperature array
u = np.zeros(nx)           # Current temperature
u_new = np.zeros(nx)       # Next temperature

# Initial conditions: Heated at one end
u[0] = 100  # Temperature at the left end (100°C)
u[-1] = 20  # Temperature at the right end (20°C)

# Time-stepping loop
for t in range(nt):
    for i in range(1, nx - 1):
        u_new[i] = u[i] + alpha * dt / dx**2 * (u[i+1] - 2*u[i] + u[i-1])
    
    # Update temperature
    u[:] = u_new[:]
    
    # Plot at specific intervals
    if t % 500 == 0:  # Every 500 time steps
        plt.plot(np.linspace(0, length, nx), u, label=f'Time = {t*dt:.3f} s')

# Final plot settings
plt.title("Heat Diffusion in 1D Rod")
plt.xlabel("Position along rod (m)")
plt.ylabel("Temperature (°C)")
plt.legend()
plt.show()