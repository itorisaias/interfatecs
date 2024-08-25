const fs = require('node:fs');
const path = require('node:path');
const fsPromises = require('node:fs/promises');
const axios = require('axios');
const FormData = require('form-data');
const pdfParse = require('pdf-parse');

const cookie = 'biscoitobocabombonera=1724611576-2124e01da117a0705940ab8cf4e748422829e36963a3111c7655ac90abcdcd8d; _ga=GA1.1.663677135.1724356777; _ga_TBTX7EY2NW=GS1.1.1724359752.2.1.1724362422.0.0.0; PHPSESSID=599bjs3mv8gsigs2debkblo419';

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
    cookie,
    ...data.getHeaders()
  };

  const response = await axios.post(url, data, { headers, responseType: 'arraybuffer' });

  // const outputPath = path.resolve(download);

  // const writer = fs.writeFileSync(outputPath);

  // response.data.pipe(writer);

  // return new Promise((resolve, reject) => {
  //   writer.on('finish', resolve);
  //   writer.on('error', reject);
  // });
  fs.writeFileSync('problemlaz2tg_d.zip', response.data);
}

function resolvePath({ year, phase, problem }) {
  let baseName;

  if (phase !== null) {
    baseName = path.resolve(__dirname, '..', `${year}`, phase, problem);
  } else {
    baseName = path.resolve(__dirname, '..', `${year}`, problem);
  }

  return {
    pdf: `${baseName}.pdf`,
    input: `${baseName}.in`,
    output: `${baseName}.out`,
    download: `${baseName}.zip`
  }
}

async function getProblemList({ year, phase }) {
  const allFiles = [];

  if (phase !== null) {
    const files = await fsPromises.readdir(path.resolve(__dirname, '..', `${year}`, phase))
    allFiles.push(...files);
  } else {
    const files = await fsPromises.readdir(path.resolve(__dirname, '..', `${year}`))
    allFiles.push(...files);
  }

  return allFiles
    .filter(file => file.endsWith('A.pdf') && file.length <= 5)
    .map(file => file.replace('.pdf', ''))
    .map(problem => ({ ...resolvePath({ year, phase, problem }), letter: problem }));
}

async function extractBaseName(pdfPath) {
  const pdfBuffer = await fsPromises.readFile(pdfPath);
  const data = await pdfParse(pdfBuffer);
  const basename = data.text.match(/(Arquivo fonte:|Source file:)\s*(.*)\./);

  if (!basename) {
    return null;
  }

  return basename[2];
}

module.exports = { build, resolvePath, getProblemList, extractBaseName };