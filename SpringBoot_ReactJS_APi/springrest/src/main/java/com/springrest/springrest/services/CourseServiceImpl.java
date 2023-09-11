package com.springrest.springrest.services;
import java.util.ArrayList;
import java.util.List;

import org.apache.el.stream.Optional;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.springrest.springrest.dao.CourseDao;
import com.springrest.springrest.entities.Course;

@Service
public class CourseServiceImpl implements CourseService {

	@Autowired
	private CourseDao coursedao;
	
	
	//Here Temporary Store Data
	//List<Course> list;
	public CourseServiceImpl() {
		//list = new ArrayList<>();
		//list.add(new Course(1,"Java Core Course","Amazing Java Core Course"));
		//list.add(new Course(2,"Java Spring Course","Amazing Java Spring Boot Course"));
	}
	
	@Override
	public List<Course> getCourses() {
		//return list;
		return coursedao.findAll();
	}

	@Override
	public Course getCourse(long courseId) {
		/*Course c = null;
		for(Course course:list) {
			if(course.getId() == courseId) {
				c = course;
				break;
			}
		}
		return c;*/
		//return coursedao.getOne(courseId);  //getById()  & getOne() depreciate
		Course course = coursedao.findById(courseId).orElse(null);
	    return course;
	}

	@Override
	public Course deleteCourse(long courseId) {
		/*Course c = null;
		for(Course course:list) {
			if(course.getId() == courseId) {
				list.remove(c);
				//c = course;
				break;
			}
		}
		return c;*/
		/*Course entity = coursedao.getOne(courseId);
		coursedao.delete(entity);	 - because it's depriciate*/
//		Course course = coursedao.findById(courseId).orElse(null);
//
//	    if (course != null) {
//	        coursedao.delete(course);
//	    }
		Course course = coursedao.findById(courseId).orElse(null);
		coursedao.deleteById(courseId);
//	    if (course != null) {
	    coursedao.delete(course);
//	    } else {
//	        // Handle the case where the course with courseId doesn't exist
//	        // You can log a message or return an appropriate response
//	    }
	    return course;
	}

	
	@Override
	public Course addCourse(Course course) {
		/*list.add(course);
		return course;*/
		
		return coursedao.save(course);
	}

	@Override
	public Course updateCourse(Course course) {
		/*for (Course c : list) {
	        if (c.getId() == course.getId()) {
	            // Update the properties of the existing course with the new values
	            c.setTitle(course.getTitle());
	            c.setDescription(course.getDescription());
	            return c; // Return the updated course
	        }
	    }
	    return null; // Return null if the course with the given id is not found*/
		return coursedao.save(course);
	}
}
