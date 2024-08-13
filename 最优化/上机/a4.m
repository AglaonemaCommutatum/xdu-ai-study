f = @(x) (x(1)^2 - x(2))^2 + (1 - x(1))^2;
gradient = @(x) [4 * x(1) * (x(1)^2 - x(2)) + 2 * (x(1) - 1); -2 * (x(1)^2 - x(2))];
x_initial = [-0.5; -0.5];% 初始点
max_iterations = 1000;
tolerance = 1e-8;% 收敛容差


H = eye(2);
x_history = zeros(2, max_iterations);
x_history(:, 1) = x_initial;


x = x_initial;
grad = gradient(x);

for iteration = 2:max_iterations
    p = -H * grad;
    
    step_size = 1;
    while f(x + step_size * p) > f(x) + 0.5 * step_size * (grad' * p)
        step_size = step_size / 2;
    end
    
    x_new = x + step_size * p;
    grad_new = gradient(x_new);
    % 梯度更新1    
    s = x_new - x;
    y = grad_new - grad;
    rho = 1 / (y' * s);
    %更新H
    H = (eye(2) - rho * s * y') * H * (eye(2) - rho * y * s') + rho * s * s';
    % 判断是否收敛
    if norm(gradient(x_new)) < tolerance
        x_history(:, iteration:end) = repmat(x_new, 1, max_iterations - iteration + 1);
        break;
    end
    
    x = x_new;
    grad = grad_new;
    x_history(:, iteration) = x;
% 更新参数为新的值，并将新的参数存入记录中
end

fprintf('Optimal point: [%f, %f]\n', x(1), x(2));
fprintf('Optimal value: %f\n', f(x));
[X1, X2] = meshgrid(-1.5:0.01:2, -0.5:0.01:3);
Z = (X1.^2 - X2).^2 + (1 - X1).^2;


figure;
mesh(X1, X2, Z);
xlabel('x1');
ylabel('x2');
zlabel('f');
title('3D view of f');

figure;
hold on;
colormap jet; 
contourf(X1, X2, Z, 80, 'LineColor', 'none');
plot(x_history(1, :), x_history(2, :), 'r.-');
quiver(x_history(1, 1:end-1), x_history(2, 1:end-1), x_history(1, 2:end) - x_history(1, 1:end-1), x_history(2, 2:end) - x_history(2, 1:end-1), 0.0001, 'k');
hold off;
xlabel('x1');
ylabel('x2');
title('Convergence path and contour plot');
colorbar;
