% 读取原始音频文件
[x, fs] = audioread('noisyaudio.m4a');

% 设定自适应滤波器的参数
M = 10; % 滤波器长度
mu = 0.01; % 步长系数

% 初始化自适应滤波器
w = zeros(M, 1);

% 利用LMS算法进行音频降噪
y = zeros(size(x));
for n = M:length(x)
    x_n = x(n:-1:n-M+1);
    y(n) = w' * x_n;
    e = x(n) - y(n);
    w = w + mu * e * x_n;
end

% 计算信噪比
snr_after = snr(x, x - y);
snr_before = snr(x, y);

% 输出信噪比
fprintf('降噪前信噪比：%.2f dB\n', snr_before);
fprintf('降噪后信噪比：%.2f dB\n', snr_after);

% 播放降噪后的音频
sound(y, fs);

% 保存降噪后的音频
audiowrite('denoised_audio.wav', y, fs);
