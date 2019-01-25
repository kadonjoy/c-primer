#include <iostream>
#include <unistd.h>
#include <poll.h>
#include <pthread.h>

using namespace std;
struct ThreadData {
    struct pollfd pollFds[3];
    int fdNums;
};

static void * threadFunction(void *priv) {
    struct ThreadData* data = reinterpret_cast<struct ThreadData*>(priv);
    int pollStatus = 0;
    cout << "write fd: " << data->pollFds[0].fd << endl;
    cout << "read fd: " << data->pollFds[1].fd << endl;
    while(true) {
        pollStatus = ::poll(data->pollFds, data->fdNums, -1);
        if (pollStatus > 0) {
            if ((POLLIN == (data->pollFds[0].revents & POLLIN)) &&
                    (POLLRDNORM == (data->pollFds[0].revents & POLLRDNORM))) {
                ssize_t readLength;
                char buf[10];
                readLength = ::read(data->pollFds[0].fd, buf, sizeof(buf));
                if (readLength > 0) {
                    cout << " read data len: " << readLength << "content: " << buf << endl;
                    break;
                }
            }
        }
    }   
}

int main(int argc, const char *argv[]) {
    int pipefds[2];
    int status = ::pipe(pipefds);
    if(status < 0) {
        cout << "create pipe error. " << endl;
        return -1; 
    }   
    pthread_t phThread;
    ThreadData th_data;
    th_data.pollFds[0].fd = pipefds[0];
    th_data.pollFds[0].events = POLLIN|POLLRDNORM;
    th_data.fdNums = 1;
    
    if ( pthread_create(&phThread, 0, threadFunction, (void *)&th_data) != 0) {
        cout << "Failed to pthread_create." << endl;
        return -1;
    }
    sleep(2);
    ::write(pipefds[1], "kadonjoy", 10);

    if (pthread_join(phThread, NULL)) {
        cout << "Thread : " << phThread << "exist error." << endl;
        return -2;
    }
    return 0;
}
