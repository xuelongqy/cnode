'use strict';

const common = require('../common');
if (!common.hasCrypto)
  common.skip('missing crypto');
const http2 = require('http2');
const assert = require('assert');

let pathToTest = process.cwd();
if (common.isAndroid) {
  // Use the script's path instead of a path without permissions on Android.
  pathToTest = __dirname;
}

const server = http2.createServer();
server.on('stream', (stream) => {
  stream.respondWithFile(pathToTest, {
    'content-type': 'text/plain'
  }, {
    onError(err) {
      common.expectsError({
        code: 'ERR_HTTP2_SEND_FILE',
        type: Error,
        message: 'Directories cannot be sent'
      })(err);

      stream.respond({ ':status': 404 });
      stream.end();
    },
    statCheck: common.mustNotCall()
  });
});
server.listen(0, () => {

  const client = http2.connect(`http://localhost:${server.address().port}`);
  const req = client.request();

  req.on('response', common.mustCall((headers) => {
    assert.strictEqual(headers[':status'], 404);
  }));
  req.on('data', common.mustNotCall());
  req.on('end', common.mustCall(() => {
    client.close();
    server.close();
  }));
  req.end();
});
