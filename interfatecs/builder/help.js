const axios = require('axios');
const fs = require('fs');
const path = require('path');
const FormData = require('form-data');

async function build({ basename, fullname, timelimit, probleminput, problemsol, problemdesc, download }) {
  const data = new FormData();

  data.append('Submit5', 'Send');
  data.append('confirmation', 'confirm');

  data.append('basename', basename);
  data.append('fullname', fullname);
  data.append('timelimit', timelimit);

  data.append('probleminput', fs.createReadStream(probleminput), `${basename}.in`);
  data.append('problemsol', fs.createReadStream(problemsol), `${basename}.out`);
  data.append('problemdesc', fs.createReadStream(problemdesc), `${basename}.pdf`);

  const url = 'http://localhost:8000/boca/admin/problem.php';
  const headers = {
    'Cookie': 'biscoitobocabombonera=1724611576-2124e01da117a0705940ab8cf4e748422829e36963a3111c7655ac90abcdcd8d; _ga=GA1.1.663677135.1724356777; _ga_TBTX7EY2NW=GS1.1.1724359752.2.1.1724362422.0.0.0; PHPSESSID=599bjs3mv8gsigs2debkblo419',
    ...data.getHeaders()
  };

  const response = await axios.post(url, data, { headers, responseType: 'stream' });

  const outputPath = path.resolve(download);

  const writer = fs.createWriteStream(outputPath);

  response.data.pipe(writer);

  return new Promise((resolve, reject) => {
    writer.on('finish', resolve);
    writer.on('error', reject);
  });
}

function resolvePath({ year, phase, problem }) {
  let baseName;

  if (phase !== null && !['Fase 1', 'Fase 2'].includes(phase)) {
    baseName = path.resolve(__dirname, '..', year, problem);
  } else {
    baseName = path.resolve(__dirname, '..', year, phase, problem);
  }

  return {
    pdf: `${baseName}.pdf`,
    input: `${baseName}.in`,
    output: `${baseName}.out`,
    download: `${baseName}.zip`
  }
}

module.exports = { build, resolvePath };