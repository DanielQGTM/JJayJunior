# Use a prebuilt C++ container
FROM mcr.microsoft.com/devcontainers/cpp:1-debian-11

# Install additional dependencies (if needed)
RUN apt-get update && apt-get install -y cmake

# Set working directory
WORKDIR /workspaces/JJayJunior

# Prevent errors with missing scripts
RUN touch /tmp/reinstall-cmake.sh && chmod +x /tmp/reinstall-cmake.sh
