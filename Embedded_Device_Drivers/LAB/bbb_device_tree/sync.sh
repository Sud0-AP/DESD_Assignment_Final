#!/bin/bash

# --- CONFIGURATION ---
# Replace with your BeagleBone Black username and IP address
BBB_USER="debian"
BBB_IP="192.168.7.2"

# Where on the BeagleBone should all your project folders live?
BBB_BASE_DIR="/home/debian/DESD_LDD_26_AR"
# ---------------------

# Automatically get the name of the folder where THIS script is saved
LOCAL_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
FOLDER_NAME=$(basename "$LOCAL_PATH")

ACTION=${1:-push} # Defaults to 'push' if you don't type anything

# The destination path on the BeagleBone
BBB_PATH="${BBB_BASE_DIR}/${FOLDER_NAME}"

case "$ACTION" in
    push)
        echo "=> Syncing: Local [${LOCAL_PATH}] -> BeagleBone [${BBB_PATH}]"
        # Ensure the base directory exists on the BeagleBone
        ssh "${BBB_USER}@${BBB_IP}" "mkdir -p ${BBB_BASE_DIR}"
        
        # Sync the folder contents, excluding the script itself
        rsync -avz --delete --exclude='sync.sh' "${LOCAL_PATH}/" "${BBB_USER}@${BBB_IP}:${BBB_PATH}/"
        echo "✓ Push complete."
        ;;
        
    pull)
        echo "=> Syncing: BeagleBone [${BBB_PATH}] -> Local [${LOCAL_PATH}]"
        
        # Sync back to PC, preventing any remote deletions from removing the script locally
        rsync -avz --delete --exclude='sync.sh' "${BBB_USER}@${BBB_IP}:${BBB_PATH}/" "${LOCAL_PATH}/"
        echo "✓ Pull complete."
        ;;
        
    *)
        echo "Invalid action: $ACTION. Use './sync.sh' or './sync.sh pull'."
        exit 1
        ;;
esac
