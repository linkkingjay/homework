$(document).ready(function () {
  var N,
      // 总线
      Bus = "",
      // 冲突窗口（争用期）
      collisionWindow,
      // 人工干扰的时间
      jammingSignal,
      // 允许的最多冲突次数
      allowCollisionCount,
      // 需要发送的数据次数
      dataCount;

  var Host = function (id) {
    this.id = 'host' + id;
    this.sendCounter = 0;
    this.collisionCounter = 0;
    var progressBar = $('<div></div>')
                         .addClass('progress')
                         .append(
                           $('<div></div>')
                             .addClass('progress-bar progress-bar-striped')
                             .attr({ 
                               'role': 'progressbar',
                               'aria-valuemin': '0', 
                               'aria-valuemax': '100',
                               'style': 'width: 0%',
                               'id': this.id
                             })
                             .html(this.id)
                         );
    $('#main').append(progressBar);
    this.progressBar = $('#' + this.id);

    this.sendData();
  };

  Host.prototype.sendData = function () {
    this.progressBar.addClass('active');

    // 当前没有其他主机在发送数据
    if (Bus === '') {
      Bus = this.id;
      // 争用期过后如果 Bus 还是当前 id 说明发送成功了
      setTimeout($.proxy(function () {
        // 发送成功一次数据
        if (Bus === this.id) {
          Bus = '';
          this.sendCounter++;
          this.progressBar.width(this.progressBar.parent().width() *
                                 this.sendCounter / dataCount);
          this.progressBar.removeClass('active');

          console.log(this.id + ' send success. Time: ' + this.sendCounter);

          // 如果还没发送完，就要继续发送
          if (this.sendCounter != dataCount) {
            this.collisionCounter = 0;
            this.sendData();
          // 全部发送完了
          } else {
            console.log(this.id + ' finished!');
          }
        // 冲突了
        } else {
          this.collision();
        }
      }, this), collisionWindow);
    // 当前有其他主机在发送数据
    } else {
      // 不是人工干扰的情况
      if (Bus != 'collision') {
        // 设置人工干扰
        Bus = 'collision';
        setTimeout(function () {
          Bus = '';
        }, jammingSignal);
      }
      this.progressBar.removeClass('active');

      this.collision();
    }
  };

  Host.prototype.collision = function () {
    if (++this.collisionCounter >= allowCollisionCount) {
      this.progressBar.width("100%");
      this.progressBar.addClass('progress-bar-danger');
      this.progressBar.removeClass('active');
      console.log(this.id + ' send failure.');
    } else {
      var k = this.collisionCounter < dataCount ?
              this.collisionCounter : dataCount,
          time = parseInt(Math.random() * Math.pow(2, k)) * collisionWindow;
      setTimeout($.proxy(function () {
        this.sendData();
      }, this), time);

      console.log(this.id + ' send collision ' + this.collisionCounter +
                  ' times, delay ' + time + 'ms');
    }
  };

  $('#start').click(function () {
    var i;
    console.clear();
    $('#main').empty();

    dataCount = $('#dataCount').val();
    allowCollisionCount = $('#allowCollisionCount').val();
    collisionWindow = $('#collisionWindow').val();
    jammingSignal = $('#jammingSignal').val();
    N = $('#N').val();

    for (i = 1; i <= N; i++) {
      new Host(i);
    }
    return false;
  });
});
