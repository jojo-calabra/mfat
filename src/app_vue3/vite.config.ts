import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'

// load environment variables from environment variables
import { loadEnv } from 'vite'
const env = loadEnv('', process.cwd())

// https://vitejs.dev/config/
export default defineConfig({
  plugins: [vue()],
  server: {  // Exposes the server to the docker internal network
    host: true,
    // load port from environment variables otherwies use default port 56123
    port: Number(env.VITE_PORT || 5173),
  },
})