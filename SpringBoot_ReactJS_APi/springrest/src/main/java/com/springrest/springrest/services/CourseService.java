package com.springrest.springrest.services;

import java.util.List;

import com.springrest.springrest.entities.Course;

public interface CourseService {
	
	//Creating Interface for loose coupling
	/*So in future want to change something only change in interface not in controleer */
	public List<Course> getCourses();

	public Course getCourse(long courseId);
	
	public Course deleteCourse(long courseId);
	
	public Course addCourse(Course course);

	public Course updateCourse(Course course);
}
