# OC
[![Build Status](https://travis-ci.org/abner-ma/OC.svg?branch=master)](https://travis-ci.org/abner-ma/OC)
---
Oh,the C program.Also mean Oh see!
test for myself.


Filebench load performance evaluation
In order to verify the overall performance of URFS, this section uses Filebench's fileserver, varmail, webserver, and webproxy to test three file systems including URFS. In order to be able to call the access interface of the related user-space file system, the Filebench code was slightly modified, and unsupported operations such as link and unlink were implemented as empty functions. BlobFS and BlueFS do not support random writes. At the same time, they have directory support defects and failed to complete related tests.
The experimental results are shown in Figure 8:
As shown in Figure 8 (a), for the fileserver scenario, it can be seen from the results that URFS leads the second-ranked UNFS by about 11.7%, which is about 64.4% higher than nvfuse. The fileserver scenario simulates file sharing, reading, writing, and other operations in a file server. These operations rely heavily on the performance of metadata. The aforementioned experiments also prove that URFS has better metadata performance overall, so it can lead under such loads.
For the varmail scenario, URFS leads the second-ranked nvfuse by about 33.3%, and the UNFS test results are close to nvfuse. In the varmail scenario, the file size is small. According to the test results, URFS's elastic separation technology of multi granularity IO queue plays a certain role.
In the webproxy scenario, the IOPS of URFS is also higher than other file systems, leading the second-ranked UNFS by about 34%. According to analysis, webproxy is a read-intensive workload scenario, which involves appending and re-reading files. Obviously, the user-space multi-process shared memory framework proposed in URFS can also play a role in this scenario and play the role of read cache.
As shown in Figure 8 (b), the test results of the webserver scenario are similar to the webproxy scenario, with URFS leading the second-ranked UNFS by about 35.3%. The webserver scenario has more read operations than the webproxy scenario, and therefore shows a higher OPS value.
