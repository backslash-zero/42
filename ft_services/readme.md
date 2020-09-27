# FT_SERVICES

## Container

A _cluster_ is a group of inter-connected computers that work together to perform computationally intensive tasks. In a cluster, each computer is referred to as a _node_.

## Kubernetes Dashboard

In case of a crash of one of the 2 database containers, we need to make sure the data is not list. Each container should be able to restart automatically if it crashes.

## Load Balancer

Should be cluster's only entry-point.  
*Load Balancer:*`FTPS`, `Grafana`, `nginx`, `phpMyAdmin`, `Wordpress`  
*ClusterIP:* `InfluxDB`, `MySQL`

## Services
All services will have their own dedicated containers, each one running under Alpine Linux.  

### nginx
Web server. Should be accessible via SSH.  
`Open on port 80(http) and 443(https) with auto 301 redirection.`

### FTPS
FTPS is an extension to the commonly used File Transfer Protocol that adds support for the Transport Layer Security.  
`Open on port 21.`

### Wordpress
Working with MySQL database. 1 admin and different users.  
`Open on port 5050.`

### MySQL
Database

### PHPMyAdmin
Link to the SQL database.  
`On port 5000`

### Grafana
Accessible on port 3000 working with influxDB. One Dashboard / Container.  
`On port 3000`

### InfluxDB
Database