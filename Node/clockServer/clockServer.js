/*
 * @Author: BreettySun
 * @Date: 2023-04-09 23:25:43
 * @LastEditors: BreettySun
 * @LastEditTime: 2023-04-09 23:57:06
 * @FilePath: \Scream-Repo\Node\clockServer\clockServer.js
 * @Description: 
 * 
 * Copyright (c) 2023 by BreettySun, All Rights Reserved. 
 */
const http = require('http')
const fs = require('fs')
const path = require('path')

const server = http.createServer()

server.on('request', (req, res) => {
  // 获取请求路径
  const url = req.url
  // 根据请求路径获取对应的文件路径
  let fpath = ''
  if (url === '/') {
    fpath = path.join(__dirname, './clock/index.html')
  } else {
    fpath = path.join(__dirname, './clock', url)
  }

  // 读取文件
  fs.readFile(fpath, (err, data) => {
    if (err) {
      res.end('404 Not Found')
      return
    }
    res.end(data)
  })

  console.log(fpath);
})

server.listen(3000, () => {
  console.log('Server is running at http://127.0.0.1:3000')
})