# ZMK Config for My 60% BLE Keyboard

## Hardware
- MCU: E73-2G4M08S1C (nRF52840)
- Matrix: 5 rows × 10 columns
- Encoder: 1 rotary encoder
- Battery monitoring: Yes

## File Structure
```
zmk-my60ble/
├── zephyr/module.yml          # Registers this as a Zephyr module (CRITICAL!)
├── Kconfig                    # Root Kconfig for module
├── CMakeLists.txt             # Root CMake for module
├── build.yaml                 # Defines what to build
├── .github/workflows/
│   └── build.yml              # GitHub Actions build
├── config/
│   ├── west.yml               # West manifest
│   ├── my60ble.keymap         # Your keymap
│   └── my60ble.conf           # Configuration
└── boards/arm/my60ble/
    ├── Kconfig.board          # Board registration
    ├── Kconfig.defconfig      # Board defaults
    ├── board.c                # Board initialization
    ├── CMakeLists.txt         # Board build config
    ├── my60ble.yaml           # Board metadata
    ├── my60ble_defconfig      # Board configuration
    └── my60ble.dts            # Hardware definition
```

## How to Use

1. **Upload to GitHub:**
   - Create new repository (e.g., `zmk-config-my60ble`)
   - Extract this archive
   - Push all files to GitHub

2. **GitHub Actions will build automatically**

3. **Download firmware:**
   - Go to Actions tab
   - Click latest build
   - Download firmware artifact
   - Extract `my60ble.uf2`

4. **Flash:**
   - Connect keyboard via USB
   - Double-press reset button
   - Copy `.uf2` to the drive

## Pin Assignments

### Matrix (COL2ROW)
- Rows: P1.00, P1.04, P1.06, P1.09, P1.11
- Cols: P1.10, P0.28, P1.13, P0.29, P0.31, P0.30, P0.07, P0.13, P0.24, P0.09

### Encoder
- A: P0.22
- B: P0.20

## Why This Structure Works

The key difference from failing attempts is the **zephyr/module.yml** file. This registers your config repo as a Zephyr module, which allows ZMK to find your custom board definition.

Without this file, ZMK won't see `boards/arm/my60ble/` and will report "No board named 'my60ble' found."

## Troubleshooting

If build fails with "No board named 'my60ble' found":
- Verify `zephyr/module.yml` exists
- Check that root `Kconfig` has the rsource line
- Ensure all board files are in `boards/arm/my60ble/`

## License
MIT
