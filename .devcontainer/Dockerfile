# Use Ubuntu 20.04 LTS as the base image
FROM ubuntu:20.04

# Set noninteractive installation to avoid timezone prompt
ARG DEBIAN_FRONTEND=noninteractive

# Set up the environment for OMNeT++
ENV OMNETPP_HOME=/opt/omnetpp

# Set the working directory in the container for OMNeT++ installation
WORKDIR $OMNETPP_HOME

# Install OMNeT++ dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    g++ \
    bison \
    flex \
    perl \
    x11-apps \
    python3 \
    python3-pyqt5 \
    python3-pyqt5.qtsvg \
    qt5-default \
    libqt5opengl5-dev \
    tcl-dev \
    tk-dev \
    libxml2-dev \
    zlib1g-dev \
    libosgearth-dev \
    wget \
    sudo

# Set environment variables for OMNeT++
ENV PATH="$OMNETPP_HOME/bin:$PATH"

# Download and install OMNeT++
RUN wget -O omnetpp.tar.gz https://github.com/omnetpp/omnetpp/releases/download/omnetpp-5.6.2/omnetpp-5.6.2-src-linux.tgz && \
    tar -xzf omnetpp.tar.gz --strip-components=1 && \
    ./configure WITH_OSGEARTH=FALSE WITH_OSG=FALSE && \
    make

# Add your application's bin directory to the PATH
ENV PATH="/tmp/ROS2_TSN_ws/bin:$PATH"

# Install Java (OpenJDK)
RUN apt-get update && apt-get install -y openjdk-11-jdk

# Set JAVA_HOME (useful for many Java applications)
ENV JAVA_HOME /usr/lib/jvm/java-11-openjdk-amd64
ENV PATH $JAVA_HOME/bin:$PATH

# Install a firefox
RUN apt-get update && apt-get install -y firefox
ENV BROWSER=/usr/bin/firefox

# Cleanup to reduce image size
RUN apt-get clean \
    && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Define the default working directory where your source code is located
WORKDIR /tmp/ROS2_TSN_ws/src/ROS2_TSN

# Define default command to keep the container running
CMD ["/bin/bash"]

