#getting Ubuntu image and Node version
FROM ubuntu:20.04
FROM node:18 AS build

#Installing the compiler module
RUN apt-get update && apt-get install -y \
    g++ \
    make

#Defining the workdir
WORKDIR /app

#Copying the resources to the workdir
COPY . /app
COPY package*.json ./

#Installing dependencies
RUN npm install

#Building the application
RUN npm run build

#Serving the app with Nginx
FROM nginx:alpine

#Copy built assets from the previous stage
COPY --from=build /app/dist /usr/share/nginx/html

#Copying Nginx config files
COPY nginx.conf /etc/nginx/conf.d/default.conf

#Expose the app port
EXPOSE 80

#compiling the code
RUN g++ -o main main.cpp

#running the code when the container is initialized
CMD ["nginx", "-g","daemon off"]

