# DaisyFxProject

Basic Fx Project with all required libraries, etc. (+Terrarium)

## Get Started

If cloning this repo from Github, you will want to do so with the submodules with:

```console
git clone https://github.com/soundg33k/DaisyFxProject --recurse-submodules
```

if you've already cloned the repo without this you can fill the submodules by running the following:

```console
git submodule update --init
```

Alternatively, you can avoid using git, and building libraries if you download the latest zip compiled zip file in the releases.

## Contents

Includes:

* libDaisy - hardware library for Daisy
* DaisySP - DSP library
* Terrarium - Terrarium hardware defines
* Fx - Passtrough Fx

This also contains the following VS code tasks:

* Build Libraries: builds libDaisy, and DaisySP from scratch. This is only necessary when manually updating, or cloning for the first time.
* Build: build the Fx example
* Clean: removes compiled Fx code
* Program : programs the Fx.bin file via probe
* Build and Program : Rebuilds the program and downloads it via probe
* Program DFU: programs the Fx.bin file via USB
* Build and Program DFU: Rebuilds the program and downloads it via USB DFU

In addition, the following debug configurations are available:

* Debug Fx: debugs the Fx application

**Note**: debugging an application from VS Code requires an ST-Link or similar probe, as well as the Cortex Debug extension for VS Code.
