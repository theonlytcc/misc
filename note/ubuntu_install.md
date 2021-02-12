# The problem meet in ubuntu

## FAQ
1. Ubuntu can not be opened, and in recovery mode, there is a log of print that
AER is happened.

It is because the PCIE RC and the pcie device are in different power state.
The resolution is to close the AER or close the power management.
a parameter "pcie_aspm=off", is add to the grub command line
