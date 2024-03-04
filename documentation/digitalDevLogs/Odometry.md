# Odometry
Around the time of competition 2 we considered a new autonomous method. We considered using positioning to make a non-recordable but highly accurate and easy to record autonomous. We would track the position of the robot using integrals of delta wheel travel, old position, and old orientation. We planned to implement a third perpendicular for stability. However, we ended up scrapped the idea because it was not as versatile, and we didn't have a field to test runs on (so we would need to program very fast at competition). We did consider making a delta position and orientation recording system (basically merge odometry and recording), however we decided that would have drawbacks and wouldn't keep the accuracy enough to warrant it.

## Math Outline
$▲LΘ = $ change in left wheel angle in degrees\
$▲RΘ = $ change in right wheel angle in degrees\
$r = $ radius\
$▲L = \frac{▲LΘ * r}{36}$\
$▲R = \frac{▲RΘ * r}{36}$\
$T = $ distance between left and right wheels in inches\
$t = $ current time since start\
$▲Θ(t) = \frac{▲L - ▲R}{T}$\
$Θ(t) = \int_{0}^{t} ▲Θ(t) \; dt$\
$▲L(t) = \frac{▲L + ▲R}{2}$\
$P(t) = \int_{0}^{t} ▲D * (cos(Θ(t)) * î + sin(Θ(t)) * ĵ) \; dt$