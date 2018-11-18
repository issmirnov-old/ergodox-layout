# Linux Specific Config

In order to flash firmware, you will need to update the [udev rules](https://www.pjrc.com/teensy/loader_linux.html).

```
sudo cp 49-teensy.rules /etc/udev/rules.d/49-teensy.rules
```

## Notes

`hid_listen` needs to be run with `sudo` on linux systems

Compiled on ubuntu 16.04
