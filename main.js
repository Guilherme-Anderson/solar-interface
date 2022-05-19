const { app, BrowserWindow } = require('electron')


let mainWindow

app.on('ready', () => {
  mainWindow = new BrowserWindow({
    width: 1100,
    height: 600,
    fullscreen: false,
    titleBarStyle: 'hiddenInset',
    titleBarOverlay: true,
    frame:false,
    webPreferences: {
      nodeIntegration: true,
      contextIsolation: false
    }
  })

  mainWindow.loadURL(`file://${__dirname}/index.html`)
//mainWindow.webContents.openDevTools()

})
