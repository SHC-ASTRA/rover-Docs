#!/bin/bash

# Ensure at least one argument is provided
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 num1 [num2 ...]"
    exit 1
fi

# Array to store process IDs
pids=()

# Trap SIGINT and SIGTERM to kill all background processes on exit
trap 'echo "Interrupt received. Terminating background processes..."; kill "${pids[@]}"; exit 1' SIGINT SIGTERM

# Loop over all command-line arguments
for num in "$@"; do
    echo "Launching command for RTSP address: 192.168.1.${num}"
    gst-launch-1.0 -v playbin \
        uri="rtsp://192.168.1.${num}/user=admin&password=&channel=1&stream=0.sdp?" \
        uridecodebin0::source::latency=0 &
    # Save the PID of the background process
    pids+=("$!")
done

echo "All commands launched. Waiting for them to finish..."
# Wait for all background processes to complete
wait

