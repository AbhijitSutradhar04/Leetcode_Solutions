class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int,
                     x1: int, y1: int, x2: int, y2: int) -> bool:

        # Find closest point of rectangle from circle center
        closestX = max(x1, min(xCenter, x2))
        closestY = max(y1, min(yCenter, y2))

        # Distance between closest point and circle center
        distance = (closestX - xCenter) ** 2 + (closestY - yCenter) ** 2

        # If distance <= radius squared, overlap exists
        return distance <= radius * radius