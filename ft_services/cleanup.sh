echo "Deleting ingresses\n"
kubectl delete --all ingresses
echo "Deleting deployments\n"
kubectl delete --all deployments
echo "Deleting pods\n"
kubectl delete --all pods
echo "Deleting services\n"
kubectl delete --all services
echo "Deleting pvc\n"
kubectl delete --all pvc

# Delete all unused Docker images and cache and free SO MUCH SPACE on your computer
echo "Deleting unused Docker images and cache\n"
docker system prune

