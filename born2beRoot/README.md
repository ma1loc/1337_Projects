# NEED TO KNOW

## Hypervisor Virtualization

Hypervisor virtualization allows one physical machine (host) to run multiple virtual machines (VMs) by sharing hardware resources.  
Types:  

- **Type 1 (Bare-metal):** Runs directly on the hardware (e.g., VMware ESXi, Hyper-V).  
- **Type 2 (Hosted):** Runs on top of an operating system (e.g., VirtualBox, VMware Workstation).  

It enables isolation, efficient resource usage, and easy VM management.

---

## UTM && VirtualBox

### UTM
- **Platform:** macOS (best for Apple Silicon) and Linux.  
- **Strengths:**  
  - Simple and lightweight.  
  - Great for emulating non-x86 systems (e.g., ARM).  
  - No extra kernel modules needed.  
- **Limitations:**  
  - Less performance optimization for x86 systems.  
  - Lacks 3D acceleration and advanced features for gaming.  

### VirtualBox
- **Platform:** Windows, macOS, Linux.  
- **Strengths:**  
  - Better performance for x86 systems, especially with 3D acceleration.  
  - Advanced features (snapshots, seamless mode, resource management).  
  - Larger community and better support.  
- **Limitations:**  
  - Requires kernel modules on some systems (Linux).  
  - More complex setup than UTM.  

### Recommendation:
- **UTM:** Best for simple use on macOS (especially Apple Silicon) and Linux, especially if you don’t need heavy performance.  
- **VirtualBox:** Best for x86/x64 systems and more resource-heavy tasks, including gaming and advanced features.  

**Note:** Like VirtualBox, UTM is cross-platform and runs on macOS and Linux.

---

## QEMU & UTM Relationship

Yes, UTM without QEMU is nothing! UTM relies on QEMU for its core functionality. Without QEMU, UTM wouldn't be able to provide virtualization or emulation features.  

- **QEMU:** Handles the hardware emulation and virtualization, enabling UTM to run virtual machines and support multiple architectures.  
- **UTM:** Provides a user-friendly interface, making it easier to set up and manage virtual machines using QEMU under the hood.

---

## kdump

`kdump` is a service that provides a crash dumping mechanism. It enables you to save the contents of the system memory for analysis.

---

## Steps of Booting the System

1. **BIOS/UEFI:** Initializes the hardware and performs POST (Power-On Self-Test).  
2. **Bootloader:** Loads the operating system (e.g., GRUB).  
3. **Kernel Initialization:** Loads the Linux kernel and initializes hardware.  
4. **Init/Systemd:** Starts system processes and services.  
5. **Login Prompt:** Displays a login interface for the user.

---

## Partitioning (LVM)

Partition sizes are typically represented in Gibibytes (GiB). This means:  

- 1 GiB = 1,024 MiB (binary system, base 2).  
- 1 MiB = 1,024 KiB.  

**Example Partition Layout:**

| Partition   | Size     | File System |
|-------------|----------|-------------|
| /boot       | 525 MB   | ext4        |
| /root       | 10.7 GB  | ext4        |
| swap        | 2.5 GB   | swap        |
| /home       | 5.4 GB   | ext4        |
| /var        | 3.2 GB   | ext4        |
| /srv        | 3.2 GB   | ext4        |
| /tmp        | 3.2 GB   | ext4        |
| /var/log    | 4.3 GB   | ext4        |

### Q&A

1. **Why is `/boot` primary, not logical, and at the beginning?**  
   `/boot` must be primary and at the beginning for compatibility with certain bootloaders that rely on it.  

2. **What is ext4 journaling?**  
   ext4 uses a journaling mechanism to prevent file system corruption during unexpected shutdowns.  

3. **What is NTFS?**  
   NTFS is a file system primarily used by Windows with advanced features like encryption and compression.  

4. **Difference between `ssh` and `sshd_config`?**  
   - `ssh`: Client used to connect to remote servers.  
   - `sshd_config`: Configuration file for the SSH daemon (server-side).  

5. **What is SELinux or AppArmor?**  
   Both are security modules that enforce access control policies for processes.

---

### Mandatory Commands to Know

- `lsblk`: Lists information about block devices.  
- `systemctl`: Manages system services.  
- `chage -l`: Displays user account password aging information.  
- `useradd`: Adds a user (-m creates a home directory).  
- `hostnamectl`: Shows or changes the hostname.  
- `sudo -l -U [username]`: Shows the sudo privileges for a user.  
- `getent`: Displays information from system databases (e.g., passwd or group).  
- `journalctl`: Displays system logs.  
- `ip add`: Shows network interface information.  
- `export`: Sets environment variables.  
- `gpasswd -d`: Removes a user from a group.
---
## Firewall (UFW)

**Forbidden to use GUIs like X.org.**  
**Useful commands:**

```bash
sudo ufw status  
sudo ufw reset  
sudo ufw allow ssh / 22  
sudo ufw enable  
sudo ufw status numbered
```

Password Complexity

Configure using PAM (Pluggable Authentication Modules):

    retry=3: Maximum password retries.
    minlen=8: Minimum password length.
    difok=3: Ensures the new password is different from the old.
    maxrepeat=3: Limits repeated characters (e.g., "aaa").
    ucredit=-1: Requires at least one uppercase letter.
    lcredit=-1: Requires at least one lowercase letter.
    dcredit=-1: Requires at least one number.
    ocredit=-1: Requires at least one special character.
    enforce_for_root: Ensures root also follows these rules.

sudo ufw delete [rule number]
sudo ufw delete allow 8080 "delete both the ipv4 and ipv4 port"

### files in linux

### “everything is linux is a file”

#### During OS boot?

- **BIOS/UEFI** → Hardware checks and bootloader.
- **Bootloader** → Loads and starts the kernel.
- **Kernel** → Initializes hardware and mounts root filesystem.
- **Init System** → Starts essential services and processes.
- **Login Prompt** → Provides user login access (CLI or GUI).

### File system?

/etc → system configuration.

/bin → essential user binaries (commands) to interact to the system.

/sbin → essential su(super user) user binaries (su commands) to interact to the system as a su.

/lib → library essential for /bin and /sbin.

/sys → information about drivers, and kernel features.

/var → variable files that change every OS run (log files).

/root → default home folder for root

/home → user homes folders

/mnt → mount points (**Mounting**: Making a device or filesystem accessible at a directory.)

### path you have to use in the (B2beR)
/etc/ssh/sshd_config → config the ssh serves

/etc/login.defs → config the chage

/etc/pam.d/common-password → config password policy

/var/log/ → the logs files system

### Process?

_> An **init system** is the **first process** started by the Linux kernel when the system boots up. It is responsible for:

- **Starting and stopping services** (like networking, SSH, and system logging).
- **Managing processes** during boot and shutdown.
- Running as the **parent process** for all other processes.

## Linux ?

### Linux, debian, centos, community

First thing the GNU/Linux is a combination of GNU tools and the Linux kernel.

- the GNU is a combination of tools that the OS needs (like that the bash commands

including the gcc ;),

is a complete operating system built on top of the **Linux kernel** and often includes:

- The **Linux kernel** (the core of the OS).
- GNU tools and utilities (like `bash`, `ls`, etc.).
- Package management systems.
- Other software for functionality (desktop environments, applications, etc.).

ex: Ubuntu is **based on Debian**, meaning Ubuntu uses Debian's structure, tools, and package management as its foundation but adds its own features.

_> Centos is a distro maintained by RedHat and aimed for professionals.

Centos is open source rather than Redhat is (**commercial).**

Debian is the first community driven distro that have a huge popularity.

In short, **Debian** is a popular choice because of its **stability.**

A **vCPU** is a virtual processor assigned to a virtual machine, representing a share of the physical CPU's resources.

## what is linux?

_> Kernel is a program that control over the hardware and system.

The kernel provides basic important services tohardware the OS, and the kernel image is usually

loaded to a protected area of the memory called **“kernel space”**  to avoid accidental overwrite

poorly designed programs.

ensure priviliged access to resources by emplying the **“Protection rings heriarchy”**

###structure of kernel?

The linux kernel was first developed by the famous linus on 1991, open source code are publicly
https://github.com/torvalds/linux


Kernel controlling operating system’s  access to resources and play the critical role.

user cannot directly interact with the kernel but processes can through the **“systemcalls”**

### A Kernel module is a pieces of code that extend the functionalities of the kernel

## LVM

### what’s LVM?

_> LVM(Logical Volume Manager) it’s a **tool** in Linux that manages storage by combining disks/partitions into **logical volumes** for easier resizing and management.

LVM allows to merge multiple blocks of devices into a large Storage:

Why the **“BOOT”** partition it can not be Manage by the **LVM**?

_> **bootloader** is a program responsible for loading the kernel from /boot into the memory during

system startup.

The **/boot** partition cannot be managed by **LVM** because the **bootloader not understand the LVM structure.**

In summary, **/boot** can be either primary or logical, but it must not be managed by LVM.

What is the **“ext4”** ?

_> **ext4** is a filesystem used by Linux operating systems to manage how date is stored and

accessed on storage devices

- The **behind-the-scenes** details of how a filesystem like **ext4 manages your files;**

**_Data Blocks**: The Files are stored in a small chunks called **data blocks,** if you have a 1MB file, the filesystem divides it into smaller blocks.

**_Inodes:** it stores important information about the file, like, (size, permissions, location, creation_time).

NOTE: Journaling in a filesystem logs changes before they are written to disk

## Rocky & Debian

**Rocky and Debian are both distributions, but they deffer.**

_> Rocky Linux:

→ derived from Red hat enterprise linux (rhel).

→ that use the [RPM Package Manager](https://en.wikipedia.org/wiki/RPM_Package_Manager) The name RPM refers to the .rpm

_> Debian:

→ An independent, **community-driven** distribution.

→ Debian is not "owned" by a company like Red Hat owns RHEL or like Ubuntu is managed by Canonical.

→ Founded in **1993** by **Ian Murdock**

→ These are **official members** of the Debian Project who have gone through a process to demonstrate their skills and dedication to the community.

They can:

- Upload software packages.
- Fix bugs.
- Vote on important project decisions.

**Rocky Linux**:

- Enterprise servers, production.
- RHEL-level stability
- Long-term (10 years support)

**Debian**:

- General-purpose, desktops, servers.
- Extremely stable (Stable branch).
- Stable, Testing, Unstable

## Apparmor

### What apparmor is?

That’s what makes Linux batter with the security (i mean one of them ;) ).

_> “Apparmor” is one of the tools that enhance the Linux security.

AppAromr is a  Mandatory Access Control (MAC) System to restrict (**limitation**) the actions of applications.

**AppArmor checks the application's profile** to see if that action is allowed. If the action is allowed by the profile, **AppArmor grants access**.

If the action is **not allowed** by the profile, **AppArmor prevents access** and the application is blocked from performing that action.

and it works by creating **Profiles** for each application defining what resources (files, network, etc) that the application can access.

**Application Profiles** → each application has a profile that specifies which resources it can access.

So, AppArmor checks the profile **first** to determine if the action is allowed. If it isn't, the access is **prevented** based on the profile’s restrictions.

### How to see the profile’s?

note: check if AppArmor is active by ”systemctl status apparmor” command

→ aa-status(command) - display various information about the current AppArmor policy.

# SSH

Secure Shell Networking protocol provides a secure connection between unsecured networking, with the default port number 22. SSH is a protocol that replaces the telnet(23) protocol.

_> How the SSH connection works between the (client && server)?

 No,     Client (+1024)                                                  Server (22)

1#       [SYN] ——————————————————— >

2#       <——————————————————— [ACK + SYN]

3#       [ACK] ——————————————————— >

4#       [Client info] -—-——————————————— >

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

4# → the client sends its info (like; type of ssh server, version of the protocol, OS they use)

Note: the first steps are called **“SSH handshake”**

5#      <——————————————————— [ACK]

6#      <——————————————————— [Server info] //same 4#

7#      ——————————————————— > [ACK]

8#      ——————————————————— > [Client Key Exchange Init]

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

8# → The **"Key Exchange Init"** step in SSH is part of the process to establish a secure connection between the client and the server. It happens early during the SSH handshake to ensure that both parties can securely communicate.

The exchange includes:

1. **Encryption Algorithms** (e.g., AES, ChaCha20) - used to encrypt the data.
2. **Key Exchange Algorithms** (e.g., Diffie-Hellman, ECDH) - used to generate a shared session key.
3. **Message Authentication Code (MAC)** Algorithms - to ensure data integrity.
4. **Compression Methods** - optional compression algorithms.
5. **Public Key Algorithms** - for verifying the server's host key (e.g., RSA, ECDSA).

This step ensures that both client and server **agree on secure algorithms** to communicate safely.

9#    <——————————————————— [Server Key Exchange Init] //same 8#

10#  ———————————————————> [ACK]

11#  ———————————————————> [Client Diffie-hellman Key Exchange Init]

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

11# → In this step, the client starts the **Diffie-Hellman key exchange process**. Here's what happens:

1. The client generates a **random private key** a (a secret large number).
2. Using the agreed **prime number** p and **generator** g (from the earlier steps), the client calculates its **public key** A=gamodp.
    
    A=gamod  pA = g^a \mod p
    
3. The client sends its **public key** A to the server.

Note: that’s what called “Public Key”

**12#**

1. The server generates its **random private key** b (a secret large number).
2. The server calculates its **public key** B=gbmodp using the same p and g.
    
    B=gbmod  pB = g^b \mod p
    
3. The server sends its **public key** B back to the client along with its **host key** (used to verify the server's identity).
4. The host key is signed to ensure it comes from the legitimate server.

Sorry I’m done, you can check for more about the SSH at https://goteleport.com/blog/ssh-handshake-explained/
# "I know there are a lot of things I haven't covered."
## check this out for more information
### about to know -> https://miro.com/app/board/uXjVPEVHTXk=/
### about how to https://42-cursus.gitbook.io/guide/rank-01/born2beroot
### ammmm https://baigal.medium.com/born2beroot-e6e26dfb50ac
