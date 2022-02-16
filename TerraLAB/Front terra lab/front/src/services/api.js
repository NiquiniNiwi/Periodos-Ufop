import axios from 'axios';

const api = axios.create({
    baseURL: 'https://release-cavemaps.herokuapp.com'
});

export default api;