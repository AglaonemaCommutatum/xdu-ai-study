f = @(x) (x(1)^2 - x(2))^2 + (1 - x(1))^2;
x_initial = [-0.5; -0.5];  % 初始点
learning_rate = 0.1;  % 学习率
max_iterations = 1000;  % 最大迭代次数
tolerance = 1e-8;  % 收敛容差

% 迭代过程记录
x_history = zeros(2, max_iterations);
x_history(:, 1) = x_initial; 


x = x_initial;  
for iteration = 2:max_iterations
    grad = gradient(x);% 计算梯度
    % 更新参数
    x_new = x - learning_rate * grad;
    % 判断是否达到收敛
    if norm(gradient(x_new)) < tolerance
        x_history(:, iteration:end) = repmat(x_new, 1, max_iterations - iteration + 1);
     
        break;
    end

    % 更新参数并记录历史值
    x = x_new;
    x_history(:, iteration) = x;
    % 更新参数为新的值
end


fprintf('最优点：[%f, %f]\n', x(1), x(2));
fprintf('最优值：%f\n', f(x));

[X1, X2] = meshgrid(-1.5:0.01:2, -0.5:0.01:3);
Z = (X1.^2 - X2).^2 + (1 - X1).^2;

% 绘制
figure;
mesh(X1, X2, Z);
xlabel('x1');
ylabel('x2');
zlabel('f');
title('函数 f 的三维视图');

figure;
hold on;
[X1, X2] = meshgrid(-2:0.01:2, -1:0.01:3);
Z = (X1.^2 - X2).^2 + (1 - X1).^2;
contourf(X1, X2, Z, 100, 'LineColor', 'none');
plot(x_history(1, :), x_history(2, :), 'ro-');
quiver(x_history(1, 1:end-1), x_history(2, 1:end-1), x_history(1, 2:end) - x_history(1, 1:end-1), x_history(2, 2:end) - x_history(2, 1:end-1), 0.5, 'k');
hold off;
xlabel('x1');
ylabel('x2');
title('更新路径和等高线图');
colorbar;
