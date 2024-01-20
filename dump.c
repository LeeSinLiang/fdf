void draw_line(t_fdf *fdf, t_point s_point, t_point e_point, int color)
{ 
    int m_new = 2 * (e_point.y - s_point.y); 
    int slope_error_new = m_new - (e_point.x - s_point.x); 
	if (fdf->vars->save)
	{
		fdf->prev_map[fdf->vars->index].s_point = s_point;
		fdf->prev_map[fdf->vars->index].e_point = e_point;
		fdf->vars->index++;
	}
	printf("s_x: %d, s_y: %d, e_x: %d, e_y: %d\n", s_point.x, s_point.y, e_point.x, e_point.y);
    for (int x = s_point.x, y = s_point.y; x <= e_point.x; x++) { 
        // cout << "(" << x << "," << y << ")\n"; 
		printf("(%d, %d)\n", x, y);
  
        // Add slope to increment angle formed 
        slope_error_new += m_new; 
		fdf->buffer[(y * (fdf->lines / 4)) + x] = color;
        // Slope error reached limit, time to 
        // increment y and update slope error. 
        if (slope_error_new >= 0) { 
            y++; 
            slope_error_new -= 2 * (e_point.x - s_point.x); 
        } 
    } 
} 