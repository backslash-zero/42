# ensure minikube version

# minikube version
minikube start
# get minikube ip
IP=$(minikube ip)

# enable metalLB
minikube addons enable metallb
# minikube addons configure metallb
# enable and open dashboard 
# minikube addons enable dashboard
minikube addons list
minikube dashboard

# xdg-open http://$IP