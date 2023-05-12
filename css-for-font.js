    <style>
        body {
           display: flex;
           justify-content: center;
           align-items: center;
        }

    </style>
    <script>
        function isMobileDevice() {
            return (typeof window.orientation !== "undefined") || (navigator.userAgent.indexOf('IEMobile') !== -1);
        }
        if(isMobileDevice()){
            function setBodyFontSize() {
              // 获取视口宽度
              var vw = Math.max(document.documentElement.clientWidth || 0, window.innerWidth || 0);
              
              // 将body元素的字体大小设置为视口宽度的5%
              document.body.style.fontSize = vw * 0.05 + 'px';
            }

            // 在页面加载完成后调用setBodyFontSize函数
            window.onload = function() {
              setBodyFontSize();
            };

            // 在窗口大小调整时重新调用setBodyFontSize函数
            window.onresize = function() {
              setBodyFontSize();
            };
        }
    </script>

