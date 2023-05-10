import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'

// load environment variables from .env file
import dotenv from 'dotenv'
import path from 'path'
dotenv.config({ path: path.resolve(__dirname, '../../.env') }) // load .env file from root directory

// https://vitejs.dev/config/
export default defineConfig({
  plugins: [vue()],
  server: {  // Exposes the server to the docker internal network
    host: true,
    port: Number(process.env.VUE3_APP_PORT_DOCKER) || 56123, // load port from .env file or use default value
  },
})