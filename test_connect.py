import os
import socket


def main():
    host = os.environ.get("IHD_SERVER", "127.0.0.1")
    port = int(os.environ.get("IHD_PORT", "5673"))
    timeout = float(os.environ.get("IHD_CONNECT_TIMEOUT", "5"))

    print(f"IHD_SERVER={host}")
    print(f"IHD_PORT={port}")
    print(f"Checking TCP connection to {host}:{port} ...")

    try:
        with socket.create_connection((host, port), timeout=timeout):
            print("[OK] TCP connection succeeded")
    except Exception as exc:
        print(f"[ERROR] TCP connection failed: {exc}")
        raise SystemExit(1)


if __name__ == "__main__":
    main()
